#pragma once
#include "Unit.h"
#include "Player.h"
class Warrior : public Unit
{
private:
	string name = "Warrior";
	string type = "Player";
	string desc = "This is a Warrior.";
	//Player specific things
	int lvl = 0;

	vector<Special> moves = 
	{ 
		Special{"Bloodshed",75,"Hack and slash at the enemy, causing major damage.","None",0}, 
		Special{"Shield Bash",25,"Forcefully bash the enemy with your shield with the chance of causing stun.","Stun",1}, 
		Special{"Bleed test",5,"Time to bleed, boi","Bleed",3} 
	};

	vector<Special> unlockedMoves = {moves[0], moves[1], moves[2]};
	vector<Item> items = {};
	Weapon weapon{ "Default",0,"Default Desc",0 };
	
	Player *player;
	int maxhp = 250;
	int hp = maxhp;
	int maxmp = 100;
	int mp = maxmp;
	int dmg = 20;
	int def = 10;

	//Reward Values
	int gold = 0;
	int xp = 0;
	
	

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
		else if (attackName == moves[1].getName() && getMP() >= moves[1].getMPCost()) {
			setdamage(getDMG() + weapon.getDamage() + (randomNumber(4, 3)));
			setMP(getMP() - moves[1].getMPCost());
		}
		else if (attackName == moves[2].getName() && getMP() >= moves[2].getMPCost()){
			setdamage(getDMG() + weapon.getDamage() + (randomNumber(4, 3)));
			setMP(getMP() - moves[2].getMPCost());
		}
		else {
			//Not enough MP
			setdamage(-1);
		}
	}

	vector<Special> getMoves() {
		return unlockedMoves;
	}

	vector<Item> getItems() {
		return items;
	}
	
	void removeItem(int num) {
		items.erase(items.begin() + num);
	}

	void setPlayerLVL(int lvl) {
		this->lvl = lvl;
	}

	void updatePlayer(int exp, int gold) {
		player->updateEXP(exp);
		*player =  {player->getName(),player->getLVL(),player->getWeapon(), player->getMoney() + gold, items, player->getCharacterClass(), player->getPosInStory()};
		//Player *h = new Player("Mr. Nugs", 3, Stick, {});
		
	}

};
