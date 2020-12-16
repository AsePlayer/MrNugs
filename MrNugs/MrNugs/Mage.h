#pragma once
#include "Unit.h"
#include "Player.h"
class Mage : public Unit
{
private:
	string name = "Mage";
	string type = "Player";
	string desc = "The Mage is a crafty and dangerous fellow. The Mage can cause crippling damage to a target, inflict confusion, recover MP, and scale damage with MP.";
	//Player specific things
	int lvl = 0;

	vector<Special> moves =
	{
		Special{"Big damage", 100, "An enormous ball of raw, unfiltered energy. Damage scales with current MP." ,"None", 0},
		Special{"Drain Touch", 25, "Steal MP from an unsuspecting victim. MP gained scales with the victim's MAX MP.", "None", 0},
		Special{"Delerium", 5, "Confuses an enemy, resulting in them targeting anyone but you, including themself.", "Confusion", 1 + lvl / 10}
	};

	vector<Special> unlockedMoves = {};
	vector<Item> items = {};
	Weapon weapon{ "Default",0,"Default Desc",0 };

	Player *player;
	int maxhp = 150;
	int hp = maxhp;
	int maxmp = 250;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

	//Reward Values
	int gold = 0;
	int xp = 0;



public:
	Mage(Player *p);
	~Mage();

	void decideDamage(string attackName);

	vector<Special> getMoves();

	vector<Item> getItems();

	void removeItem(int num);

	void setPlayerLVL(int lvl);

	void updatePlayer(int exp, int gold);

	Player* getPlayer();

	void setWeapon(Weapon weapon);

};
