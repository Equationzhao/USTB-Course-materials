#include "AccountException.h"
#include <algorithm>

AccountException::AccountException(const std::string& msg): runtime_error(msg)
{
	errors.emplace_back(msg);
}

AccountException::AccountException(AccountException&& rhs) noexcept: runtime_error(rhs.what())

{
	std::swap(rhs.errors, errors);
}


//not recommended
//extra expense of mem
auto AccountException::what() const noexcept -> const char*
{
	static std::string what;

	if (what.empty())
	{
		for (const auto& i : errors)
		{
			what += i;
			what.append("\n");
		}
	}

	return what.c_str();
}

auto AccountException::show(std::ostream& os) const -> void
{
	std::for_each(errors.begin(), errors.end(), [&os](const std::string& i) { os << i << '\n'; });
}

auto AccountException::add(const std::string& info) -> void
{
	errors.emplace_back(info);
}


auto AccountException::getErrors() const -> std::vector<std::string>
{
	return errors;
}

auto AccountException::getErrorsInBuffer() const -> std::string
{
	std::string buffer;
	for (const auto& i : errors)
	{
		buffer += i;
		buffer.append("\n");
	}

	return buffer;
}

auto AccountException::getErrorOf(const int& index) -> std::string
{
	return errors.at(index);
}
