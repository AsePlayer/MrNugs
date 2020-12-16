#include "pch.h"
#include "DinoNuggetRider.h"


DinoNuggetRider::DinoNuggetRider(int lvl)
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

void DinoNuggetRider::decideDamage(string attackName) {
	if (attackName == "Attack") {
		setdamage(getDMG() + randomNumber(5, 8));
	}
	else if (attackName == moves[0].getName() && getMP() >= moves[0].getMPCost()) {
		setdamage(getDMG() + (2 * randomNumber(8, 4)));
		setMP(getMP() - moves[0].getMPCost());
	}
	else if (attackName == moves[1].getName() && getMP() >= moves[1].getMPCost()) {
		setdamage(getDMG() + (1.5f * randomNumber(4, 6)));
		setMP(getMP() - moves[1].getMPCost());
	}
	else if (attackName == moves[2].getName() && getMP() >= moves[2].getMPCost()) {
		setdamage(getDMG() + (3 * randomNumber(2, 4)));
		setMP(getMP() - moves[2].getMPCost());
	}
}
string DinoNuggetRider::customAI(int HP) {
	//cout << endl << "DEFAULT AI" << endl;
	int rng = randomNumber(7, 0);
	if ((rng == 0 || rng == 1) && getMP() >= moves[0].getMPCost()) {
		decideDamage(moves[0].getName());
		return moves[0].getName();
	}
	else if (rng == 2 && getMP() >= moves[1].getMPCost()) {
		decideDamage(moves[1].getName());
		return moves[1].getName();
	}
	else if ((rng == 3 || rng == 4 || rng == 5) && getMP() >= moves[2].getMPCost()) {
		decideDamage(moves[2].getName());
		return moves[2].getName();
	}
	else {
		decideDamage("Attack");
		return "Attack";
	}

}

vector<Special> DinoNuggetRider::getMoves() {
	return unlockedMoves;
}


DinoNuggetRider::~DinoNuggetRider()
{
}
