// /*
// *solution: BankSystem
// *project: BankSystem
// *file: test.cpp
// *time: 2021/09/16/12:13
// *author: Equationzhao
// */

#include "Util.hpp"
#include "Date.h"
#include "safe_ptr.h"
bool Saver::status(false);

auto main() -> int
{
	std::cout << DATE::getSystemDate()<<'\n';
	DATE::setToRealTime();
	std::cout << DATE::getSystemDate();
}
