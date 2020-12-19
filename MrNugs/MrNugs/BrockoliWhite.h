//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class BrockoliWhite : public Unit
{
private:
	string name = "Brockoli White";
	string type = "Enemy";
	string desc = "Famous creator of the games Flashstrike and Stick Strike.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Syntax Error",75,"Error! You have too much HP. Lose some.", "None", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 200;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 85;
	int xp = 40;


public:
	BrockoliWhite(int lvl);
	~BrockoliWhite();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
