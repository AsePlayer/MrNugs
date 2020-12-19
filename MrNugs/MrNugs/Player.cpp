//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#include "pch.h"
#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(string name, int lvl, int exp, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory)
{
	this->name = name;
	this->lvl = lvl;
	this->weapon = weapon;
	this->money = money;
	this->items = items;
	this->characterClass = characterClass;
	this->posInStory = posInStory;
	this->exp = exp;
}

string Player::getName() {
	return name;
}

string Player::getCharacterClass() {
	return characterClass;
}

int Player::getPosInStory() {
	return posInStory;
}

int Player::getLVL() {
	return lvl;
}

int Player::getEXP() {
	return exp;
}

Weapon Player::getWeapon() {
	return weapon;
}

vector<Item> Player::getItems() {
	return items;
}

int Player::getMoney() {
	return money;
}

void Player::setLVL(int lvl) {
	this->lvl = lvl;
}

void Player::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}

void Player::setItems(vector<Item> items) {
	this->items = items;
}

void Player::addItem(Item item) {
	items.push_back(item);
	//cout << "I worked";
}

void Player::removeItem(int itemIndex) {
	items.erase(items.begin() + itemIndex);
}

void Player::setMoney(int money) {
	this->money = money;
}

void Player::updateEXP(int exp) {
	this->exp += exp;
	if (this->getLVL() < expThresholds.size()) {
		if (this->exp >= expThresholds[getLVL()]) {
			exp -= expThresholds[getLVL()];
			setLVL(getLVL() + 1);
			cout << endl << getName() << " leveled up! They are now level " << getLVL() << "!" << endl;
			if (getLVL() == 3 || getLVL() == 6) {
				cout << endl << "You unlocked a new Special!" << endl;
			}

		}
	}
}

void Player::setCharacterClass(string characterClass) {
	this->characterClass = characterClass;
}

void Player::setPosInStory(int posInStory) {
	this->posInStory = posInStory;
}

Player::~Player()
{
}
