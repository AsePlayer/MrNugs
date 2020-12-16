#pragma once
#include "pch.h"
#include <iostream>
#include "Unit.h"
#include "Warrior.h"
#include "NuggetGuard.h"
#include "DinoNuggetRider.h"
#include "FriendlyNuggetGuard.h"
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
	bool playerDead = false;

	//Player instantiation. Create this with save and load data later.
	
	
	
	
public:
	Campaign();
	~Campaign();

	bool progress(Player *h);
};

