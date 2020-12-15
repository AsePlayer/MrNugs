#pragma once
#include "Unit.h"
class FriendlyNuggetGuard : public Unit
{
private:
	string name = "Friendly Nugget Guard";
	string type = "Ally";
	string desc = "This is a Nugget Guard.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Special",75,"mage special description", "None",0},
		Special{"mage Special2",500,"special description2", "None",0},
		Special{"mage Special3",1500,"special description3", "None",0} };
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
	FriendlyNuggetGuard(int lvl);
	~FriendlyNuggetGuard();

	void decideDamage(string attackName);
	string customAI(int HP);

};