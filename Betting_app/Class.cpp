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









void League::create_schedule()
{
	int how_many = teams_vec.size();
	int how_many_2 = how_many;
	int team_one = -1;
	int team_two = how_many-1 ;
	int match_counter = 0;

	for (int i = 0; i< how_many - 1; i++)
	{
		team_one++;
		for (int j = 0; j < how_many_2 - 1; j++)
		{
			//cout << teams_vec[team_one] << " vs " << teams_vec[team_two] << endl;
			matches_vector[match_counter].m_team_one = teams_vec[team_one];
			matches_vector[match_counter].m_team_two = teams_vec[team_two];
			match_counter++;
			team_two--;
		}
		how_many_2--;
		team_two = how_many-1;
	}



}

League::League(int league_type, vector<string> teams_vec)
{
	this->league_type = league_type;
	this->teams_vec = teams_vec;
	create_schedule();



}