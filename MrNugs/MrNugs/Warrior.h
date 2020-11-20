#pragma once
#include "Unit.h"
class Warrior : public Unit
{
private:
	string name = "Warrior";
	string type = "Player";
	//Player specific things
	int lvl = 0;

	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxmp;
	int dmg = 20;
	int def = 10;

public:
	Warrior(int lvl);
	~Warrior();
	void setLVL(int level) {
		lvl = level;
	}
	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			damage = DMG + randomNumber(6, 2);
		}
		else if (attackName == "Special" && MP >= 20) {
			damage = DMG + (2 * randomNumber(8, 4));
			MP -= 20;
			cout << "LVL: " << lvl;
		}
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}
};
