//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Unit.h"
#include "Player.h"
class Thief : public Unit
{
private:
	string name = "Thief";
	string type = "Player";
	string desc = "The Thief is a cunning and deceptive adversary. The Thief can cause bleeding and poison damage to a target, steal gold and items, and steal HP.";
	//Player specific things
	int lvl = 0;

	vector<Special> moves =
	{
		Special{"Steal", 25, "Rob your enemy of extra gold, (and in rare cases, items) while dealing moderate damage.", "None", 0},
		Special{"Transfix", 50, "Pierce your enemy with a sharp blade, inflicting the bleeding status effect." ,"Bleed", 2 + lvl/5},
		Special{"Toxic Fangs", 25, "Steal a portion of your enemies HP. Causes the poison status effect.", "Poison", 1}
	};

	vector<Special> unlockedMoves = {};
	vector<Item> items = {};
	Weapon weapon{ "Default",0,"Default Desc",0 };

	Player *player;
	int maxhp = 150;
	int hp = maxhp;
	int maxmp = 150;
	int mp = maxmp;
	int dmg = 20;
	int def = 0;

	//Reward Values
	int gold = 0;
	int xp = 0;



public:
	Thief(Player *p);
	~Thief();

	void decideDamage(string attackName);

	vector<Special> getMoves();

	void addItems(Item item);


	vector<Item> getItems();

	void removeItem(int num);

	void setPlayerLVL(int lvl);

	void updatePlayer(int exp, int gold);

	Player* getPlayer();

	void setWeapon(Weapon weapon);

};
