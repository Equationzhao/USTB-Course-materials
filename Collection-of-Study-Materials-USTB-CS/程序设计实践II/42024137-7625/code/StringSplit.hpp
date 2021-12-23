#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <iosfwd>
#ifndef BKSYS_
#define BKSYS_

namespace BKSYS
{
	class string : public std::string
	{
	public:
		string() : std::string("")
		{
		}

		explicit string(const std::string& resource) : std::string(resource)
		{
		}

		explicit string(std::string&& resource): std::string(std::move(resource))
		{
		}

		explicit string(const char* resource) : std::string(resource)
		{
		}

		friend auto operator<<(std::ostream& os, const string& rhs) -> std::ostream&
		{
			os << std::string(rhs.c_str());
			return os;
		}

		~string() = default;

		auto split_into_vector(const std::string& delims = " ") const -> std::vector<std::string>
		{
			const std::string str(c_str());
			std::vector<std::string> output;
			output.reserve(this->size());
			for (auto first = str.data(), second = str.data(), last = first + str.size(); second != last && first !=
			     last; first = second + 1)
			{
				//second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

				second = std::find_first_of(first, last, std::begin(delims), std::end(delims));

				if (first != second)
				{
					output.emplace_back(first, second);
				}
			}
			return output;
		}


		auto remove(const std::string& a) -> void
		{
			const auto resVector = split_into_vector(a);


			string res;
			res.reserve(this->size());

			std::for_each(resVector.begin(), resVector.end(), [&res](const std::string& part)
			{
				res += part;
			});

			*this = res;
		}
	};


	inline auto remove(const std::string& a, const std::string& b) -> std::string
	{
		string c(a);
		c.remove(b);
		return std::move(c);
	}
}
#endif
