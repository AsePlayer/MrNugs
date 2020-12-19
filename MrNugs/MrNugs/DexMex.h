//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class DexMex : public Unit
{
private:
	string name = "Dex-Mex";
	string type = "Enemy";
	string desc = "Famous creator of the hit game Blurpz.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Bad Beans",75,"I think there was something in those beans... Causes poison", "Poison", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 150;
	int hp = maxhp;
	int maxmp = 150;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 55;
	int xp = 30;


public:
	DexMex(int lvl);
	~DexMex();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
