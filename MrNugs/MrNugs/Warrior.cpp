#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(Player *p)
{
	player = p;

	this->setLVL(p->getLVL());
	setPlayerLVL(p->getLVL());
	this->items = p->getItems();

	this->weapon = p->getWeapon();
	int lvlModifier = lvl * .05f;

	this->setNAME(p->getName());
	this->setTYPE(type);
	this->setDESC(desc);
	
	this->setGOLD(gold + (gold * lvlModifier));
	this->setXP(xp + (xp * lvlModifier));
	this->setMAXHP(maxhp + (maxhp * lvlModifier));
	this->setHP(hp + (hp * lvlModifier));
	this->setMAXMP(maxmp + (maxmp * lvlModifier));
	this->setMP(mp + (mp * lvlModifier));
	this->setDMG(dmg + (dmg * lvlModifier));



	this->setDEF(def * lvl);

	this->setdamage(0);
	
}


Warrior::~Warrior()
{
}
