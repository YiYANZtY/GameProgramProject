// Chaptor10SimpleBOSS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Enemy
{
public:
	Enemy();
	~Enemy();
	int m_Damage;
	void Attack() const;

private:

};

Enemy::Enemy():
	m_Damage(10)
{
}

Enemy::~Enemy()
{
}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class BOSS : public Enemy
{
public:
	BOSS();
	~BOSS();
	int m_DamageMultiplier;
	void SpecialAttack() const;

private:

};

BOSS::BOSS():
	m_DamageMultiplier(3)
{
}

BOSS::~BOSS()
{
}

void BOSS::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();
	cout << "Creating a boss.\n";
	BOSS boss1;
	boss1.Attack();
	boss1.SpecialAttack();

	return 0;
}

