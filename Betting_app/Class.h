#pragma once
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class Player
{
private:
	string name;
	int score;
	string convert_for_save();
public:
	Player(string);
	Player(string, int);
	string get_name();
	int get_score();
	void save_player_to_file();
};

