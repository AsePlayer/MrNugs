//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class GuacamoleGuru : public Unit
{
private:
	string name = "Guacamole Guru";
	string type = "Enemy";
	string desc = "The Guacamole Guru knows all.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Pit Launch",100,"Launches Guacamole Guru's Pit. He's only got one, so make it count!", "None", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 200;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxmp;
	int dmg = 15;
	int def = 0;

	//Reward Values
	int gold = 55;
	int xp = 35;


public:
	GuacamoleGuru(int lvl);
	~GuacamoleGuru();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
