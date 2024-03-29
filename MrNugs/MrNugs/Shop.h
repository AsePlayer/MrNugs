//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
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
	{   //Weapon(string name, int damage, string description, int price)
		Weapon("Rolling Pin", 10, "\"Flatten the competition with this rolling pin!\"", 50), 
		Weapon("Potato Peeler", 5, "\"Its blade is a bit dull...\"", 12), 
		Weapon("Can Opener", 7, "\"With this weapon, you CAN-not lose!\"", 15),
		Weapon("Ladle", 6, "\"Come get a ladle-full!\"", 12),
		Weapon("Spoon", 5, "\"A core utensil for any liquid adversary!\"", 25),
		Weapon("Scissors", 15, "\"Wins against paper 9 times out of 10!\"", 55),
		Weapon("Plastic Knife", 4, "\"The food-equivalent of a Hand Saw.\"", 10),
		Weapon("Butter Knife", 3, "\"If you thought you were going to cut anything with this knife, you were wrong.\"", 25),
		Weapon("Wooden Skewer", 5, "\"Go stick it to em'!\"", 10),
		Weapon("Plastic Straw", 1, "\"Particularly effective at sucking up liquids and killing turtles.\"", 2),
		Weapon("Literally Nothing", 0, "\"Fight the curiosity to see if this is ACTUALLY nothing. I believe in you.\"", 1),
		Weapon("Chef's Knife", 25, "\"\"I was going to kill them with kindness, but then I realized using a knife is a lot faster.\" - Jack the Ribber\"", 75),
		Weapon("Measuring Cup", 10, "\"See if you measure up to the competition with this handy cup!\"", 40) 
	};

	vector<Weapon> expensiveWeapons = 
	{ 
		Weapon("Metal Skewer (Seism, Betrayer of Suffering's End)", 45, "\"You thought you were already done? This is where the REAL fun begins!\"", 175), 
		Weapon("Cheese Grater (Cipherless, The Disposer of Secrets)", 40, "\"The most brutal form of torture available in the Nugget Kingdom.\"", 150),
		Weapon("Frying Pan (Corpsemaker, The Frying Guillotine)", 55, "\"This portable tanning salon's side effects include being cooked alive and smelling delicious.\"", 200),
		Weapon("Pizza Cutter (Fetta Finale, The Final Cut)", 85, "\"The grand finale is upon us. It all comes down to this.\"", 333),
		Weapon("Splayd (The Bond of The Corrupted)", 50, "\"The cursed creation of a spoon, knife and fork all in one. The jack of all trades.\"", 250),
		Weapon("Self-sharpening Knife (Calphalon, The Blade of Infinite Trials)", 70, "\"A terrifying knife to all of Food-kind. With each victim, its power strengthens.\"", 500),
		Weapon("Serving Fork (Hell's Eternity, Trident of Hatred)", 60, "\"This fearsome weapon transforms the hatred of its master into raw unparalleled power.\"", 350),
		Weapon("Chopsticks (Brother and Sister, The Twins Spears of Truth)", 33*2, "\"The twin siblings enfused within this sacred weapon will guide the way.\"", 200*2),
		Weapon("Meat Tenderizer (Last Favor, Champion Of Oblivion)", 99, "\"The last favor you'll never ask for.\"", 500)
	};

	vector<Weapon> weaponsForSale;

	vector<Item> items =
	{	//Item(string name, int value, int price, string description, string type);
		Item("Ketchup Packet", 100, 50, "\"Heals 100 HP\"", "HP"),
		Item("Mustard Packet", 100, 50, "\"Recovers 100 MP\"", "MP"),
		Item("Thousand Island Packet", 150, 125, "\"Heals and Recovers 150 HP and MP\"","HP&MP"),
		Item("Ketchup Bottle", 250, 100, "\"Heals 250 HP\"", "HP"),
		Item("Mustard Bottle", 300, 100, "\"Recovers 300 MP\"", "MP"),
		Item("Ranch Bottle", 0, 75, "\"Cures all status effects\"", "Cure"),
		Item("Thousand Island Bottle", 300, 200, "\"Heals and Recovers 300 HP and MP\"","HP&MP")
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

