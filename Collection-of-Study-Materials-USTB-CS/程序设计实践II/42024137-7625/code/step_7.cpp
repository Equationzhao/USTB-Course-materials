// /*
// *solution: BankSystem
// *project: BankSystem
// *file: step_7.cpp
// *time: 2021/09/19/13:55
// *author: Equationzhao
// */

#include <memory>
#include <vector>
#include "AccountException.h"
#include "BankIO.hpp"
#include "Command.h"
#include "CommandCreator.h"
#include "CreditAccount.h"
#include "DataAccess.hpp"
#include "mainMenu.h"
#include "SavingsAccount.h"
#include "StringSplit.hpp"


auto main() -> int
{
	CommandCreator factory;


	//DATE::setSystemDate(getDate(2008, 11, 1));

	try
	{
		DATE::setToRealTime();
	}
	catch (const std::exception&)
	{
		std::cerr << "time initial error\n";
		BankSystemError("time initial error");
	}

	Saver::statusOn();

	auto trd = []()
	{
		try
		{
			loadAccounts();
		}
		catch (const std::exception& e)
		{
			BankSystemError(e);
		}
	};


	std::thread load(trd);

	mainMenu menu;
	menu(std::cout, std::cin);

    std::set_terminate([]()
    {
        //sleep 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        BankSystemError("terminate");
    });
	Exit().execute();
}
