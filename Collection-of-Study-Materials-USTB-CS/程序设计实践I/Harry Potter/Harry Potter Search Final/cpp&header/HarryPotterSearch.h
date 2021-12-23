#pragma once
#ifndef _HARRY_POTTER_SEARCH_
#define _HARRY_POTTER_SEARCH_
#include <regex>
#include <string>
inline auto info() -> void;
inline auto softwareInformation() -> void;
auto initial() -> void;
auto showMenu() -> void;
auto gotoSearch() -> void;
auto search() -> void;
auto showTitle() -> void;
auto showOutcome() -> void;
auto checkNum( const char charNum[], int& n ) -> bool;
auto gotoRecord( const int& ) -> void;
auto isDigit( const std::string& str ) -> bool;
inline auto strict = false;

inline auto isDigit( const std::string& str ) -> bool
{
	auto flag(true);
	for (auto& i : str)
	{
		if (!isdigit(i))
		{
			flag = false;
			break;
		}
	}
	return flag;
}

class isChapterClass
{
public:
	auto operator()( const std::string& i ) -> bool
	{
		if (i.size() >= 25)
		{
			return false;
		}
		const std::regex pattern("chapter", std::regex::icase);
		return std::regex_search(i.begin(), i.end(), pattern);
	}
};

class isPageClass
{
public:
	auto operator()( const std::string& i ) -> bool
	{
		return !i.empty() && i.size() < 4 && isdigit(i.at(0));
	}
};

namespace option
{
inline char exit[] = "exit";
inline char search[] = "search";
inline char Goto[] = "goto";
inline char help[] = "help";
inline char clear[] = "clear";
inline char information[] = "info";
inline char strictOn[] = "strictOn";
inline char strictOff[] = "strictOff";
}
#endif
