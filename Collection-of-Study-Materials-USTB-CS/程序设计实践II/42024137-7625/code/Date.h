#pragma once
#include <iostream>
#include <ctime>
#include "error.hpp"
#include "Util.hpp"
#ifndef DATE_
#define DATE_

class Date
{
private:
	int year;
	int month;
	int day;
	auto countFromZero() const -> int;
	friend auto getDate(const int& year, const int& month, const int& day) -> Date;

public:
	Date();

	Date(const Date& rhs): year(rhs.year), month(rhs.month), day(rhs.day)
	{
	}

	static auto isValid(const int& year, const int& month, const int& day) -> bool;
	static auto isLeapYear(const int& year) -> bool;
	Date(const int& year, const int& month, const int& day);
	Date(const std::initializer_list<int>& initializer);
	auto getYear() const -> int;
	auto getMonth() const -> int;
	auto getDay() const -> int;
	auto getMaxDay() const -> int;
	auto show() const -> void;
	auto to_string() const -> std::string;
	auto getDayOfYear() const -> int;

	static auto read(std::istream& is = std::cin) -> Date;

	auto operator =(const Date& rhs) -> Date&;

	friend auto operator>>(std::istream& is, Date& date) -> std::istream&;
	friend auto operator<<(std::ostream& os, const Date& date) -> std::ostream&;
	friend auto operator-(const Date& lhs, const Date& rhs) -> int;
	friend auto operator>(const Date& lhs, const Date& rhs) -> bool;
	friend auto operator<(const Date& lhs, const Date& rhs) -> bool;
	friend auto operator<=(const Date& lhs, const Date& rhs) -> bool;
	friend auto operator>=(const Date& lhs, const Date& rhs) -> bool;
	friend auto operator==(const Date& lhs, const Date& rhs) -> bool;
};


/*
    返回Date类时间,不合法则抛出异常
 */
inline auto getDate(const int& year, const int& month, const int& day) -> Date
{
	if (!Date::isValid(year, month, day))
	{
		throw std::runtime_error("invalid date");
	}
	return {year, month, day};
}

//default delimiter="/"
//convert string like "2000/1/1" to Date
inline auto getDate(const std::string& date, const std::string& delimiter = "/") -> Date
{
	auto dateVector = BKSYS::string(date).split_into_vector(delimiter);
	const auto size = dateVector.size();

	if (size != 3)
	{
		throw std::runtime_error("Bad input");
	}

	if (std::all_of(dateVector.begin(), dateVector.end(), UTIL::isInteger))
	{
		const auto newDate = getDate(UTIL::toInteger(dateVector.at(0)), UTIL::toInteger(dateVector.at(1)),
		                             UTIL::toInteger(dateVector.at(2)));
		return newDate;
	}

	else
	{
		throw std::runtime_error("Bad input");
	}
}

namespace DATE
{
	static constexpr int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	inline Date g_SystemDate;
	static sf::default_contention_free_shared_mutex dateMutex;

	inline auto getSystemDate() -> Date
	{
		dateMutex.lock_shared();
		const auto temp = g_SystemDate;
		dateMutex.unlock_shared();
		return g_SystemDate;
	}

	inline auto setSystemDate(const Date& date) noexcept -> void
	{
		dateMutex.lock();
		g_SystemDate = date;
		dateMutex.unlock();
	}

	inline auto setToRealTime() -> void
	{
		const tm systime = UTIL::getRealTm();

		setSystemDate(Date(systime.tm_year + 1900, systime.tm_mon + 1, systime.tm_mday));
	}

	//std::mutex g_accountsVectorMutex;

	//std::mutex g_SystemDateMutex;
}

#endif
