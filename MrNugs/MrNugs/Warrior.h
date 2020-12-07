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

	vector<Special> moves = { Special{"Special",20,"special description"}, Special{"Special2",500,"special description2"}, Special{"Special3",1500,"special description3"} };
	vector<Special> unlockedMoves = {moves[0], moves[1]};
	vector<Item> items = { };
	
	Player *player;
	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxmp;
	int dmg = 20;
	int def = 10;

	Weapon weapon{ "Default",0,"Default Desc",0 };
	

public:
	Warrior(Player *p);
	~Warrior();

	void decideDamage(string attackName) {
		if (attackName == "Attack") {
			setdamage(getDMG() + weapon.getDamage() + randomNumber(6, 2));
		}
		else if (attackName == moves[0].getName() && getMP() >= moves[0].getMPCost()) {
			setdamage(getDMG() + weapon.getDamage() + (2 * randomNumber(8, 4)));
			setMP(getMP() - moves[0].getMPCost());
		}
		else if (attackName == "Special2" && getMP() >= moves[1].getMPCost()) {
			setdamage(getDMG() + weapon.getDamage() + (2 * randomNumber(8, 4)));
			setMP(getMP() - moves[1].getMPCost());
		}
		else {
			//Not enough MP
			setdamage(-1);
		}
	}

	vector<Special> getMoves() {
		return unlockedMoves;
	}

	void updatePlayer(int exp) {
		player->updateEXP(exp);
		*player = {player->getName(),player->getLVL(),player->getWeapon(), player->getMoney()};
		//Player *h = new Player("Mr. Nugs", 3, Stick, {});
		
	}

};
