#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

void main_menu();
void second_menu(string n[], int t);
void turns(string n[], int& t);
void main_game(string n[], int t, int& c, int& ic, clock_t& d);
void score_0();
void score(string n[], int x, int t, int c, int ic, clock_t d);
void result(string n[], clock_t d_0, clock_t d_1, int c_0, int c_1);

int main()
{
	int x = 0, correct_0 = 0, correct_1 = 0, incorrect_0 = 0, incorrect_1 = 0;
	string nick[2];
	clock_t during_0 = 0, during_1 = 0;
	main_menu();//wyœwietlnie g³ównego menu
	cout << "Enter first player nick: "; cin >> nick[0];//wpisanie nicku pierwszego gracza
	cout << "Enter second player nick: "; cin >> nick[1];
	turns(nick, x);;//wpisanie iloœci tur
	main_menu();//wyœwietlnie g³ównego menu
	second_menu(nick, 0);//wyœwietlenie menu dla pierwszego gracza i odliczanie do startu gry
	main_game(nick, x, correct_0, incorrect_0, during_0);//dlaczego program wykonuje siê 8 razy za ka¿dym razem nie zale¿nie od podania liczby w fukncji turns?!
	second_menu(nick, 1);//wyœwietlenie menu dla drugiego gracza i odliczanie do startu gry
	main_game(nick, x, correct_1, incorrect_1, during_1);//dlaczego program wykonuje siê 8 razy za ka¿dym razem nie zale¿nie od podania liczby w fukncji turns?!
	score_0();
	score(nick, 0, x, correct_0, incorrect_0, during_0);
	score(nick, 1, x, correct_1, incorrect_1, during_1);
	result(nick, during_0, during_1, correct_0, correct_1);
	system("PAUSE");
	system("cls");
	cout << "THANKS FOR PLAYING SEE YOU SOON!" << endl;
	system("PAUSE");
}
void main_menu()
{
	cout << "===================================" << endl;
	cout << "====Select correct key the game====" << endl;
	cout << "===================================" << endl;
	return;
}
void turns(string n[], int& t)
{
	cout << n[0] << " and " << n[1] << " enter how many turns you want to play: ";
	if (!(cin >> t))
	{
		cout << n[0] << ", " << n[1] << " nice try." << endl;
		cout << "Get some help http://images.algebraden.com/algebra/big/difference-between-integers-and-natural-numbers.jpg " << endl;
		system("PAUSE");
		exit(0);
	}
	while (t <= 0)
	{
		system("cls");
		cout << n[0] << " ," << n[1] << " you can't enter negative number and zero!" << endl;
		cout << "Enter the number of turns one more time: ";
		cin >> t;
	}
	system("cls");
	return;
}
void second_menu(string n[], int t)
{
	cout << n[t] << " you must press the right key." << endl;
	cout << "Let's start the game " << n[t] << ", have fun!" << endl;
	system("PAUSE");
	system("cls");
	for (int i = 5; i > 0; i--)
	{
		cout << "Game will start in " << i << " seconds.";
		Sleep(1000);
		system("cls");
	}
	return;
}
void main_game(string n[], int t, int& c, int& ic, clock_t& d)
{
	int random;
	char r;
	srand(time(NULL));
	clock_t start = clock();
	for (int i = 0; i < t; i++)
	{
		random = rand() % 26 + 65;
		cout << "PRESS: " << char(random) << endl;
		cin >> r;
		system("cls");
		if (char(random) == char(toupper(r)))
		{
			c++;
		}
		else
		{
			ic++;
		}
	}
	d = (clock() - start) / 1000;
	return;
}
void score_0()
{
	cout << "=============" << endl;
	cout << "====SCORE====" << endl;
	cout << "=============" << endl;
}
void score(string n[], int x, int t, int c, int ic, clock_t d)
{
	cout << n[x] << "'s result:" << endl;
	cout << n[x] << " pressed " << c << " times correctly and " << ic << " times incorrectly." << endl;
	cout << "He needed " << d << " seconds to play " << t << " turns." << endl;
	cout << "His average time of one turn is " << d / t << " seconds." << endl << endl;
	return;
}
void result(string n[], clock_t d_0, clock_t d_1, int c_0, int c_1)
{
	if (c_0 > c_1)
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations " << n[0] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
	if (c_0 < c_1)
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations " << n[1] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
	else if (d_0 > d_1)
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations " << n[1] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
	else if (d_0 < d_1)
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations" << n[0] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
}