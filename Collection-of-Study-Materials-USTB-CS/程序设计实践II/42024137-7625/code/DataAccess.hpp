// /*
// *solution: BankSystem
// *project: BankSystem
// *file: DataAccess.hpp
// *time: 2021/09/20/16:41
// *author: Equationzhao
// */
#ifndef DATAACCESS_
#define DATAACCESS_
#include <stdexcept>

#include "Account.h"
#include "Command.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"

// todo rsa the password
namespace
{
	template <typename T>
	auto remove(std::vector<T>& v, T t)
	{
		std::remove(v.begin(), v.end(), t);
		while (v.back() == t)
		{
			v.pop_back();
		}
	}
}

/*	file structure:
 *
 *	"accounts.txt"
 *		S123456
 *		C654321
 *		......
 *
 *	"S123456.txt"
 *		2018/1/23	S123456		0.015	password	balance
 *		2018/2/1	1000	balance		salary
 *		2019/1/1	xxx		balance		interest
 *		2019/10/2	-400	balance		buy phone
 *		...
 *
 *	"C654321.txt"
 *		2019/2/3	C654321		rate	password balance	credit	fee
 *		2019/2/6	1300	balance		salary
 *		2019/10/2	-8		balance		buy coffee
 *		2019/11/1	-50		balance		fee
 *		2019/11/1	xxx		balance		interest
 *		...
 *
 *
 *	first construct the object then set value.
 *
 *
 *	throw exception when
 *	1) Account Information not found;
 *	2) Uncompleted Information 
 *	3) Invalid record
 *	4) Others like converting NAN to num
 *
 *
 *	all the error msg will be gathered together, and be thrown when the loading process completed.
 */
inline auto loadAccounts() -> void
{
	//every line is an account id
	auto acts = Loader("accounts.txt").loadByLine(); //get Account IDs

	remove(acts, std::string(""));

	if (acts.empty())
	{
		return;
	}
	GetAccounts getAccounts;

	std::string errorMsg;

	for (const auto& actID : acts)
	{
		if (actID.empty())
		{
			continue;
		}
		auto info = Loader(actID + ".txt").loadByLine(); //load information from corresponding file

		remove(info, std::string(""));

		if (info.empty()) //account information missing
		{
			errorMsg += (actID + " Account Information not found\n");
			continue;
		}

		BKSYS::string DIVinfo(info.at(0));
		// get basic info from the first line, like below
		// 2018/1/23	S123456		0.015	password	balance
		// 2019/2/3		C654321		0.00003	password balance	credit	fee


		const auto parameters = DIVinfo.split_into_vector();


		if (actID.at(0) == 'S')
		{
			if (parameters.size() != 5)
			{
				errorMsg += (actID + " uncompleted information\n");
			}


			Date startsDate;
			std::string id;
			double rate = 0;
			std::string password;
			double balance = 0;
			/*************get related paramaters******************/
			try
			{
				startsDate = getDate(parameters.at(0));
				id = parameters.at(1);
				rate = UTIL::toDouble(parameters.at(2));
				password = parameters.at(3);
				balance = UTIL::toDouble(parameters.at(4));
			}
			catch (const std::exception& e)
			{
				errorMsg += (actID) + " " + e.what();
				continue;
			}

			/****************************************************/

			auto savingsAccount = new SavingsAccount(startsDate, id, rate, password); //ctor SavingsAccount
			savingsAccount->setBalance(balance);
			//std::unique_ptr<Account> savingsAccount = std::make_unique<SavingsAccount>(startsDate, id, rate, password);
			try
			{
				//insert record
				std::for_each(info.begin() + 1, info.end(),
				              [&savingsAccount, &errorMsg, &actID, &startsDate](const std::string& ar)
				              {
					              if (ar.empty())
					              {
						              return;
					              }
					              try
					              {
						              /********************get related paramaters*********************/
						              const auto temp = BKSYS::string(ar).split_into_vector("    ");

						              const auto arDate = getDate(temp.at(0));

						              const auto amount = UTIL::toDouble(temp.at(1));

						              const auto recordBalance = UTIL::toDouble(temp.at(2));

						              std::string desc;
						              std::for_each(temp.begin() + 3, temp.end(),
						                            [&desc](const std::string& part)
						                            {
							                            desc.append(part).append(" ");
						                            });

						              /*********************************************************/

						              if (arDate < startsDate)
						              {
							              throw std::runtime_error("invalid record    " + ar);
						              }

						              //step 1
						              savingsAccount->insertIntoMyRecord(
						                                                 arDate, savingsAccount->getId(), amount,
						                                                 recordBalance, desc);
						              //step 2
						              Account::insertIntoTotalRecord(
						                                             arDate, savingsAccount->getId(), amount,
						                                             recordBalance,
						                                             desc);
					              } // todo 如何处理 step1成功 step2失败?
					              catch (const std::exception& e)
					              {
						              errorMsg += actID + " " + e.what() + "\n";
					              }
				              });
				getAccounts.get().emplace_back(savingsAccount);
			}
			catch (const std::exception&)
			{
				delete savingsAccount; //release ptr when error occurs
			}
		}
		else if (actID.at(0) == 'C')
		{
			if (parameters.size() != 7)
			{
				errorMsg += (actID + " uncompleted information\n");
			}
			//example: 2019/2/3	 C654321	0.00003		password balance	credit	fee
			/*************get related paramaters******************/

			Date startsDate;
			std::string id;
			double rate = 0;
			std::string password;
			double balance = 0;
			double credit = 0;
			double fee = 0;
			try
			{
				startsDate = getDate(parameters.at(0));
				id = parameters.at(1);
				rate = UTIL::toDouble(parameters.at(2));
				password = parameters.at(3);
				balance = UTIL::toDouble(parameters.at(4));
				credit = UTIL::toDouble(parameters.at(5));
				fee = UTIL::toDouble(parameters.at(6));
			}
			catch (const std::exception& e)
			{
				errorMsg += (actID) + " " + e.what();
				continue;
			}
			/****************************************************/

			auto creditAccount = new CreditAccount(startsDate, id, credit, rate, fee, password);
			creditAccount->setBalance(balance);
			//std::unique_ptr<Account> CreditAccount = std::make_unique<CreditAccount>(startsDate, id, rate, fee, credit, password);
			try
			{
				//insert record
				std::for_each(info.begin() + 1, info.end(),
				              [&creditAccount, &errorMsg, &actID, &startsDate](const std::string& ar)
				              {
					              if (ar.empty())
					              {
						              return;
					              }
					              try
					              {
						              /********************get related paramaters*********************/
						              const auto temp = BKSYS::string(ar).split_into_vector();

						              const auto arDate = getDate(temp.at(0));

						              const auto amount = UTIL::toDouble(temp.at(1));

						              const auto recordBalance = UTIL::toDouble(temp.at(2));

						              std::string desc;

						              std::for_each(temp.begin() + 3, temp.end(),
						                            [&desc](const std::string& part)
						                            {
							                            desc.append(part).append(" ");
						                            });


						              /*********************************************************/

						              if (arDate < startsDate)
						              {
							              throw std::runtime_error("invalid record    " + ar);
						              }

						              //step 1
						              creditAccount->insertIntoMyRecord(
						                                                arDate, creditAccount->getId(), amount,
						                                                recordBalance, desc);
						              //step 2
						              Account::insertIntoTotalRecord(
						                                             arDate, creditAccount->getId(), amount,
						                                             recordBalance,
						                                             desc);
					              } // todo 如何处理 step1成功 step2失败?
					              catch (const std::exception& e)
					              {
						              errorMsg += actID + " " + e.what() + "\n";
					              }
				              });
				getAccounts.get().emplace_back(creditAccount);
			}
			catch (const std::exception&)
			{
				delete creditAccount; //release ptr when error occurs
			}
		}
		else
		{
			errorMsg += (actID + " Wrong Account type\n");
		}


		if (!errorMsg.empty())
		{
			throw std::runtime_error(errorMsg);
		}
	}
}


