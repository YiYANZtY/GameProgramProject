#include <iostream>
using namespace std;

class Creature
{
public:
	Creature(int health = 100);
	~Creature();
	virtual void Greet() const = 0;//声明纯虚函数。
	virtual void DisplayHealth() const;

private:

protected:
	int m_Health;
};

Creature::Creature(int health):
	m_Health(health)
{
}

Creature::~Creature()
{
}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	~Orc();
	virtual void Greet() const;

private:

};

Orc::Orc(int health):
	Creature(health)
{
}

Orc::~Orc()
{
}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}

int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	Orc* aOrc = new Orc(130);
	aOrc->Greet();
	aOrc->DisplayHealth();

	return 0;
}
