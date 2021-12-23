#include "AccountRecord.h"


AccountRecord::AccountRecord(const Date& date, std::string account, const double& amount,
                             const double& balance,
                             const std::string& desc): date(date), accountID(account), amount(amount), balance(balance),
                                                       desc(desc)
{
}

//date amount balance desc
auto AccountRecord::to_string() const -> std::string
{
	return date.to_string() + "    " + std::to_string(amount) + "    " + std::to_string(balance) + "    " + desc;
}

auto AccountRecord::getDate() const -> Date
{
	return date;
}

auto AccountRecord::getAccountID() const -> std::string
{
	return accountID;
}

auto AccountRecord::getDesc() const -> std::string
{
	return desc;
}


auto AccountRecord::getAmount() const -> double
{
	return amount;
}

auto AccountRecord::getBalance() const -> double
{
	return balance;
}

auto AccountRecord::ascendAmountComparator() -> std::function<bool(const AccountRecord& lhs, const AccountRecord& rhs)>
{
	return [](const AccountRecord& lhs, const AccountRecord& rhs)-> bool { return lhs.amount < rhs.amount; };
}

auto AccountRecord::ascendDateComparator() -> std::function<bool(const AccountRecord& lhs, const AccountRecord& rhs)>
{
	return [](const AccountRecord& lhs, const AccountRecord& rhs)-> bool { return lhs.date < rhs.date; };
}


auto operator<<(std::ostream& os, const AccountRecord& rhs) -> std::ostream&
{
	os << rhs.date << "    " << rhs.amount << "    " << rhs.balance << "    " << rhs.desc;
	return os;
}

auto operator<(const AccountRecord& lhs, const AccountRecord& rhs) -> bool
{
	return lhs.date < rhs.date;
}
