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
	{	//Item(string name, int value, int price, string description, string type);
		Item("Ketchup Packet", 100, 75, "Heals 100 HP", "HP"),
		Item("Mustard Packet", 100, 75, "Recovers 100 MP", "MP"),
		Item("Thousand Island Packet", 250, 150, "Heals and Recovers 150 HP and MP","HP&MP"),
		Item("Ketchup Bottle", 300, 250, "Heals 250 HP", "HP"),
		Item("Mustard Bottle", 300, 300, "Recovers 250 MP", "MP"),
		Item("Ranch Bottle", 0, 450, "Cures all status effects", "Cure"),
		Item("Thousand Island Bottle", 500, 1000, "Heals and Recovers 500 HP and MP","HP&MP")
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

