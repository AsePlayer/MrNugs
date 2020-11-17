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

	virtual int randomNumber(int num, int plus) {

		return (rand() % num + plus);
	}


};
