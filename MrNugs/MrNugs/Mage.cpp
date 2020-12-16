#include "pch.h"
#include "Mage.h"


Mage::Mage(Player *p)
{
	player = p;

	this->setLVL(p->getLVL());
	setPlayerLVL(p->getLVL());
	this->items = p->getItems();

	this->weapon = p->getWeapon();

	this->setNAME(p->getName());
	this->setTYPE(type);
	this->setDESC(desc);
	this->setGOLD(gold);
	this->setXP(xp);
	this->setMAXHP(maxhp + (maxhp * ((lvl - 1) * .05f)));
	this->setHP(hp + (hp * ((lvl - 1) * .05f)));
	this->setMAXMP(maxmp + (maxmp * ((lvl - 1) * .05f)));
	this->setMP(mp + (mp * ((lvl - 1) * .05f)));
	this->setDMG(dmg + (dmg * ((lvl - 1) * .05f)));

	this->setDEF(def * lvl);
	this->setdamage(0);

	if (getLVL() > 0) {
		unlockedMoves.push_back(moves[0]);
	}
	if (getLVL() > 3) {
		unlockedMoves.push_back(moves[1]);
	}
	if (getLVL() > 6) {
		unlockedMoves.push_back(moves[2]);
	}

}

void Mage::decideDamage(string attackName) {
	if (attackName == "Attack") {
		setdamage(getDMG() + weapon.getDamage() + randomNumber(6, 2));
	}
	else if (attackName == moves[0].getName() && getMP() >= (moves[0].getMPCost())) {
		setdamage(getDMG() + (weapon.getDamage()) + ((getMP() / 50) * randomNumber(3, 10)));
		setMP(getMP() - (moves[0].getMPCost()));
	}
	else if (attackName == moves[1].getName() && getMP() >= moves[1].getMPCost()) {
		setdamage(getDMG() + weapon.getDamage() + (randomNumber(9, 6)));
		setMP(getMP() - moves[1].getMPCost());
	}
	else if (attackName == moves[2].getName() && getMP() >= moves[2].getMPCost()) {
		setdamage(getDMG() + weapon.getDamage() + (randomNumber(4, 3)));
		setMP(getMP() - moves[2].getMPCost());
	}
	else {
		//Not enough MP
		setdamage(-1);
	}
}

vector<Special> Mage::getMoves() {
	return unlockedMoves;
}

vector<Item> Mage::getItems() {
	return items;
}

void Mage::removeItem(int num) {
	items.erase(items.begin() + num);
}

void Mage::setPlayerLVL(int lvl) {
	this->lvl = lvl;
}

void Mage::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}

void Mage::updatePlayer(int exp, int gold) {
	player->updateEXP(exp);
	*player = { player->getName(),player->getLVL(),player->getWeapon(), player->getMoney() + gold, items, player->getCharacterClass(), player->getPosInStory() };
	//Player *h = new Player("Mr. Nugs", 3, Stick, {});

}

Player* Mage::getPlayer() {
	return player;
}


Mage::~Mage()
{
}
