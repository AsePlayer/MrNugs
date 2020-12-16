#pragma once
#include "Unit.h"
class DinoNuggetRider : public Unit
{
private:
	string name = "Dino Nugget Rider";
	string type = "Enemy";
	string desc = "A skilled Nugget Guard riding a tamed Dino Nugget.";

	int lvl = 0;
	vector<Special> moves =
	{
		Special{"Bite",50,"A Dino Nugget's Bite rarely leaves its prey unscathed. Causes bleed.", "Bleed", 2},
		Special{"Tail Swipe",75,"A flick of the Dino Nugget's tail can send you flying! Causes stun.", "Stun", 1},
		Special{"Spear Throw",25,"The Dino Nugget Rider's aim is tried and true.", "None", 0}
	};
	vector<Special> unlockedMoves = { moves[0], moves[1], moves[2] };

	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 300;
	int mp = maxmp;
	int dmg = 20;
	int def = 0;

	//Reward Values
	int gold = 250;
	int xp = 25;


public:
	DinoNuggetRider(int lvl);
	~DinoNuggetRider();

	vector<Special> getMoves();
	void decideDamage(string attackName);
	string customAI(int HP);

};
