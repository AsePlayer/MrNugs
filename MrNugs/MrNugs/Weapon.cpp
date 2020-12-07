#include "pch.h"
#include "Weapon.h"


Weapon::Weapon(string name, int damage, string description, int price)
{
	this->name = name;
	this->damage = damage;
	this->description = description;
	this->price = price;
}


Weapon::~Weapon()
{
}
