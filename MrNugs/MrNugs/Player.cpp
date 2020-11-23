#include "pch.h"
#include "Player.h"


Player::Player(string name, int lvl, Weapon weapon)
{
	this->name = name;
	this->lvl = lvl;
	this->weapon = weapon;
}

Player::~Player()
{
}
