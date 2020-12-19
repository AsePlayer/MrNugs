//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
class ChipperChip : public Unit
{
private:
	string name = "Chipper Chip";
	string type = "Enemy";
	string desc = "A Chipper chap named Chip who's perfect to dip.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Sharp Edge",65,"Hey watch where you point that thing! Causes bleed.", "Bleed", 0},
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 125;
	int hp = maxhp;
	int maxmp = 220;
	int mp = maxmp;
	int dmg = 15;
	int def = 0;

	//Reward Values
	int gold = 65;
	int xp = 15;


public:
	ChipperChip(int lvl);
	~ChipperChip();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
