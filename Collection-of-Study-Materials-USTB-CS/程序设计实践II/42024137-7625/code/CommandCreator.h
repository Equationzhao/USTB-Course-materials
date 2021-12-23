#pragma once
#ifndef COMMANDCREATOR_
#define COMMANDCREATOR_
#include "StringSplit.hpp"
#include "Command.h"
#include <string>

#include "StringSplit.hpp"

class CommandCreator
{
protected:
	char firstCmd;
	BKSYS::string totalCmd;
	static std::string split;
public:
	explicit CommandCreator() noexcept;
	CommandCreator(const CommandCreator&) = delete;
	auto operator =(const CommandCreator&) = delete;
	auto parse() -> std::vector<std::string>;
	static auto getDateSplit() -> std::string;
	static auto setDateSplit(const std::string& split) -> void;
	auto getCommand(const std::string& cmd) -> Command*;
};

inline std::string CommandCreator::split = "/";

#endif // !_CommandCreator_


#ifndef USERCOMMANDCREATOR_
#define USERCOMMANDCREATOR_

class UserCommandCreator : public CommandCreator
{
private:
	const std::string id;
	std::string password;
public:
	explicit UserCommandCreator(const std::string& id, const std::string& password);
	~UserCommandCreator();
	UserCommandCreator(const UserCommandCreator&) = delete;
	auto operator =(const UserCommandCreator&) = delete;

	auto send(const std::string& cmd) -> bool;

	auto notice() const -> std::string;
};
#endif
