//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class JasonWhitHAM : public Unit
{
private:
	string name = "Jason WhitHAM";
	string type = "Enemy";
	string desc = "\"It's pronounced Wittem.\".";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Cease and Desist",55,"Takes gold from the target, increasing his overall gold worth.", "None", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 100;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 250;
	int xp = 40;


public:
	JasonWhitHAM(int lvl);
	~JasonWhitHAM();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
