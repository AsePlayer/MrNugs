#pragma once
#include "Unit.h"
class Warrior : public Unit
{
private:
	string name = "Warrior";
	string type = "Player";
	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxhp;
	int dmg = 20;
	int def = 10;

public:
	Warrior();
	~Warrior();

	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			damage = DMG + randomNumber(6, 2);
		}
		else if (attackName == "Special" && MP >= 20) {
			damage = DMG + (2 * randomNumber(8, 4));
			MP -= 20;
		}
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}
};
