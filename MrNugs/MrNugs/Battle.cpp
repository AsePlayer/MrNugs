#include "pch.h"
#include "Battle.h"


Battle::Battle()
{
}

void Battle::recieveBattle() {
	//Calculates Rewards
	for (int i = 0; i < units.size(); i++) {
		xpReward += units[i]->getXP();
		goldReward += units[i]->getGOLD();
	}

	battle();
}

void Battle::gameOver() {
	playerDied = true;
}

//Battle loop
void Battle::battle() {
	while (enemies != 0 && playerDied == false) {
		//cout << "loop start with enemies " << enemies;

		for (int i = 0; i < units.size(); i++) {
			vector<int> statusEffects = units[i]->getStatusEffects();

			//IF STUNNED
			if (statusEffects[1] > 0) {
				cout << endl << units[i]->getNAME() << " was stunned and lost their turn!" << endl;
				units[i]->setStatusEffects("Stun", -1);
				Sleep(1500);
			}
			else if (units[i]->getTYPE() == "Player") {
				//Print out character hp and mp
				cout << endl << "=====================" << endl;
				cout << units[0]->getNAME() << endl << endl;
				cout << "HP: " << units[0]->getHP() << "/" << units[0]->getMAXHP() << endl;
				cout << "MP: " << units[0]->getMP() << "/" << units[0]->getMAXMP() << endl;
				cout << "LV: " << units[0]->getLVL() << endl;
				cout << "=====================" << endl << endl;
				playerTurn();
				if (!debug) {
					Sleep(1500);
				}
				cout << endl;
			}
			//else if enemy attack
			else if (units[i]->getTYPE() == "Enemy" && units[i]->getHP() != 0) {
				enemyTurn(i);
				if (!debug) {
					Sleep(1500);
				}
				cout << endl;
			}
			//IF BLEEDING
			if (statusEffects[0] > 0) {
				int bleedDamage = units[i]->randomNumber(6, 4);
				if (units[i]->getHP() - bleedDamage <= 0) {
					units[i]->setHP(0);
					cout << endl << units[i]->getNAME() << " bled out!" << endl;
				}
				else {
					units[i]->setHP(units[i]->getHP() - bleedDamage);
					cout << endl << units[i]->getNAME() << " is bleeding and took " << bleedDamage << " damage! They now have " << units[i]->getHP() << " HP!" << endl;
				}
				units[i]->setStatusEffects("Bleed", -1);
				Sleep(1500);
			}


		}
		//Delete enemies if they die.
		for (int i = 0; i < units.size(); i++) {
			if (units[i]->getHP() <= 0) {
				units[i]->setIsDead(true);
			}
		}
		for (int i = 0; i < units.size(); i++) {

			if (units[i]->getIsDead()) {
				enemies -= 1;
				units.erase(units.begin() + i);
			}
		}

	}
	if (enemies == 0) {
		victory();
	}

}
void Battle::victory() {
	cout << endl << "* * * * * * * * * * * * * * * *" << endl << "   You Won " << goldReward << " gold and " << xpReward << "XP!" << endl << "* * * * * * * * * * * * * * * *" << endl;
	Sleep(1500);
	units[0]->updatePlayer(xpReward, goldReward);
}
//Pick target to attack, pick attack, damage target. 

void Battle::playerTurn() {
	bool exit = false;
	bool itemUsed = false;

	while (!exit) {
		int turn = battleMenu(itemUsed);
		//Back Button
		if (turn == -1) {

		}
		//Potion Used
		else if (turn == 0) {
			itemUsed = true;
		}
		//Turn Finished
		else if (turn == 1) {
			exit = true;
			break;
		}
	}


	//Prevents attack message appearing multiple times if player uses back command.


}

