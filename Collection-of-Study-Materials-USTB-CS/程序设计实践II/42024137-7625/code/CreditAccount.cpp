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
 *	��� amount Ϊ��
 */
auto CreditAccount::deposit(const Date& date, const double& amount, const char* msg) -> void
{
	record(date, amount, msg);
	this->accumulator->calculate(date, rate, amount);
}

/*
 * ������Ϣ���ж��Ƿ���Ҫ������� �������׳��쳣 
 */
auto CreditAccount::settle(const Date& date) -> void
{
	if (date.getDay() != 1) //����ÿ��һ�ţ�������
	{
		return;
	}

	this->accumulator->calculate(date, rate, 0);
	if (fabs(accumulator->getSum()) > 1e-6)
	{
		record(date, accumulator->getInterest(), "interest");
	}

	if (date.getMonth() == 1 && date.getDay() == 1) //һ��һ�ſ����
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
 *	ȡ�amountΪ�������������ÿ���Ȳ���ʱ�׳��쳣 
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
 *	�������Ƿ����
 *	���㷵��1
 *	���㷵��0
 */
auto CreditAccount::checkSufficiency(const double& amount) -> bool
{
	return (amount <= credit + balance);
}

/*
 *	�������Ƿ����
 *	���㷵��1
 *	���㷵��0
 */
auto CreditAccount::checkSufficiency() const -> bool
{
	return credit >= 0;
}
