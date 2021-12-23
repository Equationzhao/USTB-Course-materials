#pragma once
#ifndef SAVINGSACCOUNT_
#define SAVINGSACCOUNT_
#include <string>

#include "Account.h"
#include "Date.h"

class SavingsAccount : public Account
{
private:
	auto checkSufficiency(const double& amount) -> bool override;
public:
	SavingsAccount() = delete;

	SavingsAccount(const Date& date, const std::string& id, const double& rate, const std::string& password);

	~SavingsAccount() override = default;

	auto settle(const Date& date) -> void override;

	auto info() const -> std::string override;

	auto saveInfo() const -> std::string override;

	auto show(std::ostream& os) const -> void override;

	auto withdraw(const Date& date, const double& amount, const char* msg) -> void override;

	auto deposit(const Date& date, const double& amount, const char* msg) -> void override;

	auto notice() -> std::string override;
};

#endif