int Battle::battleMenu(bool itemUsed) {
	int numberFormat = 1;
	int numberFormatCorrection = 0;
	int option = 0;
	//bool itemUsed = usedItem;
	string attackUsed;
	string statusEffect;
	int duration;

	//Displays what broad action the Player would like to do?
	cout << "What would you like to do?" << endl << endl;
	cout << "[1] Attack" << endl;
	cout << "[2] Special" << endl;
	if (itemUsed) {
		//Gray out
		SetConsoleTextAttribute(hConsole, 8);
		cout << "[3] Item" << endl;
	}
	else {
		SetConsoleTextAttribute(hConsole, 7);
		cout << "[3] Item" << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << "[4] Info" << endl;
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "[0] Back" << endl;
	SetConsoleTextAttribute(hConsole, 7);

	cin >> option;
	while (option < 1 || option > 4 || cin.fail()) {
		if (option == 7926) {
			debug = true;
			cout << endl << endl << "DEBUG MODE ACTIVATE" << endl << endl << endl;
		}
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pick a number between 1 and 4" << endl;
		cin >> option;
	}
	moves = units[0]->getMoves();

	//Pick option's options
	switch (option) {
		//[1] ATTACK
	case 1:

		units[0]->decideDamage("Attack");
		attackUsed = "Attack";
		statusEffect = "None";
		duration = 0;
		break;
		/*###################################################################################################*/

													//[2] SPECIAL
	case 2:
		cout << "Which Special would you like to do?" << endl;
		for (int i = 0; i < moves.size(); i++) {
			//Not enough MP, gray out

			if (moves[i].getMPCost() > units[0]->getMP()) {
				SetConsoleTextAttribute(hConsole, 8);
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << "[" << i + 1 << "] " << moves[i].getName() << " (" << moves[i].getMPCost() << " MP)" << " - " << moves[i].getDescription() << endl;
		}
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl << "[0] Back" << endl;
		cin >> option;
		while (option < 0 || option > moves.size() || cin.fail()) {

			cin.clear();
			cin.ignore(256, '\n');
			cout << "Pick a number between 1 and " << moves.size() << endl;
			cin >> option;
		}
		if (option == 0) {
			return -1;

		}
		else {

			//Not enough MP
			while ((moves[option - 1].getMPCost()) > units[0]->getMP()) {

				cin.clear();
				cin.ignore(256, '\n');

				cout << endl << "Not enough MP!" << endl << "Which Special would you like to do?" << endl;
				cin >> option;
				while (option < 0 || option > moves.size() || cin.fail()) {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Pick a number between 1 and " << moves.size() << endl;
					cin >> option;
				}
				if (option == 0) {
					return -1;
					break;
				}

			}

			units[0]->decideDamage(moves[option - 1].getName());
			attackUsed = moves[option - 1].getName();
			statusEffect = moves[option - 1].getEffect();
			duration = moves[option - 1].getDuration();
			//cout << endl << "MOVE CHOSEN: " << moves[option - 1] << endl;

		}
		break;

		//[3] ITEM
		/*###################################################################################################*/

	case 3:
		if (itemUsed) {
			cout << endl << "Item already used this turn!" << endl;
			return -1;
		}
		else {
			items = units[0]->getItems();

			for (int i = 0; i < items.size(); i++) {
				cout << "[" << i + 1 << "] " << items[i].getName() << " (" << items[i].getDescription() << ")" << endl;
			}

			cout << endl << "[0] Back" << endl << endl;

			cin >> option;
			while (option < 0 || option > items.size() || cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Pick a number between 0 and " << items.size() << endl;
				cin >> option;
			}

			if (option == 0) {
				return -1;
			}
			else {
				if (items[option - 1].getType() == "HP") {
					if (units[0]->getHP() == units[0]->getMAXHP()) {
						cout << "You already have MAX HP!" << endl << endl;
						return -1;
					}
					units[0]->heal(items[option - 1].getValue());
					if (units[0]->getHP() == units[0]->getMAXHP()) {
						cout << "You healed to MAX HP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP!" << endl << endl;
					}
					else {
						cout << "You healed " << items[option - 1].getValue() << " HP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP!" << endl << endl;
					}
					units[0]->removeItem(option - 1);
				}
				else if (items[option - 1].getType() == "MP") {
					if (units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You already have MAX MP!" << endl << endl;
						return -1;
					}
					units[0]->recover(items[option - 1].getValue());
					if (units[0]->getHP() == units[0]->getMAXHP()) {
						cout << "You healed to MAX MP! You now have " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					else {
						cout << "You recovered " << items[option - 1].getValue() << " MP! You now have " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					units[0]->removeItem(option - 1);
				}

				return 0;
			}

		}

		break;
		/*###################################################################################################*/

	case 4:
		for (int i = 0; i < units.size(); i++) {
			cout << "[" << i + 1 << "] " << units[i]->getNAME() << endl;
		}
		cout << endl << "[0] Back" << endl << endl;
		cin >> target;
		if (target == 0) {
			return -1;
		}

		//Don't allow anything not an int or not in the range.
		while (target < 0 || target > units.size() || cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Pick a number between 1 and " << units.size() << endl;
			cin >> target;
		}

		cout << endl;
		cout << "NAME: " << units[target - 1]->getNAME() << endl;
		cout << "DESC: " << units[target - 1]->getDESC() << endl;
		cout << "LVL: " << units[target - 1]->getLVL() << endl;
		cout << "MAXHP: " << units[target - 1]->getMAXHP() << endl;
		cout << "MAXMP: " << units[target - 1]->getMAXMP() << endl;
		cout << "DMG: " << units[target - 1]->getDMG() << endl;

		cout << endl << "[0] Back" << endl << endl;

		cin >> target;
		return -1;

		break;
		/*###################################################################################################*/
	default:
		cout << "Something broke in the battle menu options.";
	}

	cout << endl << "Who would you like to attack?" << endl;
	//Displays target options.
	numberFormat = 1;
	numberFormatCorrection = 0;
	for (int i = 0; i < units.size(); i++) {
		if (units[i]->getTYPE() == "Player" || units[i]->getTYPE() == "Ally") {
			numberFormatCorrection++;
		}
		else {
			cout << "[" << numberFormat << "]: Level " << units[i]->getLVL() << " " << units[i]->getNAME() << " (with " << units[i]->getHP() << "/" << units[i]->getMAXHP() << " HP)" << endl;
			numberFormat++;
		}

	}
	cout << endl << "[0] Back" << endl;

	//Pick target
	cin >> target;
	//Don't allow anything not an int or not in the range.
	while (target < 0 || target >(units.size()) - numberFormatCorrection || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pick a number between 1 and " << (units.size()) - numberFormatCorrection << endl;
		cin >> target;
	}

	if (target == 0) {
		return -1;

	}
	if (attackUsed == "Attack") {
		statusEffect = "None";
		duration = 0;
	}
	dealDamage(0, target, attackUsed, statusEffect, duration);
	return 1;
}

//TODO: use target - numberFormatCorrection
void Battle::enemyTurn(int i) {
	vector<int> target = { 0 };
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
	string statusEffect = "None";
	int duration = 0;
	if (attackName == "StunAttack") {
		statusEffect = "Stun";
		duration = 1;
	}
	dealDamage(i, pickTarget, attackName, statusEffect, duration);

}

//Attacker deals damage to defender.
void Battle::dealDamage(int attacker, int defender, string attackname, string statuseffect, int length) {
	int attack = attacker;
	int defend = defender;
	string attackName = attackname;
	string statusEffect = statuseffect;
	int duration = length;

	cout << endl << units[attack]->getNAME() << " attacks " << units[defend]->getNAME() << " with " << attackName << ". ";
	if (units[0]->getHP() <= 0) {
		//Player death. call before he gets destroyed to prevent unforseen consequences. call battleDefeat() function.
		gameOver();
	}
	else if (units[defender]->getHP() - units[attacker]->getdamage() <= 0) {
		units[defender]->setHP(0);
		vector<int> status = units[defender]->getStatusEffects();

		if (status[0] != 0 && units[defender]->getHP() <= 0) {
		}
		else {
			cout << units[defender]->getNAME() << " took " << units[attacker]->getdamage() << " damage and died!";
		}
	}
	else {
		units[defender]->setHP(units[defender]->getHP() - units[attacker]->getdamage());
		cout << units[defender]->getNAME() << " took " << units[attacker]->getdamage() << " damage";
		if (statusEffect != "None") {
			if (statusEffect == "Stun") {
				units[defender]->setStatusEffects("Stun", duration);
				cout << " and was stunned";
			}
			if (statusEffect == "Bleed") {
				units[defender]->setStatusEffects("Bleed", duration);
				cout << " and is bleeding";
			}
		}
		cout << "! They now have " << units[defender]->getHP() << "HP.";
	}


}

//Attacker deals damage to multiple defenders.
void Battle::dealSplashDamage() {

}

//Player *h = new Player("Mr. Nugs", 3, Stick, {});
//Sets up turn order.
void Battle::requestBattle(vector<unique_ptr<Unit>> goodUnits, vector<unique_ptr<Unit>> badUnits) {
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

Battle::~Battle()
{
}
