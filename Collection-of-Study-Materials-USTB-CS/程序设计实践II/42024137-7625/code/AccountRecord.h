#pragma once

#ifndef ACCOUNTRECORD_
#define ACCOUNTRECORD_
#include <functional>

#include "Date.h"

class Date;

class AccountRecord
{
private:
	Date date;
	std::string accountID;
	double amount;
	double balance;
	std::string desc;
public:
	AccountRecord() = delete;

	~AccountRecord() = default;

	AccountRecord(const Date& date, std::string accountID, const double& amount, const double& balance,
	              const std::string& desc);

	auto to_string() const -> std::string;

	auto getDate() const -> Date;

	auto getAmount() const -> double;

	auto getAccountID() const -> std::string;

	auto getDesc() const -> std::string;

	auto getBalance() const -> double;

	friend auto operator<<(std::ostream& os, const AccountRecord& rhs) -> std::ostream&;

	friend auto operator<(const AccountRecord& lhs, const AccountRecord& rhs) -> bool;

	static auto ascendAmountComparator() -> std::function<bool(const AccountRecord& lhs, const AccountRecord& rhs)>;

	static auto ascendDateComparator() -> std::function<bool(const AccountRecord& lhs, const AccountRecord& rhs)>;
};

using account_record_query_order = std::function<bool(const AccountRecord&, const AccountRecord&)>;

#endif
