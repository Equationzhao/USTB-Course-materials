#pragma once
#include <exception>
#include <string>
#include "BankIO.hpp"
#ifndef BANKSYSTEMERROR_
#define BANKSYSTEMERROR_

/*
*	发送错误信息至BankSystemError.log
*/
inline auto BankSystemError(const std::exception& exc) -> void
{
	const bool status = Saver::Status();
	Saver::statusOn();
	Saver("BankSystemError.log").save(exc.what());
	status ? Saver::statusOn() : Saver::statusOff();
}

inline auto BankSystemError(const std::string& msg) -> void
{
	const bool status = Saver::Status();
	Saver::statusOn();
	Saver("BankSystemError.log").save(msg);
	status ? Saver::statusOn() : Saver::statusOff(); // issue 
}

#endif // !_BANKSYSTEMERROR_
