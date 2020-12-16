#pragma once
#include "Unit.h"
class NuggetGuard : public Unit
{
private:
	string name = "Nugget Guard";
	string type = "Enemy";
	string desc = "An aspiring Nugget Guard looking to move up in the ranks.";

	int lvl = 0;
	vector<Special> moves = 
	{ 
		Special{"Stab",75,"A fierce stab of a spear. Its damage varies wildly, depending on where you're stabbed.", "None", 0}, 
	};
	vector<Special> unlockedMoves = { moves[0] };

	int maxhp = 100;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 25;
	int xp = 10;
	

public:
	NuggetGuard(int lvl);
	~NuggetGuard();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
