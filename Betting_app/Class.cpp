#include "stdafx.h"
#include "Class.h"

using namespace std;


string Player::convert_for_save()
{
	string name_s = name;
	for (int i = 0; i <= name_s.size(); i++)
		if (name_s[i] == ' ')
			name_s.replace(i, 1, "_");
	string for_save;
	for_save.append(name_s);
	for_save.append(" ");
	for_save += to_string(score);




	return for_save;
}

Player::Player(string name)
{
	this->name = name;
	score = 0;
}
Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
}

string Player::get_name()
{
	return name;
}

int Player::get_score()
{
	return score;
}

void Player::save_player_to_file()
{
	fstream save("data\\players.dab", ios::out | ios::app);
	save << convert_for_save();
	save << endl;
	save.close();




}