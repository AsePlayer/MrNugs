#pragma once
#include "Unit.h"
#include "Player.h"
class Archer : public Unit
{
private:
	string name = "Archer";
	string type = "Player";
	string desc = "The Archer's cause is just and his aim is true. The Archer can cause major damage to a target, afflict a random status effect, and rain arrows upon all on the battlefield.";
	//Player specific things
	int lvl = 0;

	vector<Special> moves =
	{
		Special{"Critical Strike", 75, "Pierce thy enemies heart. Or something else important. Either way, it's gonna hurt." , "None", 0},
		Special{"Arrow of ???", 55, "Shoot the enemy with a random arrow, causes a random status effect.", "None", 1 + lvl / 5},
		Special{"Arrow Rain", 100, "Rain a volley of arrows upon all of your enemies!", "None", 1}
	};

	vector<Special> unlockedMoves = {};
	vector<Item> items = {};
	Weapon weapon{ "Default",0,"Default Desc",0 };

	Player *player;
	int maxhp = 200;
	int hp = maxhp;
	int maxmp = 175;
	int mp = maxmp;
	int dmg = 15;
	int def = 0;

	//Reward Values
	int gold = 0;
	int xp = 0;



public:
	Archer(Player *p);
	~Archer();

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
