#include "Accumulator.h"
#include <cmath>


/*
 *	增加 value
 */
auto Accumulator::addToValue(const double& value) -> void
{
	mutex_.lock();
	this->value += value;
	mutex_.unlock();
}

Accumulator::Accumulator(const AccountMode& mode): sum(0), value(0), mode(mode)
{
}

/*
 *	value 存取款的改变量 分正负
 */
auto Accumulator::calculate(const Date& date, const double& rate,
                            const double& value) -> void
{
	mutex_.lock();
	double base = 0;
	base = (date - lastDate) * rate;
	lastDate = date;
	switch (mode)
	{
	case ACCOUNTMODE::savingsAccount:
		{
			base *= this->value;
			if (date.getDay() == 1 && date.getMonth() == 1)
			{
				sum += base / (Date::isLeapYear(date.getYear() - 1) + 365);
			}
			else
			{
				sum += base / (Date::isLeapYear(date.getYear()) + 365);
			}

			break;
		}
	case ACCOUNTMODE::creditAccount:
		{
			if (this->value < 1e-6)
			{
				base *= this->value;
				sum += base; //sum < 0
			}
			break;
		}
	default:
		{
			mutex_.unlock();
			throw std::runtime_error("What are you fucking doing??");
		}
	}
	sum = floor(sum * 100 + 0.5) / 100;

	this->addToValue(value);
	mutex_.unlock();
}

auto Accumulator::reset(const Date& date, const double& value) noexcept -> void
{
	mutex_.lock();
	lastDate = date;
	this->value = value;
	sum = 0;
	mutex_.unlock();
}

/*
*	使用后请使用reset重置 
*/
auto Accumulator::getSum() noexcept -> double
{
	mutex_.lock_shared();
	const auto res = sum;
	mutex_.unlock_shared();
	return res;
}

/*
 *	返回sum的值并将其置0，仍然需要reset 设置时间
 */
auto Accumulator::getInterest() noexcept -> double
{
	mutex_.lock();
	const auto res = sum;
	sum = 0;
	mutex_.unlock();
	return res;
}
