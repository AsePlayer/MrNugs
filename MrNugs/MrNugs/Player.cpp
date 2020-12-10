#include "pch.h"
#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(string name, int lvl, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory)
{
	this->name = name;
	this->lvl = lvl;
	this->weapon = weapon;
	this->money = money;
	this->items = items;
	this->characterClass = characterClass;
	this->posInStory = posInStory;
}

Player::~Player()
{
}
