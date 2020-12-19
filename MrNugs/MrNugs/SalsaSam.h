//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class SalsaSam : public Unit
{
private:
	string name = "Salsa Sam";
	string type = "Enemy";
	string desc = "Salsa Sam has always wanted to learn to play the Sax.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"In My Eyes!",75,"AHH I got it in my eyes! Causes stun.", "Stun", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 75;
	int hp = maxhp;
	int maxmp = 150;
	int mp = maxmp;
	int dmg = 12;
	int def = 0;

	//Reward Values
	int gold = 55;
	int xp = 20;

	bool inEyes;


public:
	SalsaSam(int lvl);
	~SalsaSam();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
