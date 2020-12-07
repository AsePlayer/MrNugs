#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Item.h"
#include <vector>
#include <iostream>  
using namespace std;
class Player
{
private:
	string name;
	int lvl;
	int money;
	int exp;
	vector<int> expThresholds{0,10,50,100};
	Weapon weapon = Weapon("default",0,"default constructor", 0);
	vector<Item> items = {};
	//vector for items later
public:
	Player(string name, int lvl, Weapon weapon, int money);
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

	vector<Item> getItems() {
		return items;
	}

	int getMoney() {
		return money;
	}

	void setLVL(int lvl) {
		this->lvl = lvl;
	}

	void setWeapon(Weapon weapon) {
		this->weapon = weapon;
	}

	void setItems(vector<Item> items) {
		this->items = items;
	}

	void setMoney(int money) {
		this->money = money;
	}

	void updateEXP(int exp) {
		this->exp += exp;
		if (this->exp >= expThresholds[getLVL()]) {
			exp -= expThresholds[getLVL()];
			setLVL(getLVL() + 1);
			cout << endl << getName() << " leveled up! They are now level " << getLVL() << "!" << endl;
		}
	}

	
};

