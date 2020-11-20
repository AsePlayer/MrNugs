#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(int lvl)
{
	this->LVL = lvl;
	setLVL(lvl);
	this->NAME = name;
	this->TYPE = type;
	this->MAXHP = maxhp + (maxhp * (lvl * .1f));
	this->HP = hp		+ (hp * (lvl * .1f));
	this->MAXMP = maxmp + (maxmp * (lvl * .1f));
	this->MP = mp		+ (mp * (lvl * .1f));
	this->DMG = dmg		+ (dmg * (lvl * .1f));

	this->DEF = def * lvl;

	this->damage = 0;
	
}


Warrior::~Warrior()
{
}
