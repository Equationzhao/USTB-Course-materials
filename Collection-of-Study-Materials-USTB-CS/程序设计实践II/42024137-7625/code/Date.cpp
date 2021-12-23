#include "Date.h"
#include <array>
#include <string>


auto Date::isValid(const int& year, const int& month, const int& day) -> bool
{
	if (day <= 0 || month > 12 || month < 1)
	{
		return false;
	}

	int d = DATE::dayOfMonth[month - 1];
	if (month == 2 && isLeapYear(year))
	{
		++d;
	}
	return d >= day;
}

auto Date::isLeapYear(const int& year) -> bool
{
	return (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0);
}

auto Date::countFromZero() const -> int
{
	const int m = month;
	const int d = day;
	const int y = year;

	auto g = [&]() //same as getMaxDay()

	{
		int sum = 0;
		for (int i = 0; i < m - 1; ++i)
		{
			sum += DATE::dayOfMonth[i];
		}
		return sum + d;
	};

	return 365 * (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + g() + (m > 2 && isLeapYear(y) ? 1 : 0);
}


Date::Date()
{
	year = month = day = 0;
}


Date::Date(const int& year, const int& month, const int& day): year(year), month(month), day(day)
{
}

Date::Date(const std::initializer_list<int>& initializer)
{
	int temp[3]{0, 0, 0};
	int count = 0;
	for (const auto& i : initializer)
	{
		temp[count++] = i;
	}
	year = temp[0];
	month = temp[1];
	day = temp[2];
}

auto Date::getYear() const -> int
{
	return year;
}

auto Date::getMonth() const -> int
{
	return month;
}

auto Date::getDay() const -> int
{
	return day;
}

auto Date::getMaxDay() const -> int
{
	return DATE::dayOfMonth[month - 1];
}

auto Date::show() const -> void
{
	std::cout << *this;
}

auto Date::to_string() const -> std::string
{
	return std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day);
}

auto Date::getDayOfYear() const -> int
{
	return 365 + isLeapYear(this->year);
}

auto Date::read(std::istream& is) -> Date
{
	Date temp;
	is >> temp;
	return temp;
}

auto Date::operator=(const Date& rhs) -> Date&
{
	year = rhs.year;
	month = rhs.month;
	day = rhs.day;
	return *this;
}

/*
 * input "2008/10/1" throw invalid_date
 */
auto operator>>(std::istream& is, Date& date) -> std::istream&
{
	std::string dateStr;
	is >> dateStr;


	dateStr.append("/");
	std::array<int, 3> arr{-1, -1, -1};
	int i = 0;
	int count = 0;
	for (const auto& j : dateStr)
	{
		if (j != '/')
		{
			i *= 10;
			i += j - '0';
		}
		else
		{
			arr.at(count++) = i;
			i = 0;
		}
	}
	if (!Date::isValid(arr[0], arr[1], arr[2]))
	{
		throw std::runtime_error("invalid date");
	}
	date = std::initializer_list<int>{arr[0], arr[1], arr[2]};

	return is;
}

auto operator<<(std::ostream& os, const Date& date) -> std::ostream&
{
	os << date.year << "/" << date.month << "/" << date.day;
	return os;
}


auto operator-(const Date& lhs, const Date& rhs) -> int
{
	return lhs.countFromZero() - rhs.countFromZero();
}

auto operator>(const Date& lhs, const Date& rhs) -> bool
{
	return lhs.countFromZero() > rhs.countFromZero();
}

auto operator<(const Date& lhs, const Date& rhs) -> bool
{
	return lhs.countFromZero() < rhs.countFromZero();
}

auto operator<=(const Date& lhs, const Date& rhs) -> bool
{
	return !(rhs < lhs);
}

auto operator>=(const Date& lhs, const Date& rhs) -> bool
{
	return !(lhs < rhs);
}

auto operator==(const Date& lhs, const Date& rhs) -> bool
{
	return (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year);
}
