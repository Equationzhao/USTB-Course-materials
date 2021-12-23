#include "Account.h"
#include "error.hpp"
#include <iostream>
#include <set>
#include "Date.h"
#include "AccountException.h"
#include "Command.h"

std::multiset<AccountRecord> Account::recordSet{};
std::atomic<double> Account::total = 0;
sf::default_contention_free_shared_mutex Account::recordSetMutex;

Account::Account(const Date& date, const std::string& id, const double& rate, const std::string& password,
                 AccountMode mode)
	: password(password), id(id), initialDate(date), balance(0), rate(rate)
{
	accumulator = std::make_shared<Accumulator>(mode);
	accumulator->reset(date, 0);
}


/*
 * 保存数据，输出msg，amount区分正负
 * recordSet插入失败时抛出异常,恢复record前的状态
 */
auto Account::record(const Date& date, const double& amount, const char* msg) -> void
{
	const auto newBalance = getBalance() + amount;
	setBalance(newBalance);
	total = total + amount;

	try
	{
		recordSetMutex.lock();
		const AccountRecord ar(date, id, amount, getBalance(), msg);
		recordSet.insert(ar);
		recordSetMutex.unlock();
		insertIntoMyRecord(ar);
		Saver(id + ".txt").save(ar.to_string() + "\n");
	}
	catch (const std::exception&) //异常安全?
	{
		recordSetMutex.unlock();
		setBalance(getBalance() - amount);
		total = total - amount;
		throw AccountException(std::string("failed,recordSet insert error").append("    ").append(this->info()));
	}
	std::cout << date << "    #" << this->id << "    " << amount << "    " << getBalance() << "     " << msg << '\n';
}

//nonsense :-(
auto Account::error(const std::string& msg) -> void
{
	std::cerr << msg;
}

auto Account::getPassword() const -> std::string
{
	return password;
}

//设置余额
auto Account::setBalance(const double& balance) -> void
{
	//std::unique_lock<std::mutex> guard(BalanceMutex);
	this->balance = balance;
	//guard.unlock();
}

//設置密碼
auto Account::setPassword(const std::string& newPass) -> void
{
	if (password == newPass)
	{
		throw std::runtime_error("Do not use the same Password!");
	}

	password = newPass;
}

//检查密码是否匹配
auto Account::checkPassword(const std::string& password) const -> bool
{
	return this->password == password;
}

auto Account::getId() const noexcept -> std::string
{
	return id;
}

auto Account::getBalance() const noexcept -> double
{
	return balance;
}

auto Account::getRate() const noexcept -> double
{
	return rate;
}

auto Account::notice() -> std::string
{
	const auto sysDate = DATE::getSystemDate();
	const auto d1 = getDate(sysDate.getYear(), sysDate.getMonth(), 1);

	const auto notice = this->query_this_by_order(d1, sysDate, AccountRecord::ascendAmountComparator());
	std::string income, outcome;
	for (const auto& ar : notice)
	{
		if (ar.getAmount() > 0)
		{
			income += ar.to_string() + "\n";
		}
		else
		{
			outcome += ar.to_string() + "\n";
		}
	}

	return income + "\n\n" + outcome;
}

auto Account::getTotal() noexcept -> double
{
	return total;
}

auto Account::addTotal(const double& value) -> void
{
	total = total + value;
}


/*
*	返回 string 查询到的信息
*	
*/
auto Account::query(const Date& date1, const Date& date2) -> std::string
{
	bool found = false;
	std::string result;
	recordSetMutex.lock_shared();
	for (const auto& i : recordSet)
	{
		if ((i.getDate() >= date1) && (i.getDate() <= date2))
		{
			found = true;
			result += i.to_string().append("\n");
		}
	}
	recordSetMutex.unlock_shared();
	if (!found)
	{
		result = "Not Found";
	}
	return result;
}

auto Account::insertIntoTotalRecord(const AccountRecord& ar) -> void
{
	recordSetMutex.lock();
	try
	{
		recordSet.insert(ar);
	}
	catch (...)
	{
		recordSetMutex.unlock();
		throw;
	}

	recordSetMutex.unlock();
}

auto Account::insertIntoTotalRecord(const Date& date, const std::string& accountID, const double& amount,
                                    const double& balance, const std::string& desc) -> void
{
	recordSetMutex.lock();
	try
	{
		recordSet.emplace(date, accountID, amount, balance, desc);
	}
	catch (...)
	{
		recordSetMutex.unlock();
		throw;
	}
	recordSetMutex.unlock();
}

//插入myRecord ,有锁
auto Account::insertIntoMyRecord(const AccountRecord& ar) -> void
{
	myRecordSetMutex.lock();
	try
	{
		myRecordSet.insert(ar);
	}
	catch (...)
	{
		myRecordSetMutex.unlock();
		throw;
	}

	myRecordSetMutex.unlock();
}

//插入myRecord ,有锁
auto Account::insertIntoMyRecord(const Date& date, const std::string& accountID, const double& amount,
                                 const double& balance, const std::string& desc) -> void
{
	myRecordSetMutex.lock();
	try
	{
		myRecordSet.emplace(date, accountID, amount, balance, desc);
	}
	catch (...)
	{
		myRecordSetMutex.unlock();
		throw;
	}

	myRecordSetMutex.unlock();
}

//有锁
auto Account::getMyAccountRecord() -> std::vector<AccountRecord>
{
	std::vector<AccountRecord> myAccountRecord;
	myAccountRecord.reserve(20);
	try
	{
		myRecordSetMutex.lock_shared();
		for (const auto& i : myRecordSet)
		{
			myAccountRecord.emplace_back(i);
		}
		myRecordSetMutex.unlock_shared();
	}
	catch (const std::exception&)
	{
		myRecordSetMutex.unlock_shared();
		throw;
	}

	return myAccountRecord;
}

//有锁
auto Account::getMyAccountRecord(std::vector<AccountRecord>& myAccountRecord) -> void
{
	myAccountRecord.reserve(20);

	try
	{
		myRecordSetMutex.lock_shared();
		for (const auto& i : myRecordSet)
		{
			myAccountRecord.emplace_back(i);
		}
		myRecordSetMutex.unlock_shared();
	}
	catch (const std::exception&)
	{
		myRecordSetMutex.unlock_shared();
		throw;
	}
}

auto Account::query_this(const Date& d1, const Date& d2) -> std::string
{
	std::string result;
	bool found(false);
	const auto arVector = getMyAccountRecord();
	for (const auto& ar : arVector)
	{
		if ((ar.getDate() >= d1) && (ar.getDate() <= d2))
		{
			found = true;
			result += ar.to_string().append("\n");
		}
	}
	if (!found)
	{
		result = "Not Found\n";
	}
	return result;
}

auto Account::query_this_by_order(const Date& d1, const Date& d2,
                                  const std::function<bool(const AccountRecord&,
                                                           const AccountRecord&)>& order) -> std::vector<AccountRecord>
{
	auto&& arVector = getMyAccountRecord();

	std::vector<AccountRecord> res;
	res.reserve(20);
	for (const auto& ar : arVector)
	{
		if ((ar.getDate() >= d1) && (ar.getDate() <= d2))
		{
			res.emplace_back(ar);
		}
	}

	std::sort(res.begin(), res.begin() + res.size(), order);
	return res;
}
