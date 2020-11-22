#include "pch.h"
#include "Warrior.h"


Warrior::Warrior(Player *p)
{

	this->LVL = p->getLVL();

	
	this->lvl = p->getLVL();
	Weapon temp = p->getWeapon();
	this->weaponDamage = temp.getDamage();
	cout << "WEAPON TIME BAYBEEEEE " << weaponDamage << endl;

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
