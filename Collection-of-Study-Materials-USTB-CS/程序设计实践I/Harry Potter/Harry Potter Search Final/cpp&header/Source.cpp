/*
*Copyright (c) equationzhao All Rights Reserved.
*版本号： V1.1.1
*创建人： equationzhao
*电子邮箱：equationzhao@foxmail.com
*创建时间：2021.3.31
*更新时间：2021.4.29 00:22:02
*描述：USTB程序设计实践Ⅰ作业
*Public Repository:https://github.com/Equationzhao/Harry-Potter-Search
*/

#include <array>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>

#include "HarryPotterSearch.h"
#include "item.h"
#include "searchMap.h"
using namespace std;

/**
 * brief 存储需要查找的字符串
 */
char strFind[100];
/**
 * brief line的size
 */
int lineNo(0);
/**
 * brief 用于储存file中每行的字符串
 */
vector<string> textLine(50000); // NOLINT(clang-diagnostic-exit-time-destructors)
/**
 * brief 用于存储每条记录的索引
 */
vector<item> index; // NOLINT(clang-diagnostic-exit-time-destructors)

searchMap* searchMap::mainSearcher = new searchMap;

isChapterClass isChapter;
isPageClass isPage;

inline auto info() -> void
{
	cout << "哈利波特书籍检索系统v1.0.1\n";
}

inline auto softwareInformation() -> void
{
	cout << "* Copyright (c) EquationZhao All Rights Reserved.\n"
	<< "* 版本号： V1.1.1\n"
	<< "* 创建人： EquationZhao\n"
	<< "* 电子邮箱：equationzhao@foxmail.com\n"
	<< "* 创建时间：20210331\n"
	<< "* 更新时间：2021.4.29 00:22:02\n"
	<< "* 描述：USTB程序设计实践Ⅰ作业\n";
}

inline auto showInfo() -> void
{
	cout << "输入\"search NAME\",查询为\"NAME\"的人名/地名\n输入\"goto N\",查询第N条记录\n输入\"exit\"退出查询系统\n"
	<< "使用clear命令清除屏幕上的内容\n使用help命令以显示此提示\n使用info命令显示软件相关信息\n使用strictOn/strictOff命令启用/关闭严格模式\n\n";
}

inline auto showRemind() -> void
{
	cout << "注意:\n\t1.请不要在没有查询过时使用goto,会造成错误\n\t2.本软件对空格敏感,例如\"Harry Potter\"与\"Harry   Potter \"是不同的\n"
	<< "\t3.本软件默认关闭严格搜索模式,在检索人名/地名时影响较小,但在检索其他字符串时可能存在误差\n\t  若要启用/关闭严格模式,请使用strictOn/strictOff命令\n";
}

/**
 * brief 初始化,读取文件
 * 并将每行对应的页码和章节存入searchMap::mainSearcher
 */
auto initial() -> void
{
	setlocale(LC_ALL, "zh-CN");
	array<ifstream, 8> file;
	file[0].open("./textSource/hp1.txt", std::ifstream::in);
	file[1].open("./textSource/hp2.txt", std::ifstream::in);
	file[2].open("./textSource/hp3.txt", std::ifstream::in);
	file[3].open("./textSource/hp4.txt", std::ifstream::in);
	file[4].open("./textSource/hp5.txt", std::ifstream::in);
	file[5].open("./textSource/hp6.txt", std::ifstream::in);
	file[6].open("./textSource/hp7.txt", std::ifstream::in);
	file[7].open("./textSource/hp8.txt", std::ifstream::in);
	for (auto& filePtr : file)
	{
		int tempPage(0); //记录行数
		while (getline(filePtr, textLine[lineNo]))
		{
			if (isPage(textLine.at(lineNo)))
			{
				tempPage++;
				searchMap::mainSearcher->setPage(lineNo, tempPage);
			}
			else if (isChapter(textLine.at(lineNo)))
			{
				searchMap::mainSearcher->setChapter(lineNo, textLine[lineNo]);
			}
			lineNo++;
		}
		filePtr.close();
	}
}

/**
 * brief 清空vector 前往搜索
 */
auto gotoSearch() -> void
{
	index.clear();
	item::reset();
	cin.getline(strFind, 100);
	item::setName(strFind);
	search();
}

/**
 * brief 搜索
 */
