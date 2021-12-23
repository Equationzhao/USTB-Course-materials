#pragma once

#include <graphics.h>

constexpr auto width = 530;
constexpr auto height = 600;
#ifndef PLANE
// IMAGE g_backGround;
IMAGE g_myPlane;
IMAGE g_enemy;
IMAGE g_bullet;
IMAGE g_explode;
int g_score = 0;

class bullet
{
private:
	int positionX_, positionY_;
public:
	// bool isFlying_;

	bullet( const bool isFlying = false ) : positionX_{0}, positionY_{0}
	{
		// isFlying_ = isFlying;
	}

	~bullet() = default;

	auto setPositionX( const int& x = 0 )
	{
		positionX_ = x;
	}

	auto setPositionY( const int& y )
	{
		positionY_ = y;
	}

	auto setPosition( const int& x = 0, const int& y = 0 )
	{
		positionX_ = x;
		positionY_ = y;
	}

	auto getPositionX() const
	{
		return positionX_;
	}

	auto getPositionY() const
	{
		return positionY_;
	}

	auto moveUp()
	{
		// if (rand() % 5 == 0)
		positionY_ -= 3;
	}
};

/**
 * \brief Player's Plane
 */
class MyPlane : public bullet
{
private:
	int positionX_, positionY_;
	bool isExploded_{false};
	// ReSharper disable once CppInconsistentNaming
	int HP_;
public:
	explicit MyPlane() : positionX_{0}, positionY_{0}, HP_{20}
	{
	}

	~MyPlane() = default;

	auto getPositionX() const
	{
		return positionX_;
	}

	auto getPositionY() const
	{
		return positionY_;
	}

	auto setPosition( const MOUSEMSG& m )
	{
		positionX_ = m.x;
		positionY_ = m.y;
	}

	auto setPosition( const int& x = 0, const int& y = 0 )
	{
		positionX_ = x;
		positionY_ = y;
	}

	auto setPositionX( const int& x = 0 )
	{
		positionX_ = x;
	}

	auto setPositionY( const int& y )
	{
		positionY_ = y;
	}

	auto changeHp( const int& hp )
	{
		HP_ = hp;
	}

	auto hpMinus()
	{
		HP_--;
		if (!HP_)
		{
			isExploded_ = true;
		}
	}

	auto reSetStatus()
	{
		isExploded_ = false;
		HP_ = 20;
	}

	auto getStatus() const
	{
		return !isExploded_;
	}

	auto getHp() const
	{
		return HP_;
	}
};

/**
 * \ brief enemy Plane
 */
class enemyPlane //: public bullet
{
private:
	int positionX_, positionY_;
	bool isExploded_{false};
	int HP_; //unused
	int speed_ = 1;
public:
	explicit enemyPlane() : positionX_{0}, positionY_{0}, HP_{1}, maxSpeed{2}
	{
	}

	~enemyPlane() = default;

	auto getPositionX() const
	{
		return positionX_;
	}

	auto getPositionY() const
	{
		return positionY_;
	}

	auto setPositionX( const int& x = 0 )
	{
		positionX_ = x;
	}

	auto setPositionY( const int& y )
	{
		positionY_ = y;
	}

	auto moveDown()
	{
		positionY_ += 1;
	}

	auto moveR()
	{
		if (positionX_ < width - 30)
		{
			positionX_ += 1;
		}
	}

	auto moveL()
	{
		if (positionX_ > 30)
		{
			positionX_ -= 1;
		}
	}

	auto randomMove()
	{
		switch (rand() % 3)
		{
		case 0:
			{
				for (int i = 0; i < speed_; i++)
				{
					this->moveDown();
				}
				break;
			}
		case 1:
			{
				for (auto i = 0; i < rand() % 5 * speed_; i++)
				{
					this->moveL();
				}
				break;
			}
		case 2:
			{
				for (auto i = 0; i < rand() % 5 * speed_; i++)
				{
					this->moveR();
				}
				break;
			}
		}
	}

	auto moveDownOnly()
	{
		for (auto i = 0; i < speed_; i++)
		{
			if (rand() % 8 == 0)
				this->moveDown();
		}
	}

	int maxSpeed;

	auto newPosition()
	{
		speed_ = 1 + rand() % maxSpeed;
		this->setPositionX(rand() % width);
		this->setPositionY(-30);
	}
};

#endif // !PLANE
