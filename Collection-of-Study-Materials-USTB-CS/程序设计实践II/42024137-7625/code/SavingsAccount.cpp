#include "SavingsAccount.h"
#include <iostream>
#include <cmath>
#include "Accumulator.h"

SavingsAccount::SavingsAccount(const Date& date, const std::string& id, const double& rate,
                               const std::string& password): Account(
                                                                     date, id, rate, password,
                                                                     ACCOUNTMODE::savingsAccount)
{
}


//参数:需要取出的金额
//不足时返回0
auto SavingsAccount::checkSufficiency(const double& amount) -> bool
{
	return amount <= balance;
}

auto SavingsAccount::settle(const Date& date) -> void
{
	if (date.getMonth() != 1 || date.getDay() != 1) //不是一月一号，不结算
	{
		return;
	}
	accumulator->calculate(date, rate, 0);
	if (fabs(accumulator->getSum()) > 1e-6)
	{
		record(date, accumulator->getInterest(), "interest");
	}
	accumulator->reset(date, balance);
}

auto SavingsAccount::info() const -> std::string
{
	return std::string(id).append("    Balance: ").append(std::to_string(getBalance()));
}

//2018/1/23	S123456		0.015	password	balance
auto SavingsAccount::saveInfo() const -> std::string
{
	return initialDate.to_string() + " " + id + " " + std::to_string(rate) + " " + getPassword() + " " +
		std::to_string(getBalance());
}

auto SavingsAccount::show(std::ostream& os) const -> void
{
	os << "#" << id << "    Balance: " << getBalance();
}

auto SavingsAccount::deposit(const Date& date, const double& amount, const char* msg) -> void
{
	record(date, amount, msg);
	this->accumulator->calculate(date, rate, amount);
}

auto SavingsAccount::notice() -> std::string
{
	return Account::notice();
}


auto SavingsAccount::withdraw(const Date& date, const double& amount, const char* msg) -> void
{
	if (!checkSufficiency(amount))
	{
		throw std::runtime_error("insufficient balance");
	}
	record(date, -amount, msg);
	this->accumulator->calculate(date, rate, -amount);
}
