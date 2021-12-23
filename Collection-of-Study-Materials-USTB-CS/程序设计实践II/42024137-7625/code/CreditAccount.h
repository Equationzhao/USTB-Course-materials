#pragma once
#ifndef CREDITACCOUNT_
#define CREDITACCOUNT_
#include "Account.h"

//todo thread safe
class CreditAccount : public Account
{
private:
	std::atomic<double> fee;
	std::atomic<double> credit;

	auto checkSufficiency(const double& amount) -> bool override;
	auto checkSufficiency() const -> bool;
public:
	CreditAccount() = delete;

	CreditAccount(const Date& date, const std::string& id, const double& credit, const double& rate,
	              const double& fee, const std::string& password);

	~CreditAccount() override = default;

	auto getFee() const -> double;

	auto getCredit() const -> double;

	auto getAvailableCredit() const -> double;

	auto getDebt() const -> double;

	auto withdraw(const Date& date, const double& amount, const char* msg) -> void override;

	auto deposit(const Date& date, const double& amount, const char* msg) -> void override;

	auto settle(const Date& date) -> void override;

	auto info() const -> std::string override;

	auto saveInfo() const -> std::string override;

	auto show(std::ostream& os) const -> void override;

	auto notice() -> std::string override;
};

#endif
