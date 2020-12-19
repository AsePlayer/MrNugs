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
#include "Battle.h"
#include "Special.h"

#include <windows.h>
//Change text color vvvvvvvvvvvvv

//https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c

using namespace std;

class Battle
{
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<unique_ptr<Unit>> units;
	bool debug = false;
	int target;
	int enemies;
	int recursiveCount = 0;
	int xpReward;
	int goldReward;

	int sliceUp;

	bool playerDied = false;
	vector<Special> moves;
	vector<Item> items;
	

	void recieveBattle();

	void gameOver();

	//Battle loop
	void battle();
	void victory();
	//Pick target to attack, pick attack, damage target. 
	
	void playerTurn();

	int battleMenu(bool itemUsed);

	//TODO: use target - numberFormatCorrection
	void enemyTurn(int i);

	//Attacker deals damage to defender.
	void dealDamage(int attacker, int defender, string attackname, string statuseffect, int length);

	//Attacker deals damage to multiple defenders.
	void dealSplashDamage(int attacker, vector<int> defenders, string attackname, string statuseffect, int length);

	int randomNumber(int num, int plus);
public:
	Battle();



	~Battle();
	//Player *h = new Player("Mr. Nugs", 3, Stick, {});
	//Sets up turn order.
	bool requestBattle(vector<unique_ptr<Unit>> goodUnits, vector<unique_ptr<Unit>> badUnits);
	
};

