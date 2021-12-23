#pragma once
#include <cmath>
#ifndef UTIL_
#define UTIL_
#include <stdexcept>
#include <vector>
#include <random>
#include <regex>
#include <map>
#include "StringSplit.hpp"


namespace UTIL
{
	/*
	 *	判断是否是正整数
	 *
	 */
	inline auto isUnsignedInteger(const std::string& str) -> bool
	{
		return std::all_of(str.begin(), str.end(), iswdigit);
	}

	/*
	 *	判断是否是整数
	 *	是-true
	 *	否-false
	 */
	inline auto isInteger(const std::string& str) -> bool
	{
		if (iswdigit(str[0]) || str[0] == '-')
		{
			return std::all_of(str.begin() + 1, str.end(), iswdigit);
		}
		return false;
	}

	/*
	 *	判断是否是double 类型
	 *	是-true
	 *	否-false
	 */
	inline auto isDouble(const std::string& str) -> bool
	{
		bool e = false;
		bool E = false;
		std::string split;
		for (const auto& i : str)
		{
			if (i == 'e')
			{
				if (!e && !E)
				{
					e = true;
				}
				else
				{
					return false;
				}
			}
			else if (i == 'E')
			{
				if (!e && !E)
				{
					E = true;
				}
				else
				{
					return false;
				}
			}
		}

		if (e)
		{
			split = "e";
		}
		else if (E)
		{
			split = "E";
		}

		const std::vector<std::string> partsOfStr = BKSYS::string(str).split_into_vector(split);

		auto check = [](const std::string& str) -> bool
		{
			bool dot(false);
			for (auto c = str.begin(); c != str.end(); ++c)
			{
				if (c == str.begin() && *c == '-')
				{
					continue;
				}

				if (!iswdigit(*c))
				{
					if (!dot && *c == '.')
					{
						dot = true;
					}
					else
					{
						return false;
					}
				}
			}
			return true;
		};

		return std::all_of(partsOfStr.begin(), partsOfStr.end(), check);
	}

	/*
	 *	判断是否是数字
	 *	依次调用 isInteger isDouble
	 */
	inline auto isNum(const std::string& str) -> bool
	{
		//do not change order
		return isInteger(str) || isDouble(str);
	}


	/**
	 * 转化string为整数
	 * 是则返回该数字,若格式不对,抛出异常
	 * 判断double的方法还是太愚蠢了
	 */
	inline auto toInteger(const std::string& str) -> int
	{
		bool minus(false);
		int res = 0;
		for (auto c = str.begin(); c != str.end(); ++c)
		{
			if (c == str.begin() && *c == '-')
			{
				minus = true;
				continue;
			}

			if (iswdigit(*c))
			{
				res *= 10;
				res += *c - '0';
			}
			else
			{
				throw std::runtime_error("Bad input(NAN)");
			}
		}

		return minus ? -res : res;
	}

	/**
	 * brief convert string like "-43.54e-2.54" or "324325.321" to double
	 * param str
	 * return double NAN throw exception
	 *
	 * **low efficiency**
	 */
	inline auto toDouble(const std::string& str) -> double
	{
		//判断字符中有无e或E,若有超过一个,报错
		//若无,直接计算
		//若e不为第一个数字,则将其分为前后两部分计算
		//若e为第一个数字,则在其前面加上1,回到上一步

		bool e = false;
		bool E = false;
		std::string split;
		for (const auto& i : str)
		{
			if (i == 'e')
			{
				if (!e && !E)
				{
					e = true;
				}
				else
				{
					throw std::runtime_error("NAN");
				}
			}
			else if (i == 'E')
			{
				if (!e && !E)
				{
					E = true;
				}
				else
				{
					throw std::runtime_error("NAN");
				}
			}
		}

		if (e)
		{
			split = "e";
		}
		else if (E)
		{
			split = "E";
		}

		std::vector<std::string> partsOfStr;

		if (*str.begin() == 'e')
		{
			partsOfStr = BKSYS::string(std::string("1").append(str)).split_into_vector(split);
		}
		else
		{
			partsOfStr = BKSYS::string(str).split_into_vector(split);
		}
		double res = 0;

		auto cal = [](const std::string& str) -> double
		{
			bool minus(false);
			bool dot(false);
			double res = 0;
			int n = 0;
			for (auto c = str.begin(); c != str.end(); ++c)
			{
				if (c == str.begin() && *c == '-')
				{
					minus = true;
					continue;
				}

				if (iswdigit(*c))
				{
					if (dot)
					{
						++n;
						res += (static_cast<double>(*c) - '0') * pow(10.0, -n);
					}
					else
					{
						res *= 10;
						res += static_cast<double>(*c) - '0';
					}
				}
				else if (!dot && *c == '.')
				{
					dot = true;
				}
				else
				{
					throw std::runtime_error("NAN");
				}
			}
			return minus ? -res : res;
		};

		res += cal(partsOfStr.at(0));
		if (partsOfStr.size() == 2)
		{
			res *= pow(10, cal(partsOfStr.at(1)));
		}

		return res;
	}


	inline auto isPositiveNum(const std::string& str) -> bool
	{
		try
		{
			return toDouble(str) > 0;
		}
		catch (...)
		{
			return false;
		}
	}

	inline auto isPhoneNum(const std::string& phone) -> bool
	{
		return std::regex_match(phone, std::regex("1([0-9]{10})"));
	}

	class RandomGenerator
	{
	private:
		std::default_random_engine e;

	public:
		RandomGenerator() : e(time(nullptr))
		{
		}

		template <typename T>
		auto get_from_to(const T& begin, const T& end) -> T
		{
			std::uniform_int_distribution<T> u(begin, end);
			return u(e);
		}
	};


	/*	
	 *	usage:
	 *	
	 *	std::map<AccountMode, std::string> rule =
	 *	{
	 *		{ACCOUNTMODE::savingsAccount, "S"},
	 *		{ACCOUNTMODE::creditAccount, "C"}
	 *	};
	 *	
	 *	const UTIL::UUIDGenerator<AccountMode, std::string> uuidGeneratorTest(std::move(rule));	
	 *	
	 *	auto id = uuidGeneratorTest(ACCOUNTMODE::SavingsAccount);
	 *	
	 *	std::cout<<id<<'\n';
	 *	
	 *	
	 *	result:S5523997	
	 */
	template <typename T, typename U>
	class UUIDGenerator
	{
	private:
		std::map<T, U> prefixCastRule;

	public:
		explicit UUIDGenerator(const std::map<T, U>& prefixCastRule) : prefixCastRule(prefixCastRule)
		{
		}

		explicit UUIDGenerator(std::map<T, U>&& prefixCastRule) : prefixCastRule(std::move(prefixCastRule))
		{
		}

		auto operator()(const T& key) const -> std::string
		{
			constexpr auto i = 1000000;
			std::string prefix;
			try
			{
				prefix = prefixCastRule.at(key);
			}
			catch (...)
			{
				throw std::runtime_error("Undefined account type");
			}
			static RandomGenerator randomGenerator;
			constexpr time_t startTime(1498122787);
			int mid(static_cast<int>(difftime(time(nullptr), startTime)));
			mid /= 10000000;
			return prefix.append(std::to_string(randomGenerator.get_from_to(i, i * 10 - 1)));
		}
	};

	inline auto getRealTm() -> tm
	{
		time_t now = time(nullptr);
		//tm *systime = nullptr;
		tm systime{};
		//systime = gmtime(&now);
		gmtime_s(&systime, &now); //on MSVC
		//tm newTm = *systime;
		//delete systime;
		//return newTm;
		return systime;
	}
}

#endif
