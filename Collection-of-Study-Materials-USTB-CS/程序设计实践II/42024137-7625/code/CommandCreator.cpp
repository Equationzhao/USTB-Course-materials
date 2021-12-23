#include "CommandCreator.h"
#include <algorithm>
#include <functional>
#include "Command.h"
#include "DataAccess.hpp"
#include "StringSplit.hpp"
#include "Util.hpp"

namespace GETCMD
{
	inline auto createAccount(const std::vector<std::string>& parameters) -> Command*
	{
		if (parameters.empty())
		{
			throw std::runtime_error("Bad input");
		}

		//是否需要加以限制,比如rate>0 credit>0 等等
		//根据第一个字符判断类型（s or c）
		//s S123456 0.015 123456x
		//c C5392394 10000 0.0005 50 123456x


		const auto size = parameters.size();
		if (parameters.at(0) == "s" && size == 4 && UTIL::isNum(parameters.at(2)))
		{
			return new CreateSavingsAccount(parameters);
		}
		if (parameters.at(0) == "c" && size == 6)
		{
			if (UTIL::isNum(parameters.at(2)) && UTIL::isNum(parameters.at(3)) && UTIL::isNum(parameters.at(4)))
			{
				return new CreateCreditAccount(parameters);
			}
		}


		throw std::runtime_error("Bad input");
	}

	//检查了 parameter 的是否合乎标准,包括输入是否为数字,账户是否存在等,错误输入抛出异常
	//正确则返回 Deposit 命令对象
	//parameters eg: S123456 5000 (msg...)(optional)
	inline auto deposit(std::vector<std::string> parameters) -> Command*
	{
		const auto size = parameters.size();
		if ((size >= 2) && UTIL::isNum(parameters.at(1)))
			//检查个数&类型 todo use isPositiveNum instead of isNum 
		{
			// 将最后的msg变成一个string传入vector
			std::string msg;
			std::for_each(parameters.begin() + 2, parameters.end(),
			              [&msg](const std::string& part) { msg.append(part).append(" "); });

			std::vector<std::string> newParas;
			newParas.reserve(3);
			newParas.insert(newParas.end(), parameters.begin(), parameters.begin() + 2);
			newParas.emplace_back(msg);

			return new Deposit(newParas);
		}
		throw std::runtime_error("Bad input");
	}

	//parameters eg: S123456 5000 (msg...)(optional)
	inline auto withdraw(std::vector<std::string> parameters) -> Command*
	{
		// parameters >= 3
		const auto size = parameters.size();
		if (size >= 2 && UTIL::isNum(parameters.at(1))) //检查个数&类型 todo use isPositiveNum instead of isNum 
		{
			// 将最后的msg变成一个string传入vector
			std::string msg;
			std::for_each(parameters.begin() + 2, parameters.end(),
			              [&msg](const std::string& part) { msg.append(part).append(" "); });

			std::vector<std::string> newParas;
			newParas.reserve(3);
			newParas.insert(newParas.end(), parameters.begin(), parameters.begin() + 2);
			newParas.emplace_back(msg);
			return new Withdraw(newParas);
		}
		throw std::runtime_error("Bad input");
	}

	inline auto show(const std::vector<std::string>& parameters) -> Command*
	{
		if (parameters.empty())
		{
			return new Show();
		}
		if (parameters.size() == 1)
		{
			return new Show(parameters.at(0));
		}
		throw std::runtime_error("Bad input");
	}

	//检查天数是否为正整数,不是则抛出异常
	//
	inline auto changeDay(const std::vector<std::string>& parameters) -> Command*
	{
		int day = 0;
		parameters.size() == 1 ? day = UTIL::toInteger(parameters.at(0)) : throw std::runtime_error("Bad input");
		if (day < 0)
		{
			throw std::runtime_error("invalid number");
		}

		if (day < DATE::getSystemDate().getDay())
		{
			throw std::runtime_error("You cannot specify a previous day");
		}
		if (day > DATE::getSystemDate().getMaxDay())
		{
			throw std::runtime_error("invalid day");
		}
		return new ChangeDay(static_cast<short>(day));
	}

	inline auto nextMonth(const std::vector<std::string>& parameters) -> Command*
	{
		if (!parameters.empty())
		{
			throw std::runtime_error("Bad input");
		}
		return new NextMonth();
	}

	inline auto query(const std::vector<std::string>& parameters) -> Command*
	{
		const auto size = parameters.size();
		std::string id, password;
		Date date1, date2;
		if (size == 2) //date1 date2
		{
			date1 = getDate(parameters.at(0), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(1), CommandCreator::getDateSplit());
		}
		else if (size == 4) //id password date1 date2
		{
			id = parameters.at(0);
			password = parameters.at(1);
			date1 = getDate(parameters.at(2), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(3), CommandCreator::getDateSplit());
		}
		else
		{
			throw std::runtime_error("Bad input");
		}


		if (date1 > date2)
		{
			throw std::runtime_error("invalid date range");
		}

		return new Query(date1, date2, id, password);
	}


