#pragma once
#include "Account.h"
#include <string>
#include <vector>
#include <atomic>
#ifndef COMMAND_
#define COMMAND_

class Command
{
protected:
	std::vector<std::string> initializer;
	auto initializerToString() const -> std::string;
public:
	Command() = default;

	explicit Command(const std::vector<std::string>& initializer) : initializer(initializer)
	{
	}


	explicit Command(std::vector<std::string>&& initializer) : initializer(initializer)
	{
	}

	virtual ~Command() = default;
	virtual auto execute() const -> void = 0;
};
#endif

#ifndef CREATEACCOUNT_
#define CREATEACCOUNT_

class CreateAccount : public Command
{
public:
	explicit CreateAccount(const std::vector<std::string>& initializer) : Command(initializer)
	{
	}


	explicit CreateAccount(std::vector<std::string>&& initializer) : Command(std::move(initializer))
	{
	}


	~CreateAccount() override = default;
};
#endif

#ifndef CREATESAVINGSACCOUNT_
#define CREATESAVINGSACCOUNT_

class CreateSavingsAccount : public CreateAccount
{
public:
	explicit CreateSavingsAccount(const std::vector<std::string>& initializer) : CreateAccount(initializer)
	{
	}

	explicit CreateSavingsAccount(std::vector<std::string>&& initializer) : CreateAccount(std::move(initializer))
	{
	}

	auto execute() const -> void override;

	~CreateSavingsAccount() override = default;
};
#endif

#ifndef CREATECREDITACCOUNT_
#define CREATECREDITACCOUNT_

class CreateCreditAccount : public CreateAccount
{
public:
	explicit CreateCreditAccount(const std::vector<std::string>& initializer) : CreateAccount(initializer)
	{
	}

	explicit CreateCreditAccount(std::vector<std::string>&& initializer) : CreateAccount(std::move(initializer))
	{
	}

	auto execute() const -> void override;
	~CreateCreditAccount() override = default;
};
#endif


#ifndef DEPOSIT_
#define DEPOSIT_

//存款 
class Deposit : public Command
{
public:
	explicit Deposit(const std::vector<std::string>& initializer);

	explicit Deposit(std::vector<std::string>&& initializer);

	auto execute() const -> void override;
	~Deposit() override = default;
};
#endif

#ifndef WITHDRAW_
#define WITHDRAW_

//取款
class Withdraw : public Command
{
public:
	explicit Withdraw(const std::vector<std::string>& initializer);

	explicit Withdraw(std::vector<std::string>&& initializer);

	auto execute() const -> void override;
	~Withdraw() override = default;
};
#endif

#ifndef SHOW_
#define SHOW_

//显示所有账户
class Show : public Command
{
private:
	std::string id;
public:
	Show() = default;
	explicit Show(const std::string& id);
	auto execute() const -> void override;
	~Show() override = default;
};
#endif

#ifndef CHANGEDAY_
#define CHANGEDAY_

//向后改变天数
class ChangeDay : public Command
{
private:
	short day;
public:
	explicit ChangeDay(const short day);

	auto execute() const -> void override;
	~ChangeDay() override = default;
};
#endif

#ifndef NEXTMONTH_
#define NEXTMONTH_

//进入下个月
class NextMonth : public Command
{
public:
	NextMonth() = default;

	auto execute() const -> void override;
	~NextMonth() override = default;
};
#endif

#ifndef QUERY_
#define QUERY_


class Query : public Command
{
protected:
	std::string id;
	std::string password;
	Date d1, d2;
public:
	//不保证d1,d2的大小关系,请在ctor前判断参数d1<d2
	Query(const Date& d1, const Date& d2, const std::string& id = "", const std::string& password = "");

	auto execute() const -> void override;
	~Query() override = default;
};
#endif

#ifndef EXIT_
#define EXIT_

//简单地调用exit("0") 线程不安全
class Exit : public Command
{
public:
	Exit() = default;
	auto execute() const -> void override;
	~Exit() override = default;
};


#endif


#ifndef QUERYBY_
#define QUERYBY_


class QueryBy : public Query
{
private:
	account_record_query_order order;
public:
	QueryBy(const Date& d1, const Date& d2, account_record_query_order order,
	        const std::string& id = "",
	        const std::string& password = ""): Query(d1, d2, id, password), order(order)
	{
	}

	auto execute() const -> void override;
};


#endif


#ifndef  GETACCOUNTS_
#define  GETACCOUNTS_


//
//	usage:
//
//	GetAccounts().get().xxxx();//Ctor + Dtor RAII
//
//	or
//
//	auto accounts = GetAccounts();
//	accounts.xxxx();(excluding getOfId(string))
//	
//					**ATTENTION**
//
//	if you want to unlock immediately, use unlock();
// 
class GetAccounts
{
private:
	static std::vector<Account*> accounts;
	static sf::default_contention_free_shared_mutex a_mutex_;
	std::atomic<int> time;
public:
	GetAccounts();

	~GetAccounts();


	// throw when not found
	// ReSharper disable once CppMemberFunctionMayBeStatic
	auto getOfId(const std::string& id) -> Account*;


	auto get() -> std::vector<Account*>&;

	auto unlock() -> void;
};

#endif
