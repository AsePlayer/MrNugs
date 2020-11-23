#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Item.h"
#include <vector>
using namespace std;
class Player
{
private:
	string name;
	int lvl;
	int money;
	Weapon weapon = Weapon("default",0,"default constructor");
	vector<Item> items = {};
	//vector for items later
public:
	Player(string name, int lvl, Weapon weapon);
	~Player();

	string getName() {
		return name;
	}
	
	int getLVL() {
		return lvl;
	}

	Weapon getWeapon() {
		return weapon;
	}

	
};

