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
using namespace std;
class Game
{
private:
	Player *h = new Player("Mr. Nugs", 1, Weapon("Stick", 5, "Weapon #1", 50), 100, { Item("Ketchup Packet", 100, 50, "Heals 100 HP", "HP") }, "Warrior", 0);
public:
	Game();
	~Game();

	void beginGame() {
		Battle battle;
		Campaign controller;

		while (h->getPosInStory() < 4) {
			controller.progress(h);
		}
	}

	void saveGame() {

	}

	void loadGame() {

	}

};

