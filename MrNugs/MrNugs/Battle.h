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
using namespace std;

class Battle
{
private:
	vector<unique_ptr<Unit>> units;
	int target;
	int enemies;
	bool playerDied = false;
	
	//Picks attack depending on which attacker is up.
	void recieveBattle() {
		for (int i = 0; i < units.size(); i++) {
			//DEBUGGING PURPOSES
			units[i]->decideDamage("Special");
			//cout << "Level " << units[i]->getLVL() << " " << units[i]->getNAME() << " decides he feels like doing " << units[i]->getdamage() << " damage" << endl;
		}
		battle();
	}

	void gameOver() {
		playerDied = true;
	}

	//Battle loop
	void battle() {

		while (enemies != 0 && playerDied == false) {
			//cout << "loop start with enemies " << enemies;

			for (int i = 0; i < units.size(); i++) {
				if (units[i]->getTYPE() == "Player") {
					playerTurn();
				}
				else if (units[i]->getTYPE() == "Enemy" && units[i]->getHP() != 0) {
					enemyTurn(i);
				}
				else {
					//cout << units[i]->getNAME() << " died";
				}
				//else if enemy attack

			}
			//this statement isn't firing. EDIT: Seems to be working fine, keep eye on it.
			for (int i = 0; i < units.size(); i++) {
				if (units[i]->getHP() <= 0) {
					units.erase(units.begin() + i);
					enemies -= 1;
				}
			}

		}

	}
	//Pick target to attack, pick attack, damage target. 
	//TODO: add the pick attack part.
	void playerTurn() {
		int numberFormat = 0;
		int numberFormatCorrection = 0;

		//Displays what broad action the Player would like to do?


		cout << endl << "Who would you like to attack?" << endl;
		//Displays target options.
		for (int i = 0; i < units.size(); i++) {
			if (units[i]->TYPE == "Player" || units[i]->TYPE == "Ally") {
				numberFormatCorrection++;
			}
			else {
				cout << "[" << numberFormat << "]: " << units[i]->getNAME() << " (with " << units[i]->getHP() << " HP)" << endl;
				numberFormat++;
			}

		}
		//Pick target
		cin >> target;
		while (target < 0 || target >(units.size() - 1) - numberFormatCorrection) {
			cout << "Pick a number between 0 and " << (units.size() - 1) - numberFormatCorrection << endl;
			cin >> target;
		}

		//TODO: Display attack options.

		//Attack
		dealDamage(0, target + numberFormatCorrection, "Special");
	}
	//TODO: use target - numberFormatCorrection
	void enemyTurn(int i) {
		vector<int> target = {0};
		int pickTarget;
		for (int i = 0; i < units.size(); i++) {
			if (units[i]->getTYPE() == "Player" || units[i]->getTYPE() == "Ally") {
				target.push_back(i);
			}

		}
		if (units[0]->getHP() <= units[i]->getDMG()) {
			pickTarget = 0;
		}
		else {
			pickTarget = units[i]->randomNumber(target.size() - 1, 0);
		}
		
		//if statement for custom AI
		//defaults to default AI with else

		string attackName = units[i]->customAI(units[pickTarget]->getHP());
		dealDamage(i, pickTarget, attackName);
		
	}

	//Attacker deals damage to defender.
	void dealDamage(int attacker, int defender, string attackname) {
		int attack = attacker;
		int defend = defender;
		string attackName = attackname;

		cout << endl << "Level " << units[attack]->getLVL() << " " << units[attack]->getNAME() << " attacks " << units[defend]->getNAME() << " with " << attackName << ". ";
		if (units[0]->getHP() <= 0) {
			//Player death. call before he gets destroyed to prevent unforseen consequences. call battleDefeat() function.
			gameOver();
		}
		else if (units[defender]->getHP() - units[attacker]->getdamage() <= 0) {
			units[defender]->setHP(0);
			cout << units[defender]->getNAME() << " took " << units[attacker]->getdamage() << " damage and died!";
		}
		else {
			units[defender]->setHP(units[defender]->getHP() - units[attacker]->getdamage());
			cout << units[defender]->NAME << " took " << units[attacker]->damage << " damage! They now have " << units[defender]->HP << "HP.";
		}
		
	}

	//Attacker deals damage to multiple defenders.
	void dealSplashDamage() {

	}
	
public:
	Battle();
	~Battle();

	//Sets up turn order.
	void requestBattle(vector<unique_ptr<Unit>> goodUnits, vector<unique_ptr<Unit>> badUnits) {
		enemies = 0;
		for (int i = 0; i < goodUnits.size(); i++) {
			units.emplace_back(move(goodUnits[i]));
		}
		enemies = badUnits.size();
		for (int i = 0; i < badUnits.size(); i++) {
			units.emplace_back(move(badUnits[i]));
		}
		
		recieveBattle();
		
		
	}
	
};

