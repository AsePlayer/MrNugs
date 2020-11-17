#include "pch.h"
#include "Warrior.h"


Warrior::Warrior()
{
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


Warrior::~Warrior()
{
}
