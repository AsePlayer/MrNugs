//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "pch.h"
#include <iostream>
#include "Unit.h"

#include <vector>
#include <memory>
#include <ctime>
#include <string>
#include "Battle.h"
#include "Campaign.h"
#include <fstream>
using namespace std;

class Game
{
private:
	Player *h = new Player("Mr. Nugs", 1, 1, Weapon("Stick", 5, "Weapon #1", 50), 100, { Item("Ketchup Packet", 100, 50, "Heals 100 HP", "HP") }, "Warrior", 0);
	int gameLength = 23;
	vector<string> classes = {
		"Warrior",
		"Mage",
		"Thief",
		"Archer"
	};

	vector<string> classDescriptions = { 
		"\"The Warrior paves the path with the corpses of all who dare test his might. The Warrior can cause intense damage to multiple enemies, inflict stun, and buff himself the more injured he is.\"", 
		"\"The Mage is a crafty and dangerous fellow. The Mage can cause crippling damage to a target, inflict confusion, recover MP, and scale damage with MP.\"",
		"\"The Thief is a cunning and deceptive adversary. The Thief can cause bleeding and poison damage to a target, steal gold and items, and steal HP.\"",
		"\"The Archer's cause is just and his aim is true. The Archer can cause major damage to a target, afflict a random status effect, and rain arrows upon all on the battlefield.\""
	};
	

public:
	Game();
	~Game();

	void newGame();

	void beginGame();

	void saveGame();

	void loadGame();

};

