// /*
// *solution: BankSystem
// *project: BankSystem
// *file: mainMenu.h
// *time: 2021/09/22/22:44
// *author: Equationzhao
// */

#pragma once
#ifndef MAINMENU__
#define MAINMENU_
#include <istream>

#include "CommandCreator.h"
#include "Date.h"

class mainMenu
{
private:
	static auto getType(std::istream& is);

	auto getPassWord(std::istream& is) const -> std::string;

	auto Register(std::ostream& os, std::istream& is) -> void;


	auto signIn(std::ostream& os, std::istream& is) const -> std::unique_ptr<UserCommandCreator>;

public:
	auto operator()(std::ostream& os, std::istream& is) -> void;
};
#endif
