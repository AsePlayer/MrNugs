#include "pch.h"
#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(string name, int lvl, Weapon weapon, int money, vector<Item> items)
{
	this->name = name;
	this->lvl = lvl;
	this->weapon = weapon;
	this->money = money;
	this->items = items;
}

Player::~Player()
{
}
