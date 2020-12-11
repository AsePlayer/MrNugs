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

	void progress(Player *h);
};

