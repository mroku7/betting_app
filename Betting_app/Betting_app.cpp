// Betting_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Class.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>



using namespace std;


int main_menu();
bool add_player(vector<Player>&);
void loading_players_from_file(vector<Player>&, int&);
string delete_underscore(string&);


int main()
{
	int player_counter = 0;
	vector<Player> player_vector;
	loading_players_from_file(player_vector, player_counter);


	for (;;)
	{
		int main = main_menu();
		if (main == 0)
		{
			for (int i = 0; i < player_counter; i++)
			{
				cout << player_vector[i].get_name() << endl;
			}
			cin.get();
			cin.get();
		}
		else if (main == 1)
		{

		}
		else if (main == 2)
		{
			if (add_player(player_vector))
			{
				player_vector[player_counter].save_player_to_file();
				player_counter++;
			}
		}
		else if (main == 3)
		{
			return 0;
		}

	}
	
	
	
    
}


int main_menu()
{
	HANDLE standart = GetStdHandle(STD_OUTPUT_HANDLE);
	short b = 0;
	for (;;)
	{
		if (b == 0)
		{
			system("CLS");
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tWybierz lige" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tDodaj lige" << endl;
			cout << "\t\t\t\t\t\tDodaj gracza" << endl;
			cout << "\t\t\t\t\t\tWyjscie" << endl;
		}
		if (b == 1)
		{
			system("CLS");
			system("Color 0F");
			cout << "\t\t\t\t\t\tWybierz lige" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tDodaj lige" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tDodaj gracza" << endl;
			cout << "\t\t\t\t\t\tWyjscie" << endl;
		}
		if (b == 2)
		{
			system("CLS");
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tWybierz lige" << endl;
			cout << "\t\t\t\t\t\tDodaj lige" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tDodaj gracza" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tWyjscie" << endl;
		}
		if (b == 3)
		{
			system("CLS");
			cout << "\t\t\t\t\t\tWybierz lige" << endl;
			cout << "\t\t\t\t\t\tDodaj lige" << endl;
			cout << "\t\t\t\t\t\tDodaj gracza" << endl;
			SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\tWyjscie" << endl;
		}
		for (;;)
		{
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{	
				b += 1;
				if (b == 4)
				{
					b = 0;
					break;
				}
				break;
			}
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				b -= 1;
				if (b == -1)
				{
					b = 3;
					break;
				}
				break;
			}
			if (GetAsyncKeyState(VK_RETURN) & 1)
			{
				while (_kbhit())_getch();
				return b;
			}
		}
	}
}


bool add_player(vector<Player> &player_vector)
{
	HANDLE standart = GetStdHandle(STD_OUTPUT_HANDLE);

	string name;
	string comp_name;
	system("CLS");
	cout << "Podaj login gracza: ";
	getline(cin, name);	
	
	for (int i = 0; i < player_vector.size(); i++)
	{
		comp_name = player_vector[i].get_name();
		if (name.compare(comp_name) == 0)
		{
			cout << endl;
			cout << "Wybrany login jest zajety." << endl;
			cout << "Nie dodano nowego gracza.";
			Sleep(2000);
			return false;
		}
	}
	player_vector.push_back(Player(name));
	cout << "Gracz ";
	SetConsoleTextAttribute(standart, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << name;
	SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << " pomyslnie dodany do ligi.";
	Sleep(2000);
	return true;
}


void loading_players_from_file(vector<Player> &player_vector, int &player_counter)
{
	string test;
	string name;
	int score;
	fstream count("data\\players.dab", ios::in);
	while (!count.eof())
	{
		getline(count, test);
		player_counter++;
	}
	player_counter--;
	count.close();
	fstream open("data\\players.dab", ios::in);
	for (int i = 0; i < player_counter; i++)
	{
		open >> name;
		delete_underscore(name);
		open >> score;
		player_vector.push_back(Player(name, score));
	}
	open.close();



}

string delete_underscore(string &name)
{
	for (int i = 0; i <= name.size(); i++)
		if (name[i] == '_')
			name.replace(i, 1, " ");
	return name;
}