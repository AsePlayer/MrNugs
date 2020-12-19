//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class AlanGrahamcracker : public Unit
{
private:
	string name = "Alan Graham-cracker";
	string type = "Enemy";
	string desc = "He draws pretty cool stuff I think.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Cursed Drawing",75,"Alan shows you a horrifying image that causes you to take damage. It's a picture of yourself.", "None", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 150;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxmp;
	int dmg = 15;
	int def = 0;

	//Reward Values
	int gold = 55;
	int xp = 30;


public:
	AlanGrahamcracker(int lvl);
	~AlanGrahamcracker();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
