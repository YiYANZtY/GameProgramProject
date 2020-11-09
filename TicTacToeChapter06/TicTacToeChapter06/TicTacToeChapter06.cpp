// TicTacToeChapter06.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* Global constants */
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

/* Function prototypes */
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<string>& board);
char winner(const vector<string>& board);
bool isLegal(const vector<string>& board, int move);
int humanMove(const vector<string>& board, char human);
int computerMove(vector<string>& board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);
	return 0;
}

void instructions()
{
	cout << "欢迎来到井字棋游戏！\n";
	cout << "输入0—8来控制你落子的位置，对应棋盘的位置如图所示：\n";
	cout << "0 | 1 | 2\n";
	cout << "---------\n";
	cout << "3 | 4 | 5\n";
	cout << "---------\n";
	cout << "6 | 7 | 8\n";
	cout << "对弈即将开始！\n";
}

char askYesNo(string question) 
{
	char response;
	do
	{
		cout << question << " (y/n):";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int askNumber(string question, int high, int low = 0)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number >= high || number <= low);
	return number;
}

char humanPiece()
{
	char goFirst = askYesNo("你想先走吗？");
	if (goFirst == 'y')
	{
		cout << "\n那你先走。\n";
		return X;
	}
	else
	{
		cout << "\n那我先走了。\n";
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const vector<string>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
}