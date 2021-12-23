#include "CreditAccount.h"
#include "error.hpp"
#include <iostream>
#include <cmath>


CreditAccount::CreditAccount(const Date& date, const std::string& id, const double& credit, const double& rate,
                             const double& fee, const std::string& password):
	Account(date, id, rate, password, ACCOUNTMODE::creditAccount), fee(fee), credit(credit)
{
}

/*
 *	存款 amount 为正
 */
auto CreditAccount::deposit(const Date& date, const double& amount, const char* msg) -> void
{
	record(date, amount, msg);
	this->accumulator->calculate(date, rate, amount);
}

/*
 * 结算利息，判断是否需要交纳年费 ，余额不足抛出异常 
 */
auto CreditAccount::settle(const Date& date) -> void
{
	if (date.getDay() != 1) //不是每月一号，不结算
	{
		return;
	}

	this->accumulator->calculate(date, rate, 0);
	if (fabs(accumulator->getSum()) > 1e-6)
	{
		record(date, accumulator->getInterest(), "interest");
	}

	if (date.getMonth() == 1 && date.getDay() == 1) //一月一号扣年费
	{
		record(date, -fee, "annual fee");
	}
	accumulator->reset(date, balance);
	if (!checkSufficiency())
	{
		throw std::runtime_error("out of credit");
	}
	if (!checkSufficiency(0))
	{
		throw std::runtime_error("insufficient balance");
	}
}

auto CreditAccount::info() const -> std::string
{
	return std::string(id).append("    Balance: ").append(std::to_string(getBalance()))
	                      .append("    Available credit:").append(std::to_string(getAvailableCredit()));
}

//2019/2/3	C654321	rate	password	balance	credit	fee
auto CreditAccount::saveInfo() const -> std::string
{
	return initialDate.to_string() + " " + id + " " + std::to_string(rate) + " " + getPassword() + " " +
		std::to_string(getBalance()) + " " +
		std::to_string(credit) + " " + std::to_string(fee);
}

auto CreditAccount::show(std::ostream& os) const -> void
{
	os << id << "    Balance: " << getBalance() << "    Available credit:" << getAvailableCredit();
	//std::cout << "#" << id << "    Balance: " << getBalance() << "    Available credit:" << getAvailableCredit();
}

auto CreditAccount::notice() -> std::string
{
	std::string payment;
	if (getAvailableCredit() <= 0)
	{
		payment += "Insufficient credit\n";
	}

	if (getDebt())
	{
		payment += "Debt: " + std::to_string(getDebt()) + "\n";
	}

	return payment + Account::notice();
}

/*
 *	取款，amount为正，余额或者信用卡额度不足时抛出异常 
 */
auto CreditAccount::withdraw(const Date& date, const double& amount, const char* msg) -> void
{
	if (!checkSufficiency(amount))
	{
		throw std::runtime_error("insufficient balance");
	}
	record(date, -amount, msg);
	this->accumulator->calculate(date, rate, -amount);
}


auto CreditAccount::getFee() const -> double
{
	return fee;
}

auto CreditAccount::getCredit() const -> double
{
	return credit;
}

auto CreditAccount::getAvailableCredit() const -> double
{
	if (balance > 0)
	{
		return credit;
	}
	else
	{
		return credit + balance;
	}
}

auto CreditAccount::getDebt() const -> double
{
	return balance > 0 ? 0 : -balance;
}

/*
 *	检查余额是否充足
 *	充足返回1
 *	不足返回0
 */
auto CreditAccount::checkSufficiency(const double& amount) -> bool
{
	return (amount <= credit + balance);
}

/*
 *	检查余额是否充足
 *	充足返回1
 *	不足返回0
 */
auto CreditAccount::checkSufficiency() const -> bool
{
	return credit >= 0;
}
