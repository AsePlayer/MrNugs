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
	
	Weapon Stick = Weapon("Stick", 5, "Weapon #1", 50);
	Weapon Stick2 = Weapon("Stick 2", 1500, "Okay now THIS is a stick...", 100);

	//Player instantiation. Create this with save and load data later.
	Player *h = new Player("Mr. Nugs", 1, Weapon("Stick", 5, "Weapon #1", 50), 100, { Item("Ketchup Packet", 100, 50, "Heals 100 HP", "HP") });
	Shop shop;

public:
	Campaign();
	~Campaign();

	void progress(int progress) {
		Battle battle;

		switch (progress) {
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

			goodUnits.emplace_back(new Warrior(h));

			badUnits.emplace_back(new NuggetGuard(1));
			badUnits.emplace_back(new NuggetGuard(1));

			battle.requestBattle(move(goodUnits), move(badUnits));
			break;

		default:
			cout << "Broke game";
		}

		goodUnits.clear();
		badUnits.clear();

	}
};

