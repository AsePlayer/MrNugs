#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(Player *p)
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
	this->setMAXHP(maxhp + (maxhp * ((lvl-1) * .05f)));
	this->setHP(hp + (hp * ((lvl-1) * .05f)));
	this->setMAXMP(maxmp + (maxmp * ((lvl-1) * .05f)));
	this->setMP(mp + (mp * ((lvl-1) * .05f)));
	this->setDMG(dmg + (dmg * ((lvl-1) * .05f)));





	this->setDEF(def * lvl);

	this->setdamage(0);
	
}


Warrior::~Warrior()
{
}
