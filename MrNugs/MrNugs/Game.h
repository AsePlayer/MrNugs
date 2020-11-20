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
using namespace std;
class Game
{
public:
	Game();
	~Game();

	void beginGame() {
		Battle battle;
		Campaign controller;

		for (int i = 0; i < 5; i++) {
			controller.progress(i);
		}
	}

	void saveGame() {

	}

	void loadGame() {

	}

};

