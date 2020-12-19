//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class Human : public Unit
{
private:
	string name = "The Behemoth";
	string type = "Enemy";
	string desc = "\"This is basically Attack on Titan for Chicken Nuggets.\".";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Consume", 100, "He just ate that Nugget in one bite! The horror!", "None", 0},
		Special{"Poke", 25, "His finger is so big it sends you flying! Causes stun.", "Stun", 4},
	};
	vector<Special> unlockedMoves = { moves[0], moves[1] };

	int maxhp = 2000;
	int hp = maxhp;
	int maxmp = 750;
	int mp = maxmp;
	int dmg = 100;
	int def = 0;

	//Reward Values
	int gold = 10000;
	int xp = 1000;

	bool poked;


public:
	Human(int lvl);
	~Human();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
