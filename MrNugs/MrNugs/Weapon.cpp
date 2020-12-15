#include "pch.h"
#include "Weapon.h"


Weapon::Weapon(string name, int damage, string description, int price)
{
	this->name = name;
	this->damage = damage;
	this->description = description;
	this->price = price;
}

string Weapon::getName() {
	return name;
}
int Weapon::getDamage() {
	return damage;
}
string Weapon::getDescription() {
	return description;
}
int Weapon::getPrice() {
	return price;
}
void Weapon::increaseDamage() {
	this->damage += 1;
}

Weapon::~Weapon()
{
}
