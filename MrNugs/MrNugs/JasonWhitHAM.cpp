//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#include "pch.h"
#include "JasonWhitHAM.h"


JasonWhitHAM::JasonWhitHAM(int lvl)
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

void JasonWhitHAM::decideDamage(string attackName) {
	if (attackName == "Attack") {
		setdamage(getDMG() + randomNumber(5, 2));
	}
	else if (attackName == moves[0].getName() && getMP() >= moves[0].getMPCost()) {
		setdamage(getDMG() + (randomNumber(4, 4)));
		setMP(getMP() - moves[0].getMPCost());
	}
}
string JasonWhitHAM::customAI(int HP) {
	//cout << endl << "DEFAULT AI" << endl;
	if (randomNumber(4, 0) >= 2 && getMP() >= moves[0].getMPCost()) {
		decideDamage(moves[0].getName());
		setGOLD(getGOLD() + 25);
		return moves[0].getName();
	}
	else {
		decideDamage("Attack");
		return "Attack";
	}

}

vector<Special> JasonWhitHAM::getMoves() {
	return unlockedMoves;
}


JasonWhitHAM::~JasonWhitHAM()
{
}
