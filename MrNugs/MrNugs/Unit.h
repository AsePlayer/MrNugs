#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Special.h"
using namespace std;
class Unit
{

	string NAME = "Unit";
	string TYPE = "Default";
	string DESC = "Default Description";

	vector<Special> moves = { Special{"Special",5,"special description"} };
	vector<Special> unlockedMoves = { Special{"Special",5,"special description"} };


	int LVL = -1000;
	int MAXHP = -1000;
	int HP = -1000;
	int MAXMP = -1000;
	int MP = -1000;
	int DMG = -1000;
	int DEF = -1000;
	int damage = -1000;
	bool isDead = false;
public:
	Unit();
	~Unit();



	virtual void decideDamage(string attackName) {
		cout << "This is in the unit class. Something has gone terribly wrong";
	}

	void setLVL(int lvl) {
		LVL = lvl;
	}

	int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}

	virtual string customAI(int HP) {
		return "Default";
	}

	virtual vector<Special> getMoves() {
		return unlockedMoves;
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
	bool getIsDead() {
		return isDead;
	}
	


	void setNAME(string name) {
		NAME = name;
	}
	void setTYPE(string type) {
		TYPE = type;
	}

	void setMAXHP(int maxhp) {
		MAXHP = maxhp;
	}
	void setHP(int hp) {
		HP = hp;
	}
	void setMAXMP(int maxmp) {
		MAXMP = maxmp;
	}
	void setMP(int mp) {
		MP = mp;
	}
	void setDMG(int dmg) {
		DMG = dmg;
	}
	void setDEF(int def) {
		def = DEF;
	}
	void setdamage(int passDamage) {
		damage = passDamage;
	}
	void setIsDead(bool dead) {
		isDead = dead;
	}



};
