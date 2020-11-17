#include <iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0);
	~Critter();
	int GetHunger() const;
	void SetHunger(int hunger);

private:
	int m_Hunger;
};

Critter::Critter(int hunger):
	m_Hunger(hunger)
{
	cout << "A new critter has been born!" << endl;
}

Critter::~Critter()
{
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
	if (hunger < 0)
	{
		cout << "You can't set a critter's hunger to a negative number." << endl;
	}
	else
	{
		m_Hunger = hunger;
	}
}

int main()
{
	Critter crit1(5);
	cout << crit1.GetHunger() << endl;
	crit1.SetHunger(-1);
	crit1.SetHunger(9);
	cout << crit1.GetHunger() << endl;

	return 0;
}