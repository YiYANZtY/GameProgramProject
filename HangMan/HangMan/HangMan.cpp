// HangMan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

int main()
{
	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";
	cout << "欢迎来到HangMan\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "还有" << (MAX_WRONG - wrong) << "次机会\n";
		cout << "已经猜过\0" << used << endl;
		cout << "目前为止是这个词： " << soFar << endl;

		char guess = 0;
		cout << "请输入一个字母：";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess) != string::npos)
		{
			cout << "你已经猜过这个字母了。\n";
			cout << "请输入一个字母：";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "正确\n";
			for (int i = 0; i < THE_WORD.size(); i++)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "错误！\n";
			++wrong;
		}
	}
	if (wrong >= MAX_WRONG)
	{
		cout << "Game Over!\n";
	}
	else
	{
		cout << "You win.\n";
	}
	cout << "The word was " << THE_WORD << endl;
	return 0;
}
