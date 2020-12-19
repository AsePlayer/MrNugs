//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#include "pch.h"
#include "Unit.h"

Unit::Unit()
{
}

void Unit::decideDamage(string attackName) {
	cout << "This is in the unit class. Something has gone terribly wrong";
}

void Unit::setLVL(int lvl) {
	LVL = lvl;
}

void Unit::setPlayerLVL(int lvl) {

}

int Unit::randomNumber(int num, int plus) {
	return (rand() % num + plus);
}

void Unit::addItems(Item items) {

}

string Unit::customAI(int HP) {
	return "Default";
}

vector<Special> Unit::getMoves() {
	return unlockedMoves;
}

vector<Item> Unit::getItems() {
	return {};
}

void Unit::removeItem(int num) {

}

void Unit::updatePlayer(int exp, int gold) {

}

void Unit::heal(int value) {
	if ((getHP() + value) > getMAXHP()) {
		setHP(getMAXHP());
	}
	else {
		setHP(getHP() + value);
	}
}

void Unit::recover(int value) {
	if ((getMP() + value) > getMAXMP()) {
		setMP(getMAXMP());
	}
	else {
		setMP(getMP() + value);
	}
}


string Unit::getNAME() {
	return NAME;
}
string Unit::getTYPE() {
	return TYPE;
}
string Unit::getDESC() {
	return DESC;
}
int Unit::getXP() {
	return XP;
}
int Unit::getGOLD() {
	return GOLD;
}
int Unit::getLVL() {
	return LVL;
}
int Unit::getMAXHP() {
	return MAXHP;
}
int Unit::getHP() {
	return HP;
}
int Unit::getMAXMP() {
	return MAXMP;
}
int Unit::getMP() {
	return MP;
}
int Unit::getDMG() {
	return DMG;
}
int Unit::getDEF() {
	return DEF;
}
int Unit::getdamage() {
	return damage;
}
bool Unit::getIsDead() {
	return isDead;
}
vector<int> Unit::getStatusEffects() {
	vector<int> statusEffects = { bleed, stun, poison, confusion };
	return statusEffects;
}

void Unit::setStatusEffects(string effect, int amount) {
	if (effect == "Stun") {
		stun += amount;
	}
	if (effect == "Bleed") {
		bleed += amount;
	}
	if (effect == "Poison") {
		poison += amount;
	}
	if (effect == "Confusion") {
		confusion += amount;
	}
}

void Unit::cureStatusEffects() {
	this->stun = 0;
	this->bleed = 0;
	this->poison = 0;
	this->confusion = 0;
}

void Unit::setNAME(string name) {
	NAME = name;
}
void Unit::setTYPE(string type) {
	TYPE = type;
}
void Unit::setDESC(string desc) {
	DESC = desc;
}
void Unit::setXP(int xp) {
	XP = xp;
}
void Unit::setGOLD(int gold) {
	GOLD = gold;
}
void Unit::setMAXHP(int maxhp) {
	MAXHP = maxhp;
}
void Unit::setHP(int hp) {
	HP = hp;
}
void Unit::setMAXMP(int maxmp) {
	MAXMP = maxmp;
}
void Unit::setMP(int mp) {
	MP = mp;
}
void Unit::setDMG(int dmg) {
	DMG = dmg;
}
void Unit::setDEF(int def) {
	def = DEF;
}
void Unit::setdamage(int passDamage) {
	damage = passDamage;
}
void Unit::setIsDead(bool dead) {
	isDead = dead;
}

Player* Unit::getPlayer() {
	Player* h = new Player{ "Mr. Nugs", 1, 0, Weapon("Used Toothpick", 5, "A used toothpick. One side is still wet... ew.", 2), 100 , {}, "Warrior", 0 };
	return h;
}

void Unit::setWeapon() {

}

Unit::~Unit()
{
}