auto search() -> void
{
	const auto len = strlen(strFind);
	searchMap::mainSearcher->initial();
	const auto start = clock();
	for (auto n = 0; n < lineNo; n++)
	{
		for (auto j = 0; j < static_cast<int>(textLine[n].size()); j++)
		{
			if (strFind[0] == textLine[n][j])
			{
				auto flag(true);
				for (auto k = 1; k < static_cast<int>(len); k++)
				{
					if (strFind[k] != textLine[n][k + j])
					{
						flag = false;
						if (!strict)
						{
							j += k; //strictOff
						}
						break;
					}
				}
				if (flag)
				{
					if (!strict)
					{
						j += len; //strictOff
					}

					index.emplace_back(n, searchMap::mainSearcher->searchChapter(n),
					                   searchMap::mainSearcher->searchPage(n));
				}
			}
		}
	}
	const auto end = clock();
	showOutcome();
	cout << "查询用时" << (static_cast<double>(end) - static_cast<double>(start)) / 1000 << "秒" << endl;
}

/**
 * brief 显示标题
 */
inline auto showTitle() -> void
{
	cout << left << "序号" << "\t" << "人名/地名" << "\t\t" << "页码" << "\t"
	<< setw(20) << "章节" << "   \t" << "书名" << endl;
}

/**
 * brief 输出结果
 */
auto showOutcome() -> void
{
	system("cls");
	info();
	if (!item::getFound())
	{
		cout << "没有查询到~~" << endl;
		return;
	}
	showTitle();
	for (const auto& i : index)
	{
		i.output();
	}
	cout << "共查询到" << index.size() << "条记录" << endl;
}

/**
 * brief 检查输入的是否为合法数字
 * param charNum 用户输入的以字符形式存储的数字
 * param n
 */
auto checkNum( const char charNum[], int& n ) -> bool
{
	const auto charLen = strlen(charNum);
	auto flag(true);
	for (auto i = 0; i < static_cast<int>(charLen); i++)
	{
		if (isdigit(charNum[i]))
		{
			n *= 10;
			n += charNum[i] - '0';
		}
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}

/**
 * brief 前往第N条记录
 * param n
 */
auto gotoRecord( const int& n ) -> void
{
	if (n > static_cast<int>(index.size()) || n == 0)
	{
		cout << "No existed record! :-(\n";
		return;
	}
	cout << "第" << n << "条记录" << endl;
	const auto tempLine = static_cast<size_t>(index[n - 1].getLineNum());
	if (tempLine == 0)
	{
		cout << textLine[0] << endl << textLine[2] << endl << textLine[4] << endl;
	}
	else if (tempLine == textLine.size() - 1)
	{
		cout << textLine[tempLine - 4] << endl << textLine[tempLine - 2] << endl << textLine[tempLine] << endl;
	}
	else
	{
		cout << textLine[tempLine - 2] << endl << textLine[tempLine] << endl << textLine[tempLine + 2] << endl;
	}
}

/**
 * brief 展示菜单
 */
auto showMenu() -> void
{
	auto flag = true;
	while (true)
	{
		char option[100];
		cin >> option;
		cin.ignore(); //For cin.getline() will recive '\n'
		if (!strcmp(option, option::search))
		{
			gotoSearch();
			flag = false;
		}
		else if (!strcmp(option, option::Goto))
		{
			if (flag)
			{
				cout << "No existed record! :-(\n";
				cin.ignore();
				continue;
			}
			char charNum[10];
			cin >> charNum;
			auto n = 0;
			if (checkNum(charNum, n))
			{
				gotoRecord(n); //跳转到第n条记录
			}
			else
			{
				cout << "NaN\nPlease input a valid NUMBER!\n";
			}
		}
		else if (!strcmp(option, option::exit))
		{
			return;
		}
		else if (!strcmp(option, option::clear))
		{
			system("cls");
		}
		else if (!strcmp(option, option::information))
		{
			softwareInformation();
		}
		else if (!strcmp(option, option::help))
		{
			showInfo();
		}
		else if (!strcmp(option, option::strictOn))
		{
			if (strict)
			{
				cout << "strict mode is already on!\n";
			}
			else
			{
				cout << "strict mode on\n";
				strict = true;
			}
		}
		else if (!strcmp(option, option::strictOff))
		{
			if (!strict)
			{
				cout << "strict mode is already off!\n";
			}
			else
			{
				strict = false;
				cout << "strict mode off\n";
			}
		}
		else
		{
			cout << "\nError\nType in \'help\' to get more information\n";
		}
	}
}

auto main() -> int
{
	SetConsoleTitle(L"哈利波特书籍检索系统");
	info(); //显示基本软件名称
	showInfo(); //显示基本操作
	showRemind(); //显示注意事项
	initial(); //初始接受文件信息并存于vector<string>中
	showMenu(); //显示操作
	softwareInformation();
	cout << "\nEND\n";
	return 0;
}
