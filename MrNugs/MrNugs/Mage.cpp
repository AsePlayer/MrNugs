#include "pch.h"
#include "Mage.h"


Mage::Mage(int lvl)
{
	this->LVL = lvl;
	setLVL(lvl);
	this->NAME = name;
	this->TYPE = type;
	this->MAXHP = maxhp;
	this->HP = hp;
	this->MAXMP = maxmp;
	this->MP = mp;
	this->DMG = dmg;
	this->DEF = def;

	this->damage = 0;
}




Mage::~Mage()
{
}
