/*
*Copyright (c) equationzhao All Rights Reserved.
*�汾�ţ� V1.1.1
*�����ˣ� equationzhao
*�������䣺equationzhao@foxmail.com
*����ʱ�䣺2021.3.31
*����ʱ�䣺2021.4.29 00:22:02
*������USTB�������ʵ������ҵ
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
 * brief �洢��Ҫ���ҵ��ַ���
 */
char strFind[100];
/**
 * brief line��size
 */
int lineNo(0);
/**
 * brief ���ڴ���file��ÿ�е��ַ���
 */
vector<string> textLine(50000); // NOLINT(clang-diagnostic-exit-time-destructors)
/**
 * brief ���ڴ洢ÿ����¼������
 */
vector<item> index; // NOLINT(clang-diagnostic-exit-time-destructors)

searchMap* searchMap::mainSearcher = new searchMap;

isChapterClass isChapter;
isPageClass isPage;

inline auto info() -> void
{
	cout << "���������鼮����ϵͳv1.0.1\n";
}

inline auto softwareInformation() -> void
{
	cout << "* Copyright (c) EquationZhao All Rights Reserved.\n"
	<< "* �汾�ţ� V1.1.1\n"
	<< "* �����ˣ� EquationZhao\n"
	<< "* �������䣺equationzhao@foxmail.com\n"
	<< "* ����ʱ�䣺20210331\n"
	<< "* ����ʱ�䣺2021.4.29 00:22:02\n"
	<< "* ������USTB�������ʵ������ҵ\n";
}

inline auto showInfo() -> void
{
	cout << "����\"search NAME\",��ѯΪ\"NAME\"������/����\n����\"goto N\",��ѯ��N����¼\n����\"exit\"�˳���ѯϵͳ\n"
	<< "ʹ��clear���������Ļ�ϵ�����\nʹ��help��������ʾ����ʾ\nʹ��info������ʾ��������Ϣ\nʹ��strictOn/strictOff��������/�ر��ϸ�ģʽ\n\n";
}

inline auto showRemind() -> void
{
	cout << "ע��:\n\t1.�벻Ҫ��û�в�ѯ��ʱʹ��goto,����ɴ���\n\t2.������Կո�����,����\"Harry Potter\"��\"Harry   Potter \"�ǲ�ͬ��\n"
	<< "\t3.�����Ĭ�Ϲر��ϸ�����ģʽ,�ڼ�������/����ʱӰ���С,���ڼ��������ַ���ʱ���ܴ������\n\t  ��Ҫ����/�ر��ϸ�ģʽ,��ʹ��strictOn/strictOff����\n";
}

/**
 * brief ��ʼ��,��ȡ�ļ�
 * ����ÿ�ж�Ӧ��ҳ����½ڴ���searchMap::mainSearcher
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
		int tempPage(0); //��¼����
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
 * brief ���vector ǰ������
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
 * brief ����
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
	cout << "��ѯ��ʱ" << (static_cast<double>(end) - static_cast<double>(start)) / 1000 << "��" << endl;
}

/**
 * brief ��ʾ����
 */
inline auto showTitle() -> void
{
	cout << left << "���" << "\t" << "����/����" << "\t\t" << "ҳ��" << "\t"
	<< setw(20) << "�½�" << "   \t" << "����" << endl;
}

/**
 * brief ������
 */
auto showOutcome() -> void
{
	system("cls");
	info();
	if (!item::getFound())
	{
		cout << "û�в�ѯ��~~" << endl;
		return;
	}
	showTitle();
	for (const auto& i : index)
	{
		i.output();
	}
	cout << "����ѯ��" << index.size() << "����¼" << endl;
}

/**
 * brief ���������Ƿ�Ϊ�Ϸ�����
 * param charNum �û���������ַ���ʽ�洢������
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
 * brief ǰ����N����¼
 * param n
 */
auto gotoRecord( const int& n ) -> void
{
	if (n > static_cast<int>(index.size()) || n == 0)
	{
		cout << "No existed record! :-(\n";
		return;
	}
	cout << "��" << n << "����¼" << endl;
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
 * brief չʾ�˵�
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
				gotoRecord(n); //��ת����n����¼
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
	SetConsoleTitle(L"���������鼮����ϵͳ");
	info(); //��ʾ�����������
	showInfo(); //��ʾ��������
	showRemind(); //��ʾע������
	initial(); //��ʼ�����ļ���Ϣ������vector<string>��
	showMenu(); //��ʾ����
	softwareInformation();
	cout << "\nEND\n";
	return 0;
}
