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
	{   //Item(string name, int value, int price, string description, string type);
		Weapon("Rolling Pin", 5, "\"Flatten the competition with this rolling pin!\"", 50), 
		Weapon("Potato Peeler", 15, "\"Its blade is a bit dull...\"", 125), 
		Weapon("Can Opener", 5, "\"With this weapon, you CAN-not lose!\"", 50),
		Weapon("Ladle", 15, "\"Come get a ladle-full!\"", 125),
		Weapon("Fork", 5, "\"A core utensil for any liquid adversary!\"", 50),
		Weapon("Scissors", 15, "\"Wins against paper 9 times out of 10!\"", 125),
		Weapon("Plastic Knife", 5, "\"The food-equivalent of a Hand Saw.\"", 50),
		Weapon("Butter Knife", 15, "\"If you thought you were going to cut anything with this knife, you were wrong.\"", 125),
		Weapon("Wooden Skewer", 5, "\"Go stick it to em'!\"", 50),
		Weapon("Plastic Straw", 15, "\"Particularly effective at sucking up liquids and killing turtles.\"", 125),
		Weapon("Literally Nothing", 0, "\"Fight the curiosity to see if this is ACTUALLY nothing.\"", 1),
		Weapon("Chef's Knife", 15, "\"\"I was going to kill them with kindness, but then I realized using a knife is a lot faster.\" - Jack the Ribber\"", 125),
		Weapon("Measuring Cup", 30, "\"See if you measure up to the competition with this handy cup!\"", 250) 
	};

	vector<Weapon> expensiveWeapons = 
	{ 
		Weapon("Metal Skewer (Seism, Betrayer of Suffering's End)", 44, "You thought you were already done? This is where the REAL fun begins!", 500), 
		Weapon("Cheese Grater (Cipherless, The Disposer of Secrets)", 66, "The most brutal form of torture available in the Nugget Kingdom.", 1500),
		Weapon("Frying Pan (Corpsemaker, The Frying Guillotine)", 44, "This portable tanning salon's side effects include being cooked alive and smelling delicious.", 500),
		Weapon("Pizza Cutter (Fetta Finale, The Final Cut)", 66, "The grand finale is upon us. It all comes down to this.", 1500),
		Weapon("Splayd (The Bond of The Corrupted)", 44, "The cursed creation of a spoon, knife and fork all in one. The jack of all trades.", 500),
		Weapon("Self-sharpening Knife (Calphalon, The Blade of Infinite Trials)", 66, "A terrifying knife to all of Food-kind. Each victim just strengthens its power.", 1500),
		Weapon("Hell's Eternity, Trident of Hatred", 44, "Serving Fork", 500),
		Weapon("Brother and Sister, The Twins Spears of Truth", 66, "chopsticks", 1500),
		Weapon("Last Favor, Champion Of Oblivion", 99, "Meat Tenderizer", 3000) 
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

