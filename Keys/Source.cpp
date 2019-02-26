#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main_menu(string player_name[]);
void check_nick(string player_name[]);
void turns(string player_name[], int& turns_amount);
void second_menu(string player_name[], int number_of_player);
void main_game(int turns_amount, int number_of_player, int correct_points[], int incorrect_points[], clock_t game_time_player[]);
void score(string player_name[], int turns_amount, int correct_points[], int incorrect_points[], clock_t game_time_player[]);
void exit();

int main()
{
	int number_of_turns, correct_points[2] = { 0,0 }, incorrect_points[2] = { 0,0 };
	string nick[2];
	clock_t game_time_player[2];

	main_menu(nick);
	check_nick(nick);
	turns(nick, number_of_turns);
	second_menu(nick, 0);
	main_game(number_of_turns, 0, correct_points, incorrect_points, game_time_player);
	second_menu(nick, 1);
	main_game(number_of_turns, 1, correct_points, incorrect_points, game_time_player);
	score(nick, number_of_turns, correct_points, incorrect_points, game_time_player);
	exit();
}
void main_menu(string player_name[])
{
	cout << "===================================" << endl;
	cout << "====Select correct key the game====" << endl;
	cout << "===================================" << endl;
	cout << "Enter first player nick: "; cin >> player_name[0];
	cout << "Enter second player nick: "; cin >> player_name[1];
	return;
}
void check_nick(string player_name[])
{
	while (player_name[0] == player_name[1])
	{
		cout << "Player name can't be the same!" << endl;
		cout << "Enter second player nick again: ";
		cin >> player_name[1];
	}
	return;
}
void turns(string player_name[], int& turns_amount)
{
	cout << player_name[0] << " and " << player_name[1] << " enter how many turns you want to play: ";
	if (!(cin >> turns_amount))
	{
		cout << player_name[0] << ", " << player_name[1] << " nice try." << endl;
		cout << "Get some help http://images.algebraden.com/algebra/big/difference-between-integers-and-natural-numbers.jpg " << endl;
		system("PAUSE");
		exit(0);
	}
	while (turns_amount <= 0)
	{
		system("cls");
		cout << player_name[0] << " ," << player_name[1] << " you can't enter negative number and zero!" << endl;
		cout << "Enter the number of turns one more time: ";
		cin >> turns_amount;
	}
	system("cls");
	return;
}
void second_menu(string player_name[], int number_of_player)
{
	cout << "===================================" << endl;
	cout << "====Select correct key the game====" << endl;
	cout << "===================================" << endl;
	cout << player_name[number_of_player] << " you must press the right key." << endl;
	cout << "Let's start the game " << player_name[number_of_player] << ", have fun!" << endl;
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
void main_game(int turns_amount, int number_of_player, int correct_points[], int incorrect_points[], clock_t game_time_player[])
{
	int random_char;
	char entered_char;
	srand(time(NULL));
	clock_t start = clock();
	for (int i = 0; i < turns_amount; i++)
	{
		random_char = rand() % 26 + 65;
		cout << "PRESS: " << char(random_char) << endl;
		entered_char = getch();
		system("cls");
		if (char(random_char) == char(toupper(entered_char)))correct_points[number_of_player] ++;
		else incorrect_points[number_of_player] ++;
	}
	game_time_player[number_of_player] = clock() - start;
	return;
}
void score(string player_name[], int turns_amount, int correct_points[], int incorrect_points[], clock_t game_time_player[])
{
	cout << "=============" << endl;
	cout << "====SCORE====" << endl;
	cout << "=============" << endl;
	cout << player_name[0] << "'s result:" << endl;
	cout << player_name[0] << " pressed " << correct_points[0] << " times correctly and " << incorrect_points[0] << " times incorrectly." << endl;
	cout << "He needed " << setprecision(2) << (double)(game_time_player[0] / 1000) << " seconds to play " << turns_amount << " turns." << endl;
	cout << "His average time of one turn is " << setprecision(2) << (double)(game_time_player[0] / turns_amount) / 1000 << " seconds." << endl << endl;

	cout << player_name[1] << "'s result:" << endl;
	cout << player_name[1] << " pressed " << correct_points[1] << " times correctly and " << incorrect_points[1] << " times incorrectly." << endl;
	cout << "He needed " << setprecision(2) << (double)(game_time_player[1] / 1000) << " seconds to play " << turns_amount << " turns." << endl;
	cout << "His average time of one turn is " << setprecision(2) << (double)(game_time_player[1] / turns_amount) / 1000 << " seconds." << endl << endl;

	if (correct_points[0] > correct_points[1])
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations " << player_name[0] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
	if (correct_points[0] < correct_points[1])
	{
		cout << "==========================================================" << endl;
		cout << "Congratulations " << player_name[1] << " won!" << endl;
		cout << "==========================================================" << endl;
		return;
	}
	else
	{
		if (game_time_player[0] < game_time_player[1])
		{
			cout << "==========================================================" << endl;
			cout << "Congratulations " << player_name[0] << " won!" << endl;
			cout << "==========================================================" << endl;
			return;
		}
		else
		{
			cout << "==========================================================" << endl;
			cout << "Congratulations " << player_name[1] << " won!" << endl;
			cout << "==========================================================" << endl;
			return;
		}
	}
}
void exit()
{
	system("PAUSE");
	system("cls");
	cout << "THANKS FOR PLAYING SEE YOU SOON!" << endl;
	system("PAUSE");
}