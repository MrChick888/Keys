#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

void main_menu();
void second_menu(string n);
void main_game(string n);


int main()
{
	string nick;

	main_menu();
	cout << "Enter your nick: ";
	cin >> nick;
	system("cls");
	main_menu();
	second_menu(nick);
	main_game(nick);


	system("PAUSE");
}
void main_menu()
{
	cout << "===================================" << endl;
	cout << "====Select correct key the game====" << endl;
	cout << "===================================" << endl;
}
void second_menu(string n)
{
	cout << n << " you must press the right key." << endl;
	cout << "Let's start the game " << n << ", have fun!" << endl;
	system("PAUSE");
	system("cls");
	for (int i = 5; i > 0; i--)
	{
		cout << "Game will start in " << i << " seconds.";
		Sleep(100);//1000
		system("cls");
	}
}
void main_game(string n)
{
	int t=0, random, correct=0, incorrect=0;
	char r;
	srand(time(NULL));
	cout << n << " enter how many turns you want to play: ";
	if (!(cin >> t))
	{
		cout << n << " nice try." << endl;
		cout << "Get some help http://images.algebraden.com/algebra/big/difference-between-integers-and-natural-numbers.jpg " << endl;
		system("PAUSE");
		exit(0);
	}
	while (t<=0)
	{
		system("cls");
		cout << n << " you can't enter negative number and zero!" << endl;
		cout << "Enter the number of turns one more time: ";
		cin >> t;
	}
	system("cls");
	clock_t start = clock();
	for (int i = 0; i < t; i++)
	{
		random = rand() % 26 + 65;
		cout << "PRESS: " << char(random) << endl;
		cin >> r;
		system("cls");
		if (char(random) == char(toupper(r)))
		{
			correct++;
		}
		else
		{
			incorrect++;
		}
	}
	system("cls");
	cout << "=============" << endl;
	cout << "====SCORE====" << endl;
	cout << "=============" << endl;

	cout << n << " you press " << correct << " times correctly and " << incorrect << " times incorrectly." << endl;
	cout << "You need " << (clock() - start) / 1000 << " seconds to play " << t << " turns." << endl;
	cout << "Your average time of one turn is " << ((clock() - start) / 1000) / t << " seconds.";
}

