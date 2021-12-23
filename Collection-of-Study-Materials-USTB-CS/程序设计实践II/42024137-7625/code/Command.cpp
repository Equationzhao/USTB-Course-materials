#include <mutex>
#include <vector>
#include "Account.h"
#include "Command.h"
#include "CreditAccount.h"
#include "Date.h"
#include "StringSplit.hpp"
#include "DataAccess.hpp"
#include "error.hpp"
#include "AccountException.h"
#include "SavingsAccount.h"

std::vector<Account*> GetAccounts::accounts;
sf::default_contention_free_shared_mutex GetAccounts::a_mutex_;

GetAccounts::GetAccounts(): time(0)
{
	++time;
	a_mutex_.lock();
}

GetAccounts::~GetAccounts()
{
	if (!--time)
	{
		a_mutex_.unlock();
	}
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// usage:
//		GetAccounts getAccounts;
//		getAccounts.getOfId(xxx)->callFunctions;
//					or
//		auto ptr = getAccounts.getOfId(xxx);
//		getAccounts.unlock();//when you want to release lock,or just let it released automatically during destruction
//
//		DO NOT call like this:
//							auto something = GetAccounts().getOfId(xxx);
//								the lock will be released when the function getOfId is over(aka when the xvalue destructs).
auto GetAccounts::getOfId(const std::string& id) -> Account*
{
	for (const auto& a : accounts)
	{
		if (a->getId() == id)
		{
			return a;
		}
	}
	throw std::runtime_error("Account not found");
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// usage:
//		GetAccounts getAccounts;
//		getAccounts.get().emplace_back(xxx);
//					or
//		auto ptr = getAccounts.get();
//		getAccounts.unlock();//when you want to release lock,or just let it released automatically during destruction
//
//		DO NOT call like this:
//							auto something = GetAccounts().get();
auto GetAccounts::get() -> std::vector<Account*>&
{
	return accounts;
}


auto GetAccounts::unlock() -> void
{
	if (!--time)
	{
		a_mutex_.unlock();
	}
}


/*
* todo do not use initializer!!
* fix msg para
*/

//s S123456 0.015 123456
auto CreateSavingsAccount::execute() const -> void
{
	GetAccounts().get().emplace_back(new SavingsAccount(DATE::getSystemDate(), initializer.at(1),
	                                                    std::stod(initializer.at(2)), initializer.at(3)));

	//文件写入命令
	Saver("commands.txt").save(std::string("a ").append(initializerToString()));
	Saver("accounts.txt").save(initializer.at(1) + "\n");
}

//c C5392394 10000 0.0005 50 123456
auto CreateCreditAccount::execute() const -> void
{
	GetAccounts().get().emplace_back(new CreditAccount(DATE::getSystemDate(), initializer.at(1),
	                                                   std::stod(initializer.at(2)), std::stod(initializer.at(3)),
	                                                   std::stod(initializer.at(4)), initializer.at(5)));

	//文件写入命令
	Saver("commands.txt").save(std::string("a ").append(initializerToString()));
	Saver("accounts.txt").save(initializer.at(1) + "\n");
}

Deposit::Deposit(const std::vector<std::string>& initializer): Command(initializer)
{
}

Deposit::Deposit(std::vector<std::string>&& initializer): Command(std::move(initializer))
{
}

auto Deposit::execute() const -> void
{
	GetAccounts acts;
	const auto act = acts.getOfId(initializer.at(0));
	act->deposit(DATE::getSystemDate(), std::stod(initializer.at(1)), initializer.at(2).c_str());

	//文件写入命令
	Saver("commands.txt").save(std::string("d ").append(initializerToString()));
}

Withdraw::Withdraw(const std::vector<std::string>& initializer): Command(initializer)
{
}

Withdraw::Withdraw(std::vector<std::string>&& initializer): Command(std::move(initializer))
{
}

auto Withdraw::execute() const -> void
{
	try
	{
		GetAccounts().getOfId(initializer.at(0))->withdraw(DATE::getSystemDate(), std::stod(initializer.at(1)),
		                                                   initializer.at(2).c_str());
	}
	catch (const std::exception& e)
	{
		throw AccountException(e.what());
	}

	//文件写入命令
	Saver("commands.txt").save(std::string("w ").append(initializerToString()));
}

Show::Show(const std::string& id): id(id)
{
}

auto Show::execute() const -> void
{
	GetAccounts getAccounts;
	if (id.empty())
	{
		for (auto account = getAccounts.get().begin(); account != getAccounts.get().end(); ++account)
		{
			std::cout << "[" << account - getAccounts.get().begin() << "]  ";
			(*account)->show();
			std::cout << '\n';
		}
	}
	else
	{
		getAccounts.getOfId(id)->show();
		std::cout << '\n';
	}
	//文件写入命令
	Saver("commands.txt").save("s " + id);
}

ChangeDay::ChangeDay(const short day): day(day)
{
}

/*
*	may throw "You cannot specify a previous day" or "Invalid day"
*/
auto ChangeDay::execute() const -> void
{
	//std::unique_lock<std::mutex> dateGuard(g_SystemDateMutex);


	DATE::setSystemDate(getDate(DATE::getSystemDate().getYear(),
	                            DATE::getSystemDate().getMonth(),
	                            day));

	Saver("commands.txt").save(std::string("c ").append(std::to_string(day)));
	//dateGuard.unlock();
}

auto NextMonth::execute() const -> void
{
	//std::unique_lock<std::mutex> dateGuard(g_SystemDateMutex);
	if (DATE::getSystemDate().getMonth() == 12)
	{
		DATE::setSystemDate(Date(DATE::getSystemDate().getYear() + 1, 1, 1));
	}
	else
	{
		DATE::setSystemDate(Date(DATE::getSystemDate().getYear(),
		                         DATE::getSystemDate().getMonth() + 1,
		                         1));
	}
	//std::unique_lock<std::mutex> accountsVectorGuard(g_accountsVectorMutex);
	bool error(false);
	AccountException accountException("settle error");
	GetAccounts getAccounts;
	for (const auto& i : getAccounts.get())
	{
		if (i)
		{
			try
			{
				i->settle(DATE::getSystemDate());
			}
			catch (const std::exception& e)
			{
				error = true;
				accountException.add(i->info().append("    ").append(e.what()));
			}
		}
	}
	//getAccounts.Return();
	Saver("commands.txt").save("n");

	//accountsVectorGuard.unlock();
	//dateGuard.unlock();

	if (error)
	{
		throw AccountException(std::move(accountException));
	}
}

Query::Query(const Date& d1, const Date& d2, const std::string& id,
             const std::string& password): id(id), password(password), d1(d1), d2(d2)
{
}

auto Query::execute() const -> void
{
	if (id.empty())
	{
		std::cout << Account::query(d1, d2);
	}
	else
	{
		GetAccounts getAccounts;
		const auto act = getAccounts.getOfId(id);
		if (act->checkPassword(password))
		{
			std::cout << act->query_this(d1, d2);
		}
		else
		{
			throw std::runtime_error("Authentication failure");
		}
	}

	Saver("commands.txt").save(std::string("q " + id + " ").append(d1.to_string()).append(" ").append(d2.to_string()));
}

//save information to file and delete ptr in GetAccounts 
auto Exit::execute() const -> void
{
	saveAccounts();
	GetAccounts getAccounts;

	for (const auto& account : getAccounts.get())
	{
		delete account;
	}
	exit(0); //不写入 commands.txt 文件
}

auto QueryBy::execute() const -> void
{
	GetAccounts getAccounts;
	const auto acts = getAccounts.getOfId(id);;
	if (acts->checkPassword(password))
	{
		auto&& i = acts->query_this_by_order(d1, d2, order);

		for (const auto& j : i)
		{
			std::cout << j.to_string() << '\n';
		}
	}
	else
	{
		throw std::runtime_error("incorrect password");
	}
}

//这里设计的不好,直接把第一个参数传进来更优雅
auto Command::initializerToString() const -> std::string
{
	std::string res;
	for (const auto& i : initializer)
	{
		res += i;
		res += " ";
	}
	return res;
}

// todo 增加一个参数为 ostream||istream
// todo 将新的record单独存储? 直接写入文件尾部
