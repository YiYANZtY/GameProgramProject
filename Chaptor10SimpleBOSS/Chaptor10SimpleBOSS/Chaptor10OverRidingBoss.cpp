#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	~Enemy();
	void virtual Taunt() const;//声明虚基类成员函数
	void virtual Attack() const;

private:
	int m_Damage;
};

Enemy::Enemy(int damage):
	m_Damage(damage)
{
}

Enemy::~Enemy()
{
}

void Enemy::Taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
	cout << "Attack! Inflicts " << m_Damage << " damage points.\n";
}

class Boss : public Enemy
{
public:
	Boss(int damage = 30);
	~Boss();
	void virtual Taunt() const;
	void virtual Attack() const;

private:

};

Boss::Boss(int damage):
	Enemy(damage)//调用基类构造函数
{
}

Boss::~Boss()
{
}

void Boss::Taunt() const//重写虚基类成员函数
{
	cout << "The boss says he will end your piriful existence.\n";
}

void Boss::Attack() const
{
	Enemy::Attack();//调用基类成员函数
	cout << " And laughs heartily at you.\n";
}

int main()
{
	cout << "Enemy object:\n";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();

	cout << "Boss object:\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();

	return 0;
}
