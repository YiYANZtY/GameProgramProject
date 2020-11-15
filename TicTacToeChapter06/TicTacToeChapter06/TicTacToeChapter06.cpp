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
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
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

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);
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

void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

char winner(const vector<char>& board)
{
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
									 {3, 4, 5},
									 {6, 7, 8},
									 {0, 3, 6},
									 {1, 4, 7},
									 {2, 5, 8},
									 {0, 4, 8},
									 {2, 4, 6} };
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
			 (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			 (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][2]]) )
		{
			return board[WINNING_ROWS[row][0]];
		}
		if (count(board.begin(), board.end(), EMPTY) == 0)
		{
			return TIE;
		}
	}
	return NO_ONE;
}

inline bool isLegal(const vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("输入你想落子的地方：", (board.size() - 1));
	while (!isLegal(board, move))
	{
		cout << "\n傻逼那里已经有子了。\n";
		move = askNumber("输入你想落子的地方：", (board.size() - 1));
	}
	return move;
}

int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;//why unsigned int
	bool found = false;
	//if computer can win on next move, that's the move to make
	while (!found && move < board.size())
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
		{
			move++;
		}
	}
	//otherwise, if human can win on next move, that's the move to make
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				move++;
			}
		}
	}
	//otherwise, moving to the best open square is the move to make
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(board, move))
			{
				found = true;
			}
			++i;
		}
	}
	cout << "我走这一步：" << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << "我赢了，你是无法击败AI的！\n";
	}
	else if (winner == human)
	{
		cout << "你赢了。不可能！一定是你欺骗了我，我发誓没有下次了，人类。\n";
	}
	else
	{
		cout << "幸运的人类，你知道赢不了我的，这是最好的结果了。\n";
	}
}