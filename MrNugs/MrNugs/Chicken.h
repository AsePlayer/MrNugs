//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class Chicken : public Unit
{
private:
	string name = "The Maker";
	string type = "Enemy";
	string desc = "\"Where all Chicken Nuggets come. It's time to meet your maker.\".";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Piercing Screech", 50, "A screech so loud you have to cover your ears. Causes stun.", "Stun", 1},
		Special{"Scratch", 25, "A sharp claw scratches you, causing a lot of bleed damage.", "Bleed", 4},
		Special{"Peck", 65, "You'll notice a decently sized gap where some of your body used to be. Ouch!", "None", 0}
	};
	vector<Special> unlockedMoves = { moves[0], moves[1], moves[2] };

	int maxhp = 1000;
	int hp = maxhp;
	int maxmp = 500;
	int mp = maxmp;
	int dmg = 25;
	int def = 0;

	//Reward Values
	int gold = 1000;
	int xp = 100;

	bool screeched;


public:
	Chicken(int lvl);
	~Chicken();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
