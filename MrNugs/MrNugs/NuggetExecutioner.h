//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class NuggetExecutioner : public Unit
{
private:
	string name = "Nugget Executioner";
	string type = "Enemy";
	string desc = "A strong and fearsome Nugget Executioner. Fun Fact: You're not his last scheduled execution for the day.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Execute",125,"A fierce finishing blow for any mere mortal, causing MASSIVE damage.", "None", 0}
	};
	vector<Special> unlockedMoves = { moves[0] };
	bool executed = false;
	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 300;
	int mp = maxmp;
	int dmg = 20;
	int def = 0;

	//Reward Values
	int gold = 100;
	int xp = 50;


public:
	NuggetExecutioner(int lvl);
	~NuggetExecutioner();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
