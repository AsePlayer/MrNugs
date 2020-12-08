#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(Player *p)
{
	player = p;

	this->setLVL(p->getLVL());
	setPlayerLVL(p->getLVL());
	this->items = p->getItems();
	cout << endl << endl << p->getItems().size() << endl << endl;
	this->weapon = p->getWeapon();

	this->setNAME(p->getName());

	this->setTYPE(type);
	this->setMAXHP(maxhp + (maxhp * (lvl * .05f)));
	this->setHP(hp + (hp * (lvl * .05f)));
	this->setMAXMP(maxmp + (maxmp * (lvl * .05f)));
	this->setMP(mp + (mp * (lvl * .05f)));
	this->setDMG(dmg + (dmg * (lvl * .05f)));

	this->setDEF(def * lvl);

	this->setdamage(0);
	
}


Warrior::~Warrior()
{
}
