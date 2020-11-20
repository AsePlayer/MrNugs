#pragma once
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
#include "Campaign.h"
class Campaign
{
private:
	Battle battle;
	vector<unique_ptr<Unit>> goodUnits;
	vector<unique_ptr<Unit>> badUnits;
	string placeholder;
public:
	Campaign();
	~Campaign();

	void progress(int progress) {

		switch (progress) {
		case 0:
			//Dialogue test
			cout << "2 Mages wish to engage in the fisticuffs with you." << endl;
			cin >> placeholder;
			break;

		case 1:
			//Battle test
			goodUnits.emplace_back(new Warrior(1));

			badUnits.emplace_back(new Mage(2));
			badUnits.emplace_back(new Mage(2));

			battle.requestBattle(move(goodUnits), move(badUnits));
			break;
		
		case 2:
			cout << "Either u did it or u hella dead lol";
			cin >> placeholder;
		default:
			cout << "Broke game";
		}
	}
};

