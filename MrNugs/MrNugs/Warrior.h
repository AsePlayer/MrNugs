#pragma once
#include "Unit.h"
#include "Player.h"
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
	int weaponDamage = 0;

public:
	Warrior(Player *p);
	~Warrior();
	void setLVL(int level) {
		lvl = level;
	}
	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			damage = DMG + weaponDamage + randomNumber(6, 2);
		}
		else if (attackName == "Special" && MP >= 20) {
			damage = DMG + weaponDamage + (2 * randomNumber(8, 4));
			MP -= 20;
			cout << "LVL: " << lvl;
		}
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}
};
