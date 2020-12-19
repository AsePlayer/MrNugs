//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
#include "Player.h"
class Warrior : public Unit
{
private:
	string name = "Warrior";
	string type = "Player";
	string desc = "The Warrior paves the path with the corpses of all who dare test his might. The Warrior can cause intense damage to multiple enemies, inflict stun, and become stronger the more damaged he is.";
	//Player specific things
	int lvl = 0;

	vector<Special> moves = 
	{ 
		Special{"Bloodshed", 70,"Hack and slash at the enemy with two powerful swings, injuring anyone who dares stand in your way.","None", 0}, 
		Special{"Shield Bash", 25,"Strike the enemies head with an intense swipe of your shield. Chance to cause stun.","Stun", 1 + lvl/5}, 
		Special{"Last Stand", 100, "A lethal attack that becomes stronger the more damaged you are.", "None", 0} 
	};

	vector<Special> unlockedMoves = {};
	vector<Item> items = {};
	Weapon weapon{ "Default",0,"Default Desc",0 };
	
	Player *player;
	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 150;
	int mp = maxmp;
	int dmg = 20;
	int def = 10;

	//Reward Values
	int gold = 0;
	int xp = 0;
	
	

public:
	Warrior(Player *p);
	~Warrior();

	void decideDamage(string attackName);

	vector<Special> getMoves();

	vector<Item> getItems();
	
	void removeItem(int num);

	void setPlayerLVL(int lvl);

	void updatePlayer(int exp, int gold);

	Player* getPlayer();

	void setWeapon(Weapon weapon);

};