/*	file structure:
 *
 *	"accounts.txt"
 *		S123456
 *		C654321
 *		......
 *
 *	"S123456.txt"
 *		2018/1/23	S123456		0.015	password	balance
 *		2018/2/1	1000	balance		salary
 *		2019/1/1	xxx		balance		interest
 *		2019/10/2	-400	balance		buy phone
 *		...
 *
 *	"C654321.txt"
 *		2019/2/3	C654321		0.00003	password	balance	credit	fee
 *		2019/2/6	1300	balance		salary
 *		2019/10/2	-8		balance		buy coffee
 *		2019/11/1	-50		balance		fee
 *		2019/11/1	xxx		balance		interest
 *		...
 */

//	Lock
inline auto saveAccounts(const std::string& id) -> void
{
	GetAccounts getAccounts;
	const auto& account = getAccounts.getOfId(id);
	const auto arVector = account->getMyAccountRecord();
	std::string buffer = account->saveInfo() + "\n";
	for (auto& ar : arVector)
	{
		buffer += (ar.to_string() + "\n");
	}
	Saver(account->getId() + ".txt", std::ios::out).save(buffer);
}

/*
 *
 *	Lock
 */
inline auto saveAccounts() -> void
{
	GetAccounts getAccounts;
	const auto& acts = getAccounts.get();
	for (const auto& actPtr : acts)
	{
		const auto arVector = actPtr->getMyAccountRecord();
		std::string buffer = actPtr->saveInfo() + "\n";
		for (auto& ar : arVector)
		{
			buffer += (ar.to_string() + "\n");
		}
		Saver(actPtr->getId() + ".txt", std::ios::out).save(buffer);
	}
}


//todo debug save&load 到底哪里需要save
#endif
