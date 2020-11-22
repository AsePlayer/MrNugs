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
#include "Weapon.h"

class Campaign
{
private:
	
	Battle battle;
	vector<unique_ptr<Unit>> goodUnits;
	vector<unique_ptr<Unit>> badUnits;
	string placeholder;
	
	Weapon Stick = Weapon("Stick", 5, "Yeah right. More like a twig at best...");
	Weapon Stick2 = Weapon("Stick 2", 1500, "Okay now THIS is a stick...");
	Weapon Stick3{ "bruh",69,"ok now this is epic" };
	//Player instantiation. Create this with save and load data later.
	Player *h = new Player(420, Stick2);
	

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
			goodUnits.emplace_back(new Warrior(h));

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

