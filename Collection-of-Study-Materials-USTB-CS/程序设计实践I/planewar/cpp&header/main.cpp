#include <cmath>
#include <conio.h>
#include <ctime>
#include <graphics.h>
#include <thread>
#include <vector>

#include "Plane.h"
#pragma comment(lib,"Winmm.lib")
constexpr auto enemyNum = 1000;
int g_numRandom(2), g_numDownOnly(0), g_numRandomBase(0);
bool g_flag(false);
bool g_pause(false);
MyPlane myPlane;
MOUSEMSG* mouse = new MOUSEMSG;
std::vector<enemyPlane> enemy(enemyNum);
bullet g_bullets;
bool g_isFlying = false;
std::thread* t_clickMonitor;
std::thread* t_kbMonitor;
// std::vector<bullet> g_bullets;

/**
 * \brief This function generator the number of enemy planes which are move randomly.
 */
auto numInitial()
{
	g_numRandomBase = 1 + rand() % (enemyNum / 200);
	g_numDownOnly = 0;
}

/**
 * \brief This function initials the background music
 */
auto musicInitial()
{
	mciSendString(_T("open ./music/bgm.mp3 alias backGroudMusic"), nullptr, 0, nullptr);
	mciSendString(_T("play backGroudMusic repeat"), nullptr, 0, nullptr);
}

/**
 * \brief THis function initials the images
 */
auto imageInitial()
{
	initgraph(width, height);
	//loadimage(&g_backGround, _T("./picture/black.jpg"));
	loadimage(&g_myPlane, _T("./picture/plane.png"), 30, 30);
	loadimage(&g_enemy, _T("./picture/enemy.png"), 30, 30);
	loadimage(&g_bullet, _T("./picture/bullet.png"), 30, 30);
	loadimage(&g_explode, _T("./picture/explode.png"), 50, 50);
}

/**
 * \brief This function initials position of planes
 */
auto startMenu()
{
	IMAGE start;
	loadimage(&start, _T("./picture/start.png"), width, height);
	putimage(0, 0, &start);
	while (true)
	{
		*mouse = GetMouseMsg();
		if (mouse->mkLButton)
		{
			return;
		}
	}
}

auto positionInitial()
{
	myPlane.setPosition(0.5 * width, 0.8 * height);
	myPlane.bullet::setPositionX(myPlane.getPositionX());
	myPlane.bullet::setPositionY(-85);
	for (auto& i : enemy)
	{
		i.setPositionX(rand() % width);
	}
}

/**
 * \brief This function initials music&image&randomSeed
 */
auto initialization()
{
	srand(static_cast<unsigned>(time(nullptr)));
	musicInitial();
	imageInitial();
	startMenu();
	positionInitial();
	numInitial();
	myPlane.reSetStatus();
	g_score = 0;
}

/**
 * \brief This function draws images
 */
auto gameOver() -> void
{
	IMAGE over;
	loadimage(&over, _T("./picture/over.png"), width, height);
	BeginBatchDraw();
	putimage(0, 0, &over);
	putimage(myPlane.getPositionX() - 40, myPlane.getPositionY() - 40, &g_explode);
	outtextxy(0.38 * width, 0.6 * height, _T(" Click to restart"));
	FlushBatchDraw();
	if (mouse->mkLButton)
	{
		g_flag = false;
	}
}

auto display()
{
	cleardevice();
	BeginBatchDraw();
	//putimage(0, 0, &g_backGround);
	TCHAR scoreDisplay[100] = {'\0'};
	swprintf_s(scoreDisplay, _T("%d"), g_score);
	outtextxy(width * 0.02, height * 0.02, _T("Score:")); //显示
	outtextxy(width * 0.1, height * 0.02, scoreDisplay); //分数

	TCHAR hpDisplay[100] = {'\0'};
	swprintf_s(hpDisplay, _T("%d"), myPlane.getHp());
	outtextxy(width * 0.02, height * 0.06, _T("HP:")); //显示
	outtextxy(width * 0.07, height * 0.06, hpDisplay); //生命
	if (myPlane.getStatus())
	{
		//绘制己方飞机
		putimage(myPlane.getPositionX(), myPlane.getPositionY(), &g_myPlane);
		//绘制敌方飞机
		for (int i = 0; i < g_numRandom + g_numDownOnly; i++)
		{
			putimage(enemy[i].getPositionX(), enemy[i].getPositionY(), &g_enemy);
		}
		//绘制子弹
		if (g_isFlying)
		{
			putimage(g_bullets.getPositionX(), g_bullets.getPositionY(), &g_bullet);
		}
	}
	else
	{
		gameOver();
	}
	FlushBatchDraw();
	// Sleep(1);
}

