#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual Attack() const;

private:

protected:
	int* m_pDamage;
};

Enemy::Enemy(int damage)
{
	cout << "正在调用Enemy的构造函数.\n";
	m_pDamage = new int(damage);
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor, deleting m_pDamage.\n";
	delete m_pDamage;
	m_pDamage = 0;
}

void Enemy::Attack() const
{
	cout << "An enemy attacks and inflicts " << *m_pDamage << " damage points.\n";
}

class Boss : public Enemy
{
public:
	Boss(int multiplier = 2);
	virtual ~Boss();
	void virtual Attack() const;
	void virtual Taunt() const;//测试

private:

protected:
	int* m_pMultiplier;
};

Boss::Boss(int multiplier)
{
	cout << "正在调用Boss的构造函数。\n";
	m_pMultiplier = new int(multiplier);
}

Boss::~Boss()
{
	cout << "In Boss destructor, deleting m_pMultiplier.\n";
	delete m_pMultiplier;
	m_pMultiplier = 0;
}

void Boss::Attack() const
{
	cout << "A boss attacks and inflicts " << (*m_pDamage) * (*m_pMultiplier) << " damage points.\n";
}

void Boss::Taunt() const
{
	cout << "测试能否通过基类指针调用派生类的成员函数。\n";
}

int main()
{
	cout << "Calling Attack() on Boss object through pointer to Enemy:\n";
	Enemy* pBadGuy = new Boss();
	pBadGuy->Attack();
//	pBadGuy->Taunt();//无法通过基类指针调用派生类成员函数。

	cout << "Deleting pointer to Enemy:\n";
	delete pBadGuy;
	pBadGuy = 0;

	return 0;
}