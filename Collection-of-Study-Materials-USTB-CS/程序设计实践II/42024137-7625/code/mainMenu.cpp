#include "mainMenu.h"


auto mainMenu::getType(std::istream& is)
{
	std::string cmd;

	is >> cmd;
	if (cmd != "s" && cmd != "c" && cmd != "e")
	{
		throw std::runtime_error("Bad input");
	}

	return cmd;
}

auto mainMenu::getPassWord(std::istream& is) const -> std::string
{
	std::string password;
	is >> password;

	if (password.size() != 6 || !std::all_of(password.begin(), password.end(), isdigit))
	{
		throw std::runtime_error("Password should be six digits");
	}

	return password;
}

auto mainMenu::Register(std::ostream& os, std::istream& is) -> void
{
	const static std::map<AccountMode, std::string> rule =
	{
		{ACCOUNTMODE::savingsAccount, "S"},
		{ACCOUNTMODE::creditAccount, "C"}
	};

	const static UTIL::UUIDGenerator<AccountMode, std::string> uuidGenerator(rule);
	os << "Choose the Type of the account you want to sign up for."
		<< '\n' << "<s> SavingsAccount    <c> CreditAccount    <e> exit" << '\n';

	AccountMode accountMode;
	std::string type;


	while (true)
	{
		try
		{
			type = getType(is);
		}
		catch (const std::exception& e)
		{
			os << e.what() << '\n';
		}
		if (type == "s")
		{
			accountMode = ACCOUNTMODE::savingsAccount;
			break;
		}
		if (type == "c")
		{
			accountMode = ACCOUNTMODE::creditAccount;
			break;
		}
		if (type == "e")
		{
			return;
		}
	}

	std::string password;
	while (true)
	{
		os << "Type in Your password:\n";

		try
		{
			password = getPassWord(is);
			os << "Config password:\n";

			if (password == getPassWord(is))
			{
				break;
			}
			os << "The password did not match the re-typed password!\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}


	const auto id = uuidGenerator(accountMode);

	std::string cmd;
	constexpr auto rate1 = 0.015, rate2 = 0.0005;

	switch (accountMode)
	{
	case ACCOUNTMODE::savingsAccount:
		{
			cmd = "a " + type + " " + id + " " + std::to_string(rate1) + " " + password;

			break;
		}
	case ACCOUNTMODE::creditAccount:
		{
			constexpr auto fee = 50;
			constexpr auto credit = 10000;
			cmd = "a " + type + " " + id + " " + std::to_string(credit) + " " + std::to_string(rate2) + " " +
				std::to_string(fee) + " " + password;
			break;
		}
	default:
		{
			throw std::runtime_error("Account type not exist");
		}
	}


	const std::unique_ptr<Command> exe(CommandCreator().getCommand(cmd));

	try
	{
		exe->execute();
		os << DATE::getSystemDate() << "    " << id << " created\n";
		system("pause");
	}
	catch (...)
	{
		os << "Failed, try again later\n";
		BankSystemError("Failed, try again later");
	}
}

auto mainMenu::signIn(std::ostream& os, std::istream& is) const -> std::unique_ptr<UserCommandCreator>
{
	os << "Type in Your Id:\n";
	std::string id;
	is >> id;
	os << "Type in your password\n";
	std::string password;
	is >> password;
	GetAccounts getAccounts;
	const auto act = getAccounts.getOfId(id);
	if (act->checkPassword(password))
	{
		auto userCommandCreator = std::make_unique<UserCommandCreator>(id, password);
		return userCommandCreator;
	}
	else
	{
		throw std::runtime_error("Authentication failure");
	}
}

auto mainMenu::operator()(std::ostream& os, std::istream& is) -> void
{
	os << "\tUSTB Bank\n\t" << DATE::getSystemDate() << '\n';

	std::string cmd;
	while (true)
	{
		os << "<i>Sign in    <u>Sign Up\n";
		is >> cmd;

		if (cmd == "i")
		{
			try
			{
				const std::unique_ptr<UserCommandCreator> userCommandCreatorPtr = std::move(signIn(os, is));
				os <<
					"Success\n<d>deposit\t<w>withdraw\t<s>show\t<c>change day\t<n>next month\t<q>query\t<t>query by time\t<v>query by amount\t<e>exit\n";

				os << userCommandCreatorPtr->notice();
				while (true)
				{
					try
					{
						std::string userCmd;
						std::getline(is, userCmd);
						if (userCmd.empty() || std::ranges::all_of(userCmd, [](const char& c) { return c == ' '; }))
						{
							continue;
						}

						if (!userCommandCreatorPtr->send(userCmd))
						{
							system("cls");
							break;
						}
					}
					catch (const std::exception& e)
					{
						os << e.what() << '\n';
					}
				}
			}
			catch (const std::exception& e)
			{
				os << e.what() << '\n';
			}
		}
		else if (cmd == "u")
		{
			Register(os, is);
			system("cls");
		}
		else if (cmd == "e")
		{
			system("cls");
			return;
		}
		else
		{
			os << "Bad input\n";
		}
	}
}
