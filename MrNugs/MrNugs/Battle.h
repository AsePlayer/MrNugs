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
	
	//Picks attack depending on which attacker is up.
	void recieveBattle() {
		for (int i = 0; i < units.size(); i++) {
			
			units[i]->decideDamage("Special");
			cout << units[i]->NAME << " decides he feels like doing " << units[i]->damage << " damage" << endl;
		}
		battle();
	}

	//Battle loop
	void battle() {

		while (enemies != 0) {
			if (units[target]->HP <= 0) {
				units.erase(units.begin() - target);
			}
			for (int i = 0; i < units.size() - 1; i++) {
				if (units[i]->TYPE == "Player") {
					playerTurn();
				}
				//else if enemy attack

			}


		}

	}
	//Pick target to attack, pick attack, damage target. 
	//TODO: add the pick attack part.
	void playerTurn() {
		int numberFormat = 0;
		int numberFormatCorrection = 0;

		cout << endl << "Who would you like to attack?" << endl;
		//Displays target options.
		for (int i = 0; i < units.size(); i++) {
			if (units[i]->TYPE == "Player" || units[i]->TYPE == "Ally") {
				numberFormatCorrection++;
			}
			else {
				cout << "[" << numberFormat << "]: " << units[i]->NAME << " (with " << units[i]->HP << " HP)" << endl;
				numberFormat++;
			}

		}
		cin >> target;
		while (target < 0 || target >(units.size() - 1) - numberFormatCorrection) {
			cout << "Pick a number between 0 and " << (units.size() - 1) - numberFormatCorrection << endl;
			cin >> target;
		}

		//TODO: Display attack options.

		//Attack
		dealDamage(0, target + numberFormatCorrection);
	}
	//TODO: use target - numberFormatCorrection
	void enemyTurn() {

	}

	//Attacker deals damage to defender.
	void dealDamage(int attacker, int defender) {
		int attack = attacker;
		int defend = defender;
		
		if (units[0]->HP <= 0) {
			//Player death. call before he gets destroyed to prevent unforseen consequences. call battleDefeat() function.
		}
		else if (units[defender]->HP - units[attacker]->damage <= 0) {
			units[defender]->HP = 0;
			cout << units[defender]->NAME << " took " << units[attacker]->damage << " damage and died!";
		}
		else {
			units[defender]->HP -= units[attacker]->damage;
			cout << units[defender]->NAME << " took " << units[attacker]->damage << " damage! They now have " << units[defender]->HP << "HP.";
		}
		
		
		//cout << "Lol he kinda deserved that. " << units[defender]->NAME << " took " << units[attacker]->damage << " damage! They now have " << units[defender]->HP << "HP." ;

		if (units[defender]->HP <= 0) {
			units.erase(units.begin() + defender);
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

