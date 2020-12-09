#include "pch.h"
#include "NuggetGuard.h"


NuggetGuard::NuggetGuard(int lvl)
{
	//this->LVL = lvl;
	//setLVL(lvl);
	this->setLVL(lvl);
	int lvlModifier = lvl * .05f;

	this->setNAME(name);
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




NuggetGuard::~NuggetGuard()
{
}
