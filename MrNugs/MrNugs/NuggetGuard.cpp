#include "pch.h"
#include "NuggetGuard.h"


NuggetGuard::NuggetGuard(int lvl)
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

void NuggetGuard::decideDamage(string attackName) {
	if (attackName == "Attack") {
		setdamage(getDMG() + randomNumber(5, 2));
	}
	else if (attackName == moves[0].getName() && getMP() >= moves[0].getMPCost()) {
		setdamage(getDMG() + (2 * randomNumber(8, 4)));
		setMP(getMP() - moves[0].getMPCost());
	}
}
string NuggetGuard::customAI(int HP) {
	//cout << endl << "DEFAULT AI" << endl;
	if (randomNumber(4, 0) == 0 && getMP() >= 75) {
		decideDamage("BleedAttack");
		return "BleedAttack";
	}
	else {
		decideDamage("Attack");
		return "Attack";
	}

}

vector<Special> NuggetGuard::getMoves() {
	return unlockedMoves;
}


NuggetGuard::~NuggetGuard()
{
}
