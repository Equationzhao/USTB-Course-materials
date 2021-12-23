#pragma once
#include <stdexcept>
#include "Date.h"
#include "Account.h"
#include <vector>
#ifndef ACCOUNTEXCEPTION_
#define ACCOUNTEXCEPTION_

class Account;

//todo 丰富异常信息
class AccountException final : public std::runtime_error
{
private:
	std::vector<std::string> errors{};
public:
	explicit AccountException(const std::string& msg);

	AccountException(AccountException&& rhs) noexcept;

	auto what() const noexcept -> const char* override;

	auto show(std::ostream& os) const -> void;

	auto add(const std::string& info) -> void;

	auto getErrors() const -> std::vector<std::string>;

	auto getErrorsInBuffer() const -> std::string;

	auto getErrorOf(const int& index) -> std::string;

	~AccountException() override = default;
};
#endif
