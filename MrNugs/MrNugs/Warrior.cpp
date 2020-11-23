#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(Player *p)
{

	this->setLVL(p->getLVL());
	
	Weapon temp = p->getWeapon();

	this->weaponDamage = temp.getDamage();

	this->setNAME(p->getName());
	this->setTYPE(type);
	this->setMAXHP(maxhp + (maxhp * (lvl * .1f)));
	this->setHP(hp + (hp * (lvl * .1f)));
	this->setMAXMP(maxmp + (maxmp * (lvl * .1f)));
	this->setMP(mp + (mp * (lvl * .1f)));
	this->setDMG(dmg + (dmg * (lvl * .1f)));

	this->setDEF(def * lvl);

	this->setdamage(0);
	
}


Warrior::~Warrior()
{
}
