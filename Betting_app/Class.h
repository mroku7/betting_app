#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Player
{
private:
	string name;
	int score;
	struct bets
	{
		string b_team_one;
		string b_team_two;
		unsigned int b_score_one;
		unsigned int b_score_two;
	};
public:
	string add_underscore(string);
	string convert_for_save();
	Player();
	Player(string);
	Player(string, int);
	string get_name();
	int get_score();
	void save_player_to_file();
};











class League:Player
{
private:
	string custom_league_name;
	int league_type;
	vector <string> teams_vec;
	int teams_number;
	struct matches
	{
		string m_team_one;
		string m_team_two;
		unsigned int m_score_one;
		unsigned int m_score_two;

	};
	vector <matches> matches_vector;
	void create_schedule();
public:
	League(int, vector<string>, string);
	string get_team_one(int);
	string get_team_two(int);
	int get_matches_number();
	void save_schedule_to_file();
	int get_league_type();


};






