#include "pch.h"
#include "NuggetGuard.h"


NuggetGuard::NuggetGuard(int lvl)
{
	//this->LVL = lvl;
	//setLVL(lvl);

	this->setLVL(lvl);

	this->setNAME(name);
	this->setTYPE(type);
	this->setDESC(desc);
	this->setGOLD(gold + (gold * ((lvl - 1) * .05f)));
	this->setXP(xp + (xp * ((lvl - 1) * .05f)));
	this->setMAXHP(maxhp + (maxhp * ((lvl - 1) * .05f)));
	this->setHP(hp + (hp * ((lvl - 1) * .05f)));
	this->setMAXMP(maxmp + (maxmp * ((lvl - 1) * .05f)));
	this->setMP(mp + (mp * ((lvl - 1) * .05f)));
	this->setDMG(dmg + (dmg * ((lvl - 1) * .05f)));

	this->setDEF(def * lvl);

	this->setdamage(0);
}




NuggetGuard::~NuggetGuard()
{
}
