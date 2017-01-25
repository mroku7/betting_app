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
void loading_schedule_from_file(vector <League>&, int&);
string delete_underscore(string&);
int league_selection_menu();


int main()
{
	int player_counter = 0;
	int league_counter = 0;
	vector<Player> player_vector;
	vector<League> league_vector;
	loading_players_from_file(player_vector, player_counter);


	for (;;)
	{
		int main = main_menu();
		if (main == 0)
		{
			
		}
		else if (main == 1)
		{
			int league_type =league_selection_menu();
			if (league_type == 0)
			{
				string name;
				cout << "Jak chcesz nazwac ta nowa lige?" << endl;
				while (_kbhit())_getch();
				getline(cin, name);

				//reading teams
				int team_num = 0;
				string team;
				cout << "Podaj ilosc druzyn: ";
				while (_kbhit())_getch();
				while (!(cin >> team_num) || team_num % 2 != 0)
				{
					cin.clear();
					cin.ignore();
					cout << "Podaj poprawna wartosc. Pamietaj, ze liczba druzyn moze byc tylko parzysta." << endl;
					cout << "Podaj ilosc druzyn: ";
				}
				vector <string>teams_vec;
				system("CLS");
				if (cin)cin.get();
				for (int i = 0; i < team_num; i++)
				{
					cout << "Druzyna nr " << (i + 1) << ": ";
					getline(cin, team);
					teams_vec.push_back(team);
					cout << endl;
				}
				//new league in vector
				league_vector.push_back(League(league_type, teams_vec, name));
				league_counter++;
				league_vector[league_counter-1].save_schedule_to_file();
			}


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
	//you can easily add new option to menu just increase variable size and declare new menu string e.g. menu[4]= "new menu option"
	const int size = 4;
	string menu[size];
	menu[0] = "\t\t\t\t\t\tWybierz lige";
	menu[1] = "\t\t\t\t\t\tDodaj lige";
	menu[2] = "\t\t\t\t\t\tDodaj gracza";
	menu[3] = "\t\t\t\t\t\tWyjscie";

	HANDLE standart = GetStdHandle(STD_OUTPUT_HANDLE);
	short b = 0;
	for (;;)
	{
		system("CLS");
		for (int i = 0; i < size; i++)
		{
			if (i == b)
			{
				SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				continue;
			}
			cout << menu[i] << endl;
		}

		for (;;)
		{
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{	
				b += 1;
				if (b == size)
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
					b = (size-1);
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

int league_selection_menu()
{
	const int size = 4;
	string menu[size];
	menu[0] = "\t\t\t\t\t\t*Liga";
	menu[1] = "\t\t\t\t\t\t*Liga + puchar";
	menu[2] = "\t\t\t\t\t\t*Puchar";
	menu[3] = "\t\t\t\t\t\t Wstecz";

	HANDLE standart = GetStdHandle(STD_OUTPUT_HANDLE);
	short b = 0;
	for (;;)
	{
		system("CLS");
		cout << "\t\t\t\t\t\Wybierz rodzaj rozgrywek: " << endl;
		for (int i = 0; i < size; i++)
		{
			if (i == b)
			{
				SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(standart, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				continue;
			}
			cout << menu[i] << endl;
		}

		for (;;)
		{
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				b += 1;
				if (b == size)
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
					b = (size-1);
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
	if (count.is_open())
	{
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


}

void loading_schedule_from_file(vector <League>& league_vector, int& league_counter)
{


}

string delete_underscore(string &name)
{
	for (int i = 0; i <= name.size(); i++)
		if (name[i] == '_')
			name.replace(i, 1, " ");
	return name;
}