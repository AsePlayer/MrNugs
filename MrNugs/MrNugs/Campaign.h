#pragma once
#include "pch.h"
#include <iostream>
#include "Unit.h"
#include "Warrior.h"
#include "NuggetGuard.h"
#include <vector>
#include <memory>
#include <ctime>
#include <string>
#include "Battle.h"
#include "Campaign.h"
#include "Weapon.h"
#include "Shop.h"


class Campaign
{
private:
	

	vector<unique_ptr<Unit>> goodUnits;
	vector<unique_ptr<Unit>> badUnits;
	string placeholder;

	//Player instantiation. Create this with save and load data later.
	
	Shop shop;
	
	
public:
	Campaign();
	~Campaign();

	void progress(Player *h) {
		Battle battle;
		int pos = h->getPosInStory();
		switch (pos) {
		case 0:
			//Dialogue test
			cout << "2 Nugget Guards wish to engage in the fisticuffs with you." << endl;
			break;

		case 1:
			//Battle test
			goodUnits.emplace_back(new Warrior(h));

			badUnits.emplace_back(new NuggetGuard(1));
			badUnits.emplace_back(new NuggetGuard(1));

			battle.requestBattle(move(goodUnits), move(badUnits));
			break;
		
		case 2:
			//Shop test
			shop.requestShop(h);

			break;

		case 3:
			cout << "2 Slightly Better Nugget Guards wish to avenge their fallen comrades." << endl;
			goodUnits.emplace_back(new Warrior(h));

			badUnits.emplace_back(new NuggetGuard(3));
			badUnits.emplace_back(new NuggetGuard(2));

			battle.requestBattle(move(goodUnits), move(badUnits));
			break;

		default:
			cout << "Broke game";
		}

		goodUnits.clear();
		badUnits.clear();

		pos++;
		h->setPosInStory(pos);
		

	}
};

