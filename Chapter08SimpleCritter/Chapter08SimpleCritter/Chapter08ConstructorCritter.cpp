#include <iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0);
	~Critter();
	int m_Hunger;
	void Greet();

private:

};

Critter::Critter(int hunger)
{
	cout << "A new critter has been born!" << endl;
	m_Hunger = hunger;
}

Critter::~Critter()
{
}

void Critter::Greet()
{
	cout << "Hi. My hunger level is " << m_Hunger << endl;
}

class Monster
{
public:
	Monster(int hunger, int age, int tall);
	~Monster();
	int m_Hunger;
	int m_Age;
	int m_Tall;

private:

};

Monster::Monster(int hunger, int age, int tall):
	m_Hunger(hunger),
	m_Age(age),
	m_Tall(tall)
{
}

Monster::~Monster()
{
}

int main()
{
	Critter crit1(7);
	crit1.Greet();

	Monster mon1(100, 200, 300);
	cout << mon1.m_Hunger << mon1.m_Age << mon1.m_Tall << endl;

	return 0;
}