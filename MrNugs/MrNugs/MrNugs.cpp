// MrNugs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Unit.h"
#include "Warrior.h"
#include "Mage.h"
#include <vector>
#include <memory>
#include <ctime>
#include <string>
#include "Battle.h"
using namespace std;


int main()
{
	srand(time(NULL));

	Battle battle;

	//vector<Unit> gayass {penis, pp};

	

	vector<unique_ptr<Unit>> goodUnits;
	vector<unique_ptr<Unit>> badUnits;

	goodUnits.emplace_back(new Warrior());

	badUnits.emplace_back(new Mage());
	badUnits.emplace_back(new Mage());

	battle.requestBattle(move(goodUnits), move(badUnits));

}


