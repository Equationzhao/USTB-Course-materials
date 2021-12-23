#pragma once
#ifndef ACCUMULATOR_
#define ACCUMULATOR_
#include "Date.h"

using AccountMode = int;

class Date;

namespace ACCOUNTMODE
{
	constexpr int savingsAccount = 1;
	constexpr int creditAccount = 2;
}


class Accumulator
{
private:
	double sum;
	double value;
	AccountMode mode;
	Date lastDate;
	sf::default_contention_free_shared_mutex mutex_{};
	auto addToValue(const double& value) -> void;
public:
	Accumulator() = delete;

	explicit Accumulator(const AccountMode& mode);

	auto calculate(const Date& date, const double& rate, const double& value) -> void;

	auto reset(const Date& date, const double& value = 0) noexcept -> void;

	auto getSum() noexcept -> double;

	auto getInterest() noexcept -> double;
};
#endif