/**
 * \brief This function is used to check enemy is hit or not.
 * \return While enemy is hit, function returns true,else return false.
 */
inline auto isHitEnemy()
{
	for (auto i = 0; i < g_numRandom + g_numDownOnly; i++)
	{
		if (fabs(g_bullets.getPositionX() - enemy[i].getPositionX()) +
			fabs(g_bullets.getPositionY() - enemy[i].getPositionY()) <= 20 && g_isFlying ||
			fabs(myPlane.getPositionX() - enemy[i].getPositionX()) + fabs(
				myPlane.getPositionY() - enemy[i].getPositionY()) <= 40)
		{
			return i;
		}
	}
	return -1;
}

/**
 * \brief This function is used to check Player is hit or not.
 * \return While player is hit, function returns true,else return false.
 */
inline auto isHitPlayer()
{
	for (int i = 0; i < enemyNum; i++)
	{
		if (fabs(enemy[i].getPositionX() - myPlane.getPositionX()) + fabs(
			enemy[i].getPositionY() - myPlane.getPositionY()) <= 60)
		{
			return i;
		}
	}
	return -1;
}

inline auto isHitBullet()
{
	for (auto i = 0; i < g_numRandom + g_numDownOnly; i++)
	{
		if (g_isFlying && fabs(g_bullets.getPositionX() - enemy[i].getPositionX()) +
			fabs(g_bullets.getPositionY() - enemy[i].getPositionY()) <= 20)
		{
			return true;
		}
	}
	return false;
}

[[noreturn]] auto clickMonitor()
{
	while (g_flag)
	{
		PeekMouseMsg(mouse);
		if (mouse->uMsg == WM_LBUTTONDOWN)
		{
			if (!g_isFlying)
			{
				g_isFlying = true;
			}
		}
	}
}

[[noreturn]] auto kbMonitor()
{
	while (true)
	{
		while (_kbhit() && !g_pause)
		{
			g_pause = true;
		}
	}
}

auto refreshStatus()
{
	if (myPlane.getStatus())
	{
		g_numDownOnly = g_score / 10;
		g_numRandom = g_numRandomBase + g_score / 20;
		int n1;
		if ((n1 = isHitEnemy()) >= 0) // 击中敌机或与之碰撞
		{
			if (isHitBullet())
			{
				g_isFlying = false;
			}
			bool collide(false);
			/*.
			* 若敌机碰撞我方,则不加分,敌机重启,我方生命-1
			*/
			if (isHitPlayer() > 0)
			{
				myPlane.hpMinus();
				collide = true;
			}

			enemy[n1].newPosition(); //重置敌机位置

			/*
			 * 子弹击中敌方,加分
			 */
			if (!collide)
			{
				g_score++;
				putimage(enemy[n1].getPositionX(), enemy[n1].getPositionY(), &g_explode);
			}
		}
		for (int i = 0; i < g_numRandom + g_numDownOnly; i++)
		{
			if (enemy[i].getPositionY() >= height)
			{
				enemy[i].newPosition();
			}
		}

		if (g_bullets.getPositionY() <= height)
		{
			g_isFlying = false;
		}
	}
}

auto refreshPosition()
{
	if (myPlane.getStatus())
	{
		myPlane.setPosition(mouse->x - 15, mouse->y - 15);
	}

	// for (int i = 0; i < g_numRandom; i++)
	// {
	// 	enemy[i].randomMove(); //随机运动
	// }

	for (int i = 0; i < g_numRandom + g_numDownOnly; i++) //g_numRandom
	{
		enemy[i].moveDownOnly(); //垂直运动
	}

	if (!g_isFlying)
	{
		g_bullets.setPosition(mouse->x - 15, mouse->y - 10);
	}
	g_bullets.moveUp();
}

auto refresh()
{
	refreshPosition();
	refreshStatus();
}

auto pause()
{
	BeginBatchDraw();
	outtextxy(width * 0.3, height * 0.5, _T("Pause, press any key to continue."));
	FlushBatchDraw();
}

auto run()
{
	t_clickMonitor = new std::thread(clickMonitor);
	t_kbMonitor = new std::thread(kbMonitor);
	while (g_flag)
	{
		while (true)
		{
			display(); //绘制图像
			if (!g_flag)
			{
				break;
			}
			if (g_pause) //g_pause是一个判断游戏是否暂停的bool型全局变量,初始化为false
			{
				pause();
				system("pause");
				g_pause = false;
			}
			refresh(); //刷新
		}
	}
}

auto main() -> int
{
	while (!g_flag)
	{
		g_flag = true;
		initialization(); // 初始化
		run();
	}
	delete t_clickMonitor;
	delete t_kbMonitor;
	delete mouse;
}
