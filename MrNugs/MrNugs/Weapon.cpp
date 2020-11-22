#include "pch.h"
#include "Weapon.h"


Weapon::Weapon(string name, int damage, string description)
{
	this->name = name;
	this->damage = damage;
	this->description = description;
}


Weapon::~Weapon()
{
}
