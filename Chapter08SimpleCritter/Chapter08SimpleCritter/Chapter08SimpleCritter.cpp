// Chapter08SimpleCritter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Critter
{
public:
	Critter();
	~Critter();
	int m_Hunger;
	void Greet();

private:

};

Critter::Critter()
{
}

Critter::~Critter()
{
}

void Critter::Greet()
{
	cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << endl;
}

int main()
{
	Critter crit1;
	Critter crit2;
	crit1.m_Hunger = 9;
	crit2.m_Hunger = 3;
	crit1.Greet();
	crit2.Greet();
	return 0;
}

