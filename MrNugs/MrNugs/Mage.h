#pragma once
#include "Unit.h"
class Mage : public Unit
{
private:
	string name = "Mage";
	string type = "Enemy";
	int lvl = 0;
	int maxhp = 100;
	int hp = maxhp;
	int maxmp = 200;
	int mp = maxmp;
	int dmg = 10;
	int def = 0;

public:
	Mage(int lvl);
	~Mage();

	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			setdamage(getDMG() + randomNumber(5, 2));
		}
		else if (attackName == "Special" && getMP() >= 75) {
			setdamage((3 * getDMG()) + (2 * randomNumber(6, 4)));
			setMP(getMP()- 75);
		}
	}
	 string customAI(int HP) {
		//cout << endl << "DEFAULT AI" << endl;
		if (randomNumber(4, 0) == 0 && getMP() >= 75) {
			decideDamage("Special");
			cout << "Special";
			return "Special";
		}
		else {
			decideDamage("Attack");
			return "Attack";
		}
		
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}
};
