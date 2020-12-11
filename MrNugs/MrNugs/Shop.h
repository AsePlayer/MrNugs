#pragma once
#include "pch.h"
#include <iostream>
#include "Unit.h"
#include <Windows.h>
#include <vector>
#include <memory>
#include <ctime>
#include <string>

#include "Weapon.h"
#include "Item.h"
#include "Player.h"
#include <windows.h>
using namespace std;


class Shop
{
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Weapon> cheapWeapons = 
	{ 
		Weapon("Stick", 5, "\"Weapon Description #1\"", 50), 
		Weapon("Branch", 15, "\"Weapon Description #2\"", 125), 
		Weapon("Log", 30, "\"Weapon Description #3\"", 250) 
	};

	vector<Weapon> expensiveWeapons = 
	{ 
		Weapon("Expensive Stick", 44, "Expensive #1", 500), 
		Weapon("Expensive Branch", 66, "Expensive #2", 1500), 
		Weapon("Expensive Log", 99, "Expensive #3", 3000) 
	};

	vector<Weapon> weaponsForSale;

	vector<Item> items = 
	{ 
		Item("Ketchup Packet", 100, 50, "Heals 100 HP", "HP"), 
		Item("Mustard Packet", 100, 50, "Recovers 100 MP", "MP"), 
		Item("Ketchup Bottle", 250, 150, "Heals 250 HP", "HP"), 
		Item("Mustard Bottle", 250, 150, "Recovers 250 MP", "MP") 
	};

	//Generate the two weapons (one cheap, one expensive) for sale today.
	vector<Weapon> getWeaponsForSale(Weapon currentWeapon);

	void shop(Player *player);

	int displayDeals(Player *player);

	int randomNumber(int num, int plus);

public:
	Shop();
	~Shop();

	void requestShop(Player *player);
};

