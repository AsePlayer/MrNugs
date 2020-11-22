#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
class Unit
{

public:
	Unit();
	~Unit();

	string NAME = "Unit";
	string TYPE = "Default";
	int LVL = -1000;
	int MAXHP = -1000;
	int HP = -1000;
	int MAXMP = -1000;
	int MP = -1000;
	int DMG = -1000;
	int DEF = -1000;
	int damage = -1000;


	virtual void decideDamage(string attackName) {
		cout << "This is in the unit class. Something has gone terribly wrong";
	}

	void setLVL(int lvl) {
		LVL = lvl;
		cout << "lol he is lvl " << LVL;
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}

	virtual string customAI(int HP) {
		return "Default";
	}

	string getNAME() {
		return NAME;
	}
	string getTYPE() {
		return TYPE;
	}
	int getLVL() {
		return LVL;
	}
	int getMAXHP() {
		return MAXHP;
	}
	int getHP() {
		return HP;
	}
	int getMAXMP() {
		return MAXMP;
	}
	int getMP() {
		return MP;
	}
	int getDMG() {
		return DMG;
	}
	int getDEF() {
		return DEF;
	}
	int getdamage() {
		return damage;
	}
	void setHP(int hp) {
		HP = hp;
	}


};
