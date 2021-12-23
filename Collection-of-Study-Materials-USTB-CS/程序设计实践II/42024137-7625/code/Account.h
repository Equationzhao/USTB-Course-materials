#pragma once
#ifndef ACCOUNT_
#define ACCOUNT_
#include <functional>
#include <string>
#include <memory>
#include <set>
#include "safe_ptr.h"
#include "Accumulator.h"
#include "AccountRecord.h"
#include "Date.h"

class Accumulator;
class AccountRecord;
class Date;
using AccountMode = int;


//todo fix copy&backup
class Account
{
private:
	std::string password;
protected:
	const std::string id;
	const Date initialDate;
	std::atomic<double> balance;
	std::atomic<double> rate;

	static std::atomic<double> total;

	static std::multiset<AccountRecord> recordSet;

	static sf::default_contention_free_shared_mutex recordSetMutex;

	std::shared_ptr<Accumulator> accumulator;

	std::multiset<AccountRecord> myRecordSet;
	sf::default_contention_free_shared_mutex myRecordSetMutex;

	Account(const Date& date, const std::string& id, const double& rate, const std::string& password, AccountMode mode);

	virtual auto checkSufficiency(const double& amount) -> bool = 0;

	auto record(const Date& date, const double& amount, const char* msg) -> void;

	static auto error(const std::string& msg) -> void;

	auto getPassword() const -> std::string;

public:
	Account() = delete;
	Account(const Account&) = delete;
	auto operator =(const Account&) = delete;
	virtual ~Account() = default;

	auto setPassword(const std::string& newPass) -> void;
	//function todo change Password
	auto checkPassword(const std::string& password) const -> bool;

	auto getId() const noexcept -> std::string;
	auto getBalance() const noexcept -> double;
	auto getRate() const noexcept -> double;
	auto setBalance(const double& balance) -> void;

	virtual auto info() const -> std::string =0;
	virtual auto saveInfo() const -> std::string = 0;
	virtual auto show(std::ostream& os = std::cout) const -> void =0;
	virtual auto deposit(const Date& date, const double& amount, const char* msg = nullptr) -> void =0;
	virtual auto withdraw(const Date& date, const double& amount, const char* msg = nullptr) -> void =0;
	virtual auto settle(const Date& date) -> void =0;

	virtual auto notice() -> std::string;


	static auto getTotal() noexcept -> double;
	static auto addTotal(const double& value) -> void;

	static auto query(const Date& date1, const Date& date2) -> std::string;

	static auto insertIntoTotalRecord(const AccountRecord& ar) -> void;


	static auto insertIntoTotalRecord(const Date& date, const std::string& accountID, const double& amount,
	                                  const double& balance,
	                                  const std::string& desc) -> void;

	auto insertIntoMyRecord(const AccountRecord& ar) -> void;

	auto insertIntoMyRecord(const Date& date, const std::string& accountID, const double& amount, const double& balance,
	                        const std::string& desc) -> void;

	auto getMyAccountRecord() -> std::vector<AccountRecord>;

	auto getMyAccountRecord(std::vector<AccountRecord>& myAccountRecord) -> void;

	auto query_this(const Date& d1, const Date& d2) -> std::string;

	auto query_this_by_order(const Date& d1,
	                         const Date& d2,
	                         const std::function<bool(const AccountRecord&, const AccountRecord&)>& order)
	-> std::vector<AccountRecord>;
};

#endif
