#pragma once
#include "Unit.h"
class Mage : public Unit
{
private:
	string name = "Mage";
	string type = "Enemy";
	int maxhp = 100;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxhp;
	int dmg = 10;
	int def = 0;

public:
	Mage();
	~Mage();


	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			damage = DMG + randomNumber(6, 0);
		}
		else if (attackName == "Special" && MP >= 75) {
			damage = (3 * DMG) + (2 * randomNumber(4, 8));
			MP -= 75;
		}
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}
};
