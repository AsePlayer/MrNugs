//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#include "pch.h"
#include "Chicken.h"


Chicken::Chicken(int lvl)
{

	//this->LVL = lvl;
	//setLVL(lvl);

	this->setLVL(lvl);

	this->setNAME(name);
	this->setTYPE(type);
	this->setDESC(desc);
	this->setGOLD(gold + (gold * ((lvl - 1) * .05f)));
	this->setXP(xp + (xp * ((lvl - 1) * .05f)));
	this->setMAXHP(maxhp + (maxhp * ((lvl - 1) * .05f)));
	this->setHP(hp + (hp * ((lvl - 1) * .05f)));
	this->setMAXMP(maxmp + (maxmp * ((lvl - 1) * .05f)));
	this->setMP(mp + (mp * ((lvl - 1) * .05f)));
	this->setDMG(dmg + (dmg * ((lvl - 1) * .05f)));

	this->setDEF(def * lvl);

	this->setdamage(0);
}

void Chicken::decideDamage(string attackName) {
	if (attackName == "Attack") {
		setdamage(getDMG() + 2 * randomNumber(5, 2));
	}
	else if (attackName == moves[0].getName() && getMP() >= moves[0].getMPCost()) {
		setdamage(getDMG() + (randomNumber(8, 4)));
		setMP(getMP() - moves[0].getMPCost());
	}
	else if (attackName == moves[1].getName() && getMP() >= moves[1].getMPCost()) {
		setdamage(getDMG() + (2 * randomNumber(6, 8)));
		setMP(getMP() - moves[1].getMPCost());
	}
	else if (attackName == moves[2].getName() && getMP() >= moves[2].getMPCost()) {
		setdamage(getDMG() + (2 * randomNumber(8, 4)));
		setMP(getMP() - moves[2].getMPCost());
	}
}
string Chicken::customAI(int HP) {
	//cout << endl << "DEFAULT AI" << endl;
	int rng = randomNumber(8, 0);
	if (rng <= 2 && getMP() >= moves[0].getMPCost() && !screeched) {
		decideDamage(moves[0].getName());
		screeched = true;
		return moves[0].getName();
	}
	else if (rng <= 5 && getMP() >= moves[1].getMPCost()) {
		decideDamage(moves[1].getName());
		return moves[1].getName();
	}
	else if (rng <= 7 && getMP() >= moves[2].getMPCost()) {
		screeched = false;
		decideDamage(moves[2].getName());
		return moves[2].getName();
	}
	else {
		screeched = false;
		decideDamage("Attack");
		return "Attack";
	}

}

vector<Special> Chicken::getMoves() {
	return unlockedMoves;
}


Chicken::~Chicken()
{
}
