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

	vector<string> moves = {"Special", "Special2", "Special3"};
	vector<int> movesMPCost = {20,111502};
	vector<string> unlockedMoves = {"Special","Special2"};

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

	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			setdamage(getDMG() + weaponDamage + randomNumber(6, 2));
		}
		else if (attackName == "Special" && getMP() >= 20) {
			setdamage(getDMG() + weaponDamage + (2 * randomNumber(8, 4)));
			setMP(getMP() - 20);
		}
		else if (attackName == "Special2" && getMP() >= 111502) {
			setdamage(getDMG() + weaponDamage + (2 * randomNumber(8, 4)));
			setMP(getMP() - 20);
		}
		else {
			//Not enough MP
			setdamage(-1);
		}
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}

	vector<string> getMoves() {
		return unlockedMoves;
	}
	vector<int> getMovesMPCost() {
		return movesMPCost;
	}
};
