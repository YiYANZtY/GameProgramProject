﻿// Chapter09GameLobby.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
	Player(const string& name = "");
	~Player();
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	string m_Name;
	Player* m_pNext;

};

Player::Player(const string& name):
	m_Name(name),
	m_pNext(0)
{
}

Player::~Player()
{
}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
};

Lobby::Lobby():
	m_pHead(0)
{
}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);
	/*If list is empty, make head of list this new player.*/
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	else /*Otherwise find the end of the list and add the player there.*/
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)
	{
		cout << "The game lobby is empty. No one to remove.\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;
	cout << "\nHere's who's in the game lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{
			os << pIter->GetName() << endl;
			pIter = pIter->GetNext();
		}
	}
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;
	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Good-Bye.\n";
			break;
		case 1:
			myLobby.AddPlayer();
			break;
		case 2:
			myLobby.RemovePlayer();
			break;
		case 3:
			myLobby.Clear();
			break;
		default:
			cout << "That was not a valid choice.\n";
			break;
		}
	} while (choice != 0);

	return 0;
}

