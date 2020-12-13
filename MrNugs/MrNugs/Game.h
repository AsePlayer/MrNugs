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
	Player *h = new Player("Mr. Nugs", 1, Weapon("Stick", 5, "Weapon #1", 50), 100, { Item("Ketchup Packet", 100, 50, "Heals 100 HP", "HP") }, "Warrior", 0);
	int gameLength = 4;
	vector<string> classes = {"Warrior"};
	vector<string> classDescriptions = { "The Warrior paves the path with the corpses of all who dare test his might. The Warrior can cause intense damage to multiple enemies, inflict stun, and buff himself." };
	

public:
	Game();
	~Game();

	void newGame();

	void beginGame();

	void saveGame();

	void loadGame();



};

