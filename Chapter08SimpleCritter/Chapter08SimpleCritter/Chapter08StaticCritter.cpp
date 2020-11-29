#include <iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0);
	~Critter();
	static int s_Total;
	static int GetTotal();

private:
	int m_Hunger;

};

int Critter::s_Total = 0;

Critter::Critter(int hunger):
	m_Hunger(hunger)
{
	cout << "A critter has been born!" << endl;
	s_Total++;
}

Critter::~Critter()
{
}

int Critter::GetTotal()
{
	return s_Total;
}

int main()
{
	cout << "The total number of critters is: " << Critter::s_Total << endl;
	Critter crit1, crit2, crit3;
	cout << "The total number of critters is: " << Critter::GetTotal() << endl;

	return 0;
}