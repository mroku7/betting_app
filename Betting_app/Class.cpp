#include "stdafx.h"
#include "Class.h"

using namespace std;




string Player::convert_for_save()
{
	
	string for_save = add_underscore(name);
	for_save.append(" ");
	for_save += to_string(score);
	
	return for_save;
}

Player::Player() {}
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

string Player::add_underscore(string text)
{
	for (int i = 0; i <= text.size(); i++)
		if (text[i] == ' ')
			text.replace(i, 1, "_");
	return text;
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
			matches asd;
			asd.m_team_one = teams_vec[team_one];
			asd.m_team_two = teams_vec[team_two];
			matches_vector.push_back(asd);
			team_two--;
		}
		how_many_2--;
		team_two = how_many-1;
	}
	int size = matches_vector.size();
	for (int i = 0; i < size; i++)
	{
		matches asd;
		asd.m_team_one = matches_vector[i].m_team_two;
		asd.m_team_two = matches_vector[i].m_team_one;
		matches_vector.push_back(asd);
	}
}

League::League(int league_type, vector<string> teams_vec, string custom_league_name)
{
	this->league_type = league_type;
	this->teams_vec = teams_vec;
	this->custom_league_name = custom_league_name;
	create_schedule();
}

string League::get_team_one(int nr)
{
	return matches_vector[nr].m_team_one;
}
string League::get_team_two(int nr)
{
	return matches_vector[nr].m_team_two;
}

int League::get_matches_number()
{
	return matches_vector.size();
}

int League::get_league_type()
{
	return league_type;
}

void League::save_schedule_to_file()
{
	string file_name;
	string name = Player::add_underscore(custom_league_name);


	if (league_type == 0)
	{
		file_name = "data\\leagues\\league_";
		file_name.append(name);
		file_name.append(".lig");
	}
	else if (league_type == 1)
	{
		file_name = "data\\leagues\\league_n_bracket_";
		file_name.append(name);
		file_name.append(".lig");
	}
	else if (league_type == 2)
	{
		file_name = "data\\leagues\\bracket_";
		file_name.append(name);
		file_name.append(".lig");
	}
	fstream save(file_name, ios::out | ios::app);
	string under_name;
	for (int i = 0; i < matches_vector.size(); i++)
	{
		under_name = add_underscore(matches_vector[i].m_team_one);
		save << under_name;
		save << " ";
		under_name = add_underscore(matches_vector[i].m_team_two);
		save << under_name;
		save << endl;
	}
	
	save.close();
}

