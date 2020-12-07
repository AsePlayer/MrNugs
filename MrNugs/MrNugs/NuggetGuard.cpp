#include "pch.h"
#include "NuggetGuard.h"


NuggetGuard::NuggetGuard(int lvl)
{
	//this->LVL = lvl;
	//setLVL(lvl);

	this->setLVL(lvl);

	this->setNAME(name);
	this->setTYPE(type);
	this->setMAXHP(maxhp + (maxhp * (lvl * .1f)));
	this->setHP(hp + (hp * (lvl * .1f)));
	this->setMAXMP(maxmp + (maxmp * (lvl * .1f)));
	this->setMP(mp + (mp * (lvl * .1f)));
	this->setDMG(dmg + (dmg * (lvl * .1f)));

	this->setDEF(def * lvl);

	this->setdamage(0);
}




NuggetGuard::~NuggetGuard()
{
}
