//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class FriendlyNuggetGuard : public Unit
{
private:
	string name = "Friendly Nugget Guard";
	string type = "Ally";
	string desc = "A Nugget Guard who's decided to team up with you. Who would've thought?";

	int lvl = 0;
	vector<Special> moves = 
	{ 
		Special{"Stab",75,"A fierce stab of a spear. Its damage varies wildly, depending on where you're stabbed.", "None", 0}, 
	};

	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 300;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 25;
	int xp = 10;


public:
	FriendlyNuggetGuard(int lvl);
	~FriendlyNuggetGuard();

	void decideDamage(string attackName);
	string customAI(int HP);

};
