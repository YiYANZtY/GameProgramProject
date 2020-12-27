// Chapter10Blackjack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Card
{
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};//梅花，方片，红心，黑桃
	//重载<<运算符
	friend ostream& operator<<(ostream& os, const Card& aCard);
	//返回牌值1~11
	int GetValue() const;
	//将牌翻面
	void Flip();
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	~Card();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu):
	m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{
}

Card::~Card()
{
}

int Card::GetValue() const
{
	//如果牌面向下，则值为0
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
	void Add(Card* pCard);
	void Clear();
	//获得Hand中数值和，智能地处理A当作1或者11
	int GetTotal() const;
	Hand();
	virtual ~Hand();

protected:
	vector<Card*> m_Cards;

private:

};

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

int main()
{

	return 0;
}