	inline auto query_by_order_time(const std::vector<std::string>& parameters) -> Command*
	{
		const auto size = parameters.size();
		std::string id, password;
		Date date1, date2;
		if (size == 2) //date1 date2
		{
			date1 = getDate(parameters.at(0), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(1), CommandCreator::getDateSplit());
		}
		else if (size == 4) //id password date1 date2
		{
			id = parameters.at(0);
			password = parameters.at(1);
			date1 = getDate(parameters.at(2), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(3), CommandCreator::getDateSplit());
		}
		else
		{
			throw std::runtime_error("Bad input");
		}


		if (date1 > date2)
		{
			throw std::runtime_error("invalid date range");
		}

		return new QueryBy(date1, date2, AccountRecord::ascendDateComparator(), id, password);
	}


	inline auto query_by_order_amount(const std::vector<std::string>& parameters)
	{
		const auto size = parameters.size();
		std::string id, password;
		Date date1, date2;
		if (size == 2) //date1 date2
		{
			date1 = getDate(parameters.at(0), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(1), CommandCreator::getDateSplit());
		}
		else if (size == 4) //id password date1 date2
		{
			id = parameters.at(0);
			password = parameters.at(1);
			date1 = getDate(parameters.at(2), CommandCreator::getDateSplit());
			date2 = getDate(parameters.at(3), CommandCreator::getDateSplit());
		}
		else
		{
			throw std::runtime_error("Bad input");
		}


		if (date1 > date2)
		{
			throw std::runtime_error("invalid date range");
		}

		return new QueryBy(date1, date2, AccountRecord::ascendAmountComparator(), id, password);
	}


	inline auto exit(const std::vector<std::string>& parameters) -> Command*
	{
		if (!parameters.empty())
		{
			throw std::runtime_error("Bad input");
		}
		return new Exit();
	}
}

auto getFunctionTable() -> std::unordered_map<char, std::function<Command*(const std::vector<std::string>&)>>&
{
	static std::unordered_map<char, std::function<Command*(const std::vector<std::string>&)>> functionTable =
	{
		{'a', GETCMD::createAccount},
		{'c', GETCMD::changeDay},
		{'d', GETCMD::deposit},
		{'w', GETCMD::withdraw},
		{'s', GETCMD::show},
		{'n', GETCMD::nextMonth},
		{'q', GETCMD::query},
		{'t', GETCMD::query_by_order_time},
		{'v', GETCMD::query_by_order_amount},
		{'e', GETCMD::exit}
	};

	return functionTable;
}


CommandCreator::CommandCreator() noexcept : firstCmd('\0')
{
}

/*
*
*	取第一个字符为主命令,若第一个不是单个字符,抛出异常
*	**其余**字符存入vector 返回
*/
auto CommandCreator::parse() -> std::vector<std::string>
{
	std::vector<std::string> temp = totalCmd.split_into_vector();
	if (temp.size() == 0)
	{
		throw std::runtime_error("");
	}
	if (temp.at(0).size() == 1)
	{
		firstCmd = temp.at(0)[0];
	}
	else
	{
		throw std::runtime_error("Bad input");
	}

	temp.erase(temp.begin(), temp.begin() + 1);
	return temp;
}

inline auto CommandCreator::getDateSplit() -> std::string
{
	return split;
}

//更改默认日期分隔符
inline auto CommandCreator::setDateSplit(const std::string& split) -> void
{
	CommandCreator::split = split;
}

//**不要传入空的string!** throw exception when cmd is empty
auto CommandCreator::getCommand(const std::string& cmd) -> Command*
{
	if (cmd.empty())
	{
		throw std::runtime_error("cmd empty");
	}
	totalCmd = static_cast<BKSYS::string>(cmd);
	const auto para = parse();

	return getFunctionTable()[firstCmd](para);
}

UserCommandCreator::UserCommandCreator(const std::string& id, const std::string& password): id(id), password(password)
{
}

UserCommandCreator::~UserCommandCreator()
{
	saveAccounts(id);
}


//cmd like 
auto UserCommandCreator::send(const std::string& cmd) -> bool
{
	if (cmd.empty())
	{
		throw std::runtime_error("cmd empty");
	}
	totalCmd = static_cast<BKSYS::string>(cmd);
	auto para = parse();

	// todo add password check during operation 
	switch (firstCmd)
	{
	case 'c':
	case 'n':
		{
			break;
		}
	case 'd':
	case 'w':
		{
			if (para.size() >= 1)
			{
				para.emplace(para.begin(), id);
			}
			else
			{
				throw std::runtime_error("Bad input");
			}
			break;
		}
	case 't':
		{
		}
	case 'v':
		{
		}
	case 'q':
		{
			if (para.size() != 2)
			{
				throw std::runtime_error("Bad input");
			}
			para.emplace(para.begin(), id);
			para.emplace(para.begin() + 1, password);
			break;
		}

	case 'e':
		{
			return false;
		}

	case 's':
		{
			if (para.empty())
			{
				para.emplace(para.begin(), id);
			}
			else
			{
				para.emplace(para.begin() + 1, id);
			}
			break;
		}
	default:
		{
			throw std::runtime_error("Bad input");
		}
	}


	const std::unique_ptr<Command> exe(getFunctionTable()[firstCmd](para));
	exe->execute();
	return true;
}

auto UserCommandCreator::notice() const -> std::string
{
	return GetAccounts().getOfId(id)->notice();
}
