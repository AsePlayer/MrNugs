//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#include "pch.h"
#include "Battle.h"


Battle::Battle()
{
}

void Battle::recieveBattle() {
	int counter = 1;
	bool original = false;
	//Calculates Rewards
	for (int i = 0; i < units.size(); i++) {
		xpReward += units[i]->getXP();
		goldReward += units[i]->getGOLD();
	}
	//Gives duplicate enemies numbers so they can be distinguished.
	for (int i = 0; i < units.size(); i++) {
		for (int j = 0; j < units.size(); j++) {
			if (units[i]->getNAME() == units[j]->getNAME() && i != j) {
				original = true;
				counter++;
				units[j]->setNAME(units[j]->getNAME() + " " + to_string(counter));
			}
		}
		if (original == true) {
			units[i]->setNAME(units[i]->getNAME() + " " + to_string(1));
			original = false;
		}
		counter = 1;
	}

	battle();
}

void Battle::gameOver() {
	playerDied = true;
	//units[0]->updatePlayer(0, 0);
}

//Battle loop
void Battle::battle() {
	while (enemies != 0 && playerDied == false) {
		for (int i = 0; i < units.size(); i++) {
			if (units[0]->getHP() == 0) {
				playerDied = true;
				break;
			}
			vector<int> statusEffects = units[i]->getStatusEffects();
			//cout << "Bleed counter: " << statusEffects[0];
			//IF STUNNED
			if (statusEffects[1] > 0) {
				cout << endl << units[i]->getNAME() << " was stunned and lost their turn!";
				cout << endl << "---------------------------------------------------------------";
				units[i]->setStatusEffects("Stun", -1);
				Sleep(1500);
			}
			//If player attack
			else if (units[i]->getTYPE() == "Player") {

				playerTurn();
				if (statusEffects[0] > 0 || statusEffects[1] > 0 || statusEffects[2] > 0 || statusEffects[3] > 0) {

				}
				else {
					cout << endl << "---------------------------------------------------------------";
				}
				if (!debug) {
					Sleep(1500);
				}
			}
			//If enemy attack
			else if (units[i]->getTYPE() == "Enemy" && units[i]->getHP() != 0) {

				enemyTurn(i);
				if (statusEffects[0] > 0 || statusEffects[1] > 0 || statusEffects[2] > 0 || statusEffects[3] > 0) {

				}
				else {
					cout << endl << "---------------------------------------------------------------";
				}
				if (!debug) {
					Sleep(1500);
				}
			}
			//If ally attack
			else if (units[i]->getTYPE() == "Ally") {
				vector<int> targets = {};
				for (int j = 0; j < units.size(); j++) {
					if (units[j]->getTYPE() == "Enemy") {
						targets.push_back(j);
					}
				}
				int pickTarget = randomNumber(targets.size(),0);
				string attackName = units[i]->customAI(units[targets[pickTarget]]->getHP());
				dealDamage(i, targets[pickTarget], attackName, "None", 0);
				cout << endl << "---------------------------------------------------------------";
				Sleep(1500);
			}
			//IF BLEEDING
			statusEffects = units[i]->getStatusEffects();
			if (statusEffects[0] > 0) {
				int bleedDamage = units[i]->randomNumber(6, 4);
				if (units[i]->getHP() - bleedDamage <= 0 && units[i]->getTYPE() != "Player") {
					units[i]->setHP(0);
					cout << endl << units[i]->getNAME() << " bled out!" << endl;
				}
				else {
					units[i]->setHP(units[i]->getHP() - bleedDamage);
					cout << endl << units[i]->getNAME() << " is bleeding and took " << bleedDamage << " damage! They now have " << units[i]->getHP() << " HP!" << endl;
				}
				units[i]->setStatusEffects("Bleed", -1);
				cout << "---------------------------------------------------------------";
				Sleep(1500);
			}
			//IF POISONED (poison doesn't kill, doesn't go away, and reduces to 1hp at most).
			if (statusEffects[2] > 0) {
				int poisonDamage = units[i]->randomNumber(3, 2);
				if (units[i]->getHP() - poisonDamage <= 0) {
					if (units[i]->getHP() != 0) {

					}
					else if (units[i]->getHP() == 1) {
						cout << endl << units[i]->getNAME() << " is poisoned and has " << units[i]->getHP() << " HP!" << endl;
					}
					else {
						units[i]->setHP(1);
						cout << endl << units[i]->getNAME() << " is poisoned and was reduced to " << units[i]->getHP() << " HP!" << endl;
					}

				}
				else {
					units[i]->setHP(units[i]->getHP() - poisonDamage);
					cout << endl << units[i]->getNAME() << " is poisoned and took " << poisonDamage << " damage! They now have " << units[i]->getHP() << " HP!" << endl;
				}
				cout << "---------------------------------------------------------------";
				Sleep(1500);

			}
			

		}
		//Delete enemies if they die.
		for (int i = units.size() - 1; i > 0; i--) {
			if (units[i]->getHP() <= 0 && units[i]->getTYPE() == "Enemy") {
				enemies -= 1;
				units.erase(units.begin() + i);
			}
			else if (units[i]->getHP() <= 0 && units[i]->getTYPE() == "Ally") {
				units.erase(units.begin() + i);
			}
		}
	}
	if (enemies == 0) {
		//Special condition for Self-sharpening Knife (Calphalon, The Blade of Infinite Trials) damage increase.
		if (sliceUp > 0) {
			Sleep(1500);
			cout << endl << "Your Self-sharpening Knife (Calphalon, The Blade of Infinite Trials)'s sharpened with the slicing of its victims. Damage increased by " << sliceUp << "!" << endl;
		}
		victory();
	}

}

void Battle::victory() {
	cout << endl << "* * * * * * * * * * * * * * * *" << endl << "   You Won " << goldReward << " gold and " << xpReward << "XP!" << endl << "* * * * * * * * * * * * * * * *" << endl;
	Sleep(1500);
	units[0]->updatePlayer(xpReward, goldReward);
}

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

}

int Battle::battleMenu(bool itemUsed) {
	vector<Special> specials;
	vector<int> statusEffects;
	int numberFormat = 1;
	int numberFormatCorrection = 0;
	int option = 0;
	string attackUsed;
	string statusEffect;
	int duration;
	int effected = 0;

	//Displays what broad action the Player would like to do
	cout << endl << "=====================" << endl;
	cout << units[0]->getNAME() << endl << endl;
	cout << "HP: " << units[0]->getHP() << "/" << units[0]->getMAXHP() << endl;
	cout << "MP: " << units[0]->getMP() << "/" << units[0]->getMAXMP() << endl;
	cout << "LV: " << units[0]->getLVL() << endl;
	cout << "=====================" << endl << endl;
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
	
	case 1:
		//[1] ATTACK

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

				cout << endl << "Not enough MP!" << endl << endl;
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

			
			attackUsed = moves[option - 1].getName();

			//Only trigger stun if RNG permits it. Otherwise, stunlocks are too easy.
			if (moves[option - 1].getEffect() == "Stun"){
				//50% chance, chance increases based on character level.
				if (randomNumber(30, units[0]->getLVL()) > 15) {
				statusEffect = moves[option - 1].getEffect();
				}
			}
			else {
				//If not stun, give the effect no matter what.
				statusEffect = moves[option - 1].getEffect();

				if (moves[option - 1].getName() == "Arrow of ???") {
					int randomly = randomNumber(4, 0);
					
					if (randomly == 0) {
						statusEffect = "Bleed";
					}
					else if (randomly == 1) {
						statusEffect = "Poison";
					}
					else if (randomly == 2) {
						statusEffect = "Stun";
					}
					else if (randomly == 3) {
						statusEffect = "Confusion";
					}
					else {
						cout << "BROKEN BROKEN BROKEN";
					}
				}
			}
		
			duration = moves[option - 1].getDuration();
		}
		break;

		/*###################################################################################################*/

													//[3] ITEM
	case 3:
		if (itemUsed) {
			cout << endl << "Item already used this turn!" << endl;
			return -1;
		}
		else {
			cout << endl << "What Item would you like to use?" << endl;
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
				//If healing potion is used
				if (items[option - 1].getType() == "HP") {
					if (units[0]->getHP() == units[0]->getMAXHP()) {
						cout << "You already have MAX HP!" << endl << endl;
						Sleep(1500);
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
				//If mana potion is used
				else if (items[option - 1].getType() == "MP") {
					if (units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You already have MAX MP!" << endl << endl;
						Sleep(1500);
						return -1;
					}
					units[0]->recover(items[option - 1].getValue());
					if (units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You healed to MAX MP! You now have " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					else {
						cout << "You recovered " << items[option - 1].getValue() << " MP! You now have " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					units[0]->removeItem(option - 1);
				}
				//If hp and mana potion is used.
				else if (items[option - 1].getType() == "HP&MP") {
					if (units[0]->getHP() == units[0]->getMAXHP() && units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You already have MAX HP and MP!" << endl << endl;
						Sleep(1500);
						return -1;
					}
					units[0]->heal(items[option - 1].getValue());
					units[0]->recover(items[option - 1].getValue());
					//MAX HP and MAX MANA
					if (units[0]->getHP() == units[0]->getMAXHP() && units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You healed to MAX HP and MP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP and " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					//MAX HP but not MAX MANA
					else if (units[0]->getHP() == units[0]->getMAXHP() && units[0]->getMP() != units[0]->getMAXMP()) {
						cout << "You healed to MAX HP and recovered " << items[option - 1].getValue() << " MP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP and " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					//MAX MANA but not MAX HP
					else if (units[0]->getHP() != units[0]->getMAXHP() && units[0]->getMP() == units[0]->getMAXMP()) {
						cout << "You healed " << items[option-1].getValue() << " HP and recovered to MAX MP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP and " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					//Neither MAX HP or MAX MANA
					else {
						cout << "You healed " << items[option - 1].getValue() << " HP and recovered " << items[option - 1].getValue() << " MP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP and " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!" << endl << endl;
					}
					units[0]->removeItem(option - 1);
				}
				//If cure potion is used

				else if (items[option - 1].getType() == "Cure") {
					vector<int> effects = units[0]->getStatusEffects();

					bool effected = false;
					for (int i = 0; i < effects.size(); i++) {
						if (effects[i] != 0) {
							effected = true;
						}
					}
					if (effected == false) {
						cout << "You aren't suffering from any status effects!" << endl << endl;
						Sleep(1500);
						return -1;
					}
					else {
						cout << "You have been cured of all status effects!" << endl << endl;

						units[0]->cureStatusEffects();
					}
					units[0]->removeItem(option - 1);
				}
				Sleep(1500);

				return 0;
			}

		}

		break;
		/*###################################################################################################*/

												//[4] INFO
	case 4:
		cout << endl << "Which unit would you like info on?" << endl;
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
		cout << "DMG: " << units[target - 1]->getDMG() << endl << endl;
		cout << "Specials:" << endl;
		specials = units[target - 1]->getMoves();
		for (int i = 0; i < units[target - 1]->getMoves().size(); i++) {
			cout << specials[i].getName() << " - " << specials[i].getDescription() << endl;
		}

		cout << endl << "Status Effects:" << endl;
		statusEffects = units[target - 1]->getStatusEffects();
		for (int i = 0; i < statusEffects.size(); i++) {
			if (statusEffects[i] > 0) {
				effected++;
			}
		}
		if (effected == 0) {
			cout << "None" << endl;
		}
		else {
			//int bleed, stun, poison, confusion;
			if (statusEffects[0] > 0) {
				cout << "Bleeding: " << statusEffects[0] << endl;
			}
			if (statusEffects[1] > 0) {
				cout << "Stunned: " << statusEffects[1] << endl;
			}
			if (statusEffects[2] > 0) {
				cout << "Poisoned: Infinite" << endl;
			}
			if (statusEffects[3] > 0) {
				cout << "Confused: " << statusEffects[3] << endl;
			}

		}

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
	numberFormatCorrection = 1;
	for (int i = 0; i < units.size(); i++) {
		if (units[i]->getTYPE() == "Ally") {
			numberFormatCorrection++;
			SetConsoleTextAttribute(hConsole, 8);
			cout << "[X]: " << units[i]->getNAME() << " (" << units[i]->getHP() << "/" << units[i]->getMAXHP() << " HP)" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else {
			if (units[i]->getTYPE() != "Player") {
				cout << "[" << numberFormat << "]: " << units[i]->getNAME() << " (" << units[i]->getHP() << "/" << units[i]->getMAXHP() << " HP)" << endl;
				numberFormat++;
			}
		}

	}
	cout << endl << "[0] Back" << endl;

	//Pick target
	cin >> target;
	//Don't allow anything not an int or not in the range.
	while (target < 0 || target > (units.size()) - numberFormatCorrection || cin.fail()) {
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
	else {
		units[0]->decideDamage(moves[option - 1].getName());
	}
	dealDamage(0, target + numberFormatCorrection - 1, attackUsed, statusEffect, duration);
	if (attackUsed == "Bloodshed") {
		if (enemies != 0) {
			Sleep(1000);
			units[0]->decideDamage(moves[option - 1].getName());
			if (units[randomNumber(units.size() - 1, numberFormatCorrection)]->getHP() <= 0) {

			}
			else {
				dealDamage(0, randomNumber(units.size() - 1, numberFormatCorrection), attackUsed, statusEffect, duration);
			}

		}
	}
	if (attackUsed == "Drain Touch") {
		Sleep(1250);
		int val = (units[target - 1]->getMAXMP() / 25) * 5;
		units[0]->recover(val + 25);
		units[target + numberFormatCorrection - 1]->recover(-val);
		if (units[target - 1]->getMP() < 0) {
			units[target - 1]->setMP(0);
		}
		cout << endl << "Drain Touch recovered " << val + 25 << " MP! You now have " << units[0]->getMP() << "/" << units[0]->getMAXMP() << " MP!";
		if (units[0]->getMP() > units[0]->getMAXMP()) {
			units[0]->setMP(units[0]->getMAXMP());
		}
	}
	if (attackUsed == "Toxic Fangs") {
		Sleep(1500);
		int val = (units[target - 1]->getMAXHP() / 25) * 3;
		units[0]->heal(val);
		cout << endl << "Toxic Fangs healed " << val << " HP! You now have " << units[0]->getHP() << "/" << units[0]->getMAXHP() << " HP!";
		if (units[0]->getHP() > units[0]->getMAXHP()) {
			units[0]->setHP(units[0]->getMAXHP());
		}
	}
	if (attackUsed == "Steal") {
		Item item = Item("Ketchup Packet", 100, 75, "\"Heals 100 HP\"", "HP");
		int goldValue = 0;
		Sleep(1500);
		int rng = randomNumber(100,1);
		if (rng < 70) {
			goldValue += units[target - 1]->getGOLD() / 3;
			goldValue += randomNumber(3, 5);
			goldReward += goldValue;
			cout << endl << "Steal's haul was " << goldValue << " gold!";
		}
		else {
			if (rng > 70 && rng < 75) {
				item = Item("Ketchup Packet", 100, 75, "\"Heals 100 HP\"", "HP");
			}
			else if (rng > 75 && rng < 80) {
				item = (Item("Mustard Packet", 100, 75, "\"Recovers 100 MP\"", "MP"));
			}
			else if (rng > 80 && rng < 85) {
				item = (Item("Thousand Island Packet", 250, 150, "\"Heals and Recovers 150 HP and MP\"", "HP&MP"));
			}
			else if (rng > 85 && rng < 89) {
				item = (Item("Ketchup Bottle", 300, 250, "\"Heals 250 HP\"", "HP"));
			}
			else if (rng > 89 && rng < 94) {
				item = (Item("Mustard Bottle", 300, 300, "\"Recovers 250 MP\"", "MP"));
			}
			else if (rng > 94 && rng < 99) {
				item = (Item("Ranch Bottle", 0, 450, "\"Cures all status effects\"", "Cure"));
			}
			else {
				item = (Item("Thousand Island Bottle", 500, 1000, "\"Heals and Recovers 500 HP and MP\"", "HP&MP"));
			}
			cout << endl << "Steal's haul was 1 " << item.getName() << "!";
			units[0]->addItems(item);
		}

	}
	if (attackUsed == "Arrow Rain") {
		if (enemies != 0) {
			Sleep(1000);
			for (int i = 0; i < units.size(); i++) {
				if (units[i]->getTYPE() == "Enemy" && units[i]->getNAME() != units[target + numberFormatCorrection - 1]->getNAME()) {
					units[0]->recover(125);
					units[0]->decideDamage(moves[option - 1].getName());
					dealDamage(0, i , attackUsed, statusEffect, duration);
					Sleep(1000);
				}

			}

		}
	}
	return 1;
}


void Battle::enemyTurn(int i) {
	vector<int> target = { 0 };
	vector<int> statusEffects = units[i]->getStatusEffects();
	int pickTarget;
	//IF CONFUSED
	if (statusEffects[3] > 0 && units[i]->getNAME() != "The Maker" || statusEffects[3] > 0 && units[i]->getNAME() == "The Behemoth" && randomNumber(2,0) == 0) {
		for (int i = 0; i < units.size(); i++) {
			if (units[i]->getTYPE() == "Enemy") {
				target.push_back(i);
			}
		}
	}
//IF NOT CONFUSED
	else {
	for (int i = 0; i < units.size(); i++) {
		if (units[i]->getTYPE() == "Player" || units[i]->getTYPE() == "Ally") {
			target.push_back(i);
		}
	}
	}

	if (units[0]->getHP() <= units[i]->getDMG()) {
		pickTarget = 0;
	}
	else if (statusEffects[3] > 0) {
		pickTarget = units[i]->randomNumber(target.size(), 0);
		if (pickTarget == 0 && units[i]->getNAME() != "The Maker" || pickTarget == 0 && units[i]->getNAME() == "The Behemoth" && randomNumber(2, 0) == 0) {
			pickTarget = i;
		}
	}
	else {
		pickTarget = units[i]->randomNumber(target.size() - 1, 0);
	}

	string attackName = units[i]->customAI(units[pickTarget]->getHP());
	string statusEffect = "None";
	int duration = 0;
	if (attackName == "Tail Swipe" || attackName == "In My Eyes!" || attackName == "Piercing Screech" || attackName == "Poke") {
		statusEffect = "Stun";
		duration = 1;
	}
	else if (attackName == "Bite" || attackName == "Sharp Edge" || attackName == "Scratch") {
		statusEffect = "Bleed";
		duration = 2;
		if (attackName == "Scratch") {
			duration = 4;
		}
	}
	else if (attackName == "Bad Beans") {
		statusEffect = "Poison";
		duration = 1;
	}
	else {
		statusEffect = "None";
		duration = 0;
	}
	dealDamage(i, pickTarget, attackName, statusEffect, duration);

}

//Attacker deals damage to defender. Post-attack status effects are also applied.
void Battle::dealDamage(int attacker, int defender, string attackname, string statuseffect, int length) {
	int attack = attacker;
	int defend = defender;
	bool confused = false;
	string attackName = attackname;
	string statusEffect = statuseffect;
	int duration = length;
	vector<int> status = units[defender]->getStatusEffects();
	vector<int> statusAttacker = units[attacker]->getStatusEffects();

	//IF CONFUSED
	if (statusAttacker[3] > 0) {
		cout << endl << units[attack]->getNAME() << " is confused and attacks ";
		if (attacker == defender) {
			cout << "themself with " << attackName << ". ";
		}
		else {
			cout << units[defend]->getNAME() << " with " << attackName << ". ";
		}
		confused = true;
		units[attacker]->setStatusEffects("Confusion", -1);
	}
	else {
		cout << endl << units[attack]->getNAME() << " attacks " << units[defend]->getNAME() << " with " << attackName << ". ";
	}
	if (units[defender]->getHP() - units[attacker]->getdamage() <= 0) {
		units[defender]->setHP(0);

		if (units[0]->getHP() <= 0) {
			//Player death. call before he gets destroyed to prevent unforseen consequences. call battleDefeat() function.
			gameOver();
		}

		cout << units[defender]->getNAME() << " took " << units[attacker]->getdamage() << " damage and died!";
		Player* player = units[0]->getPlayer();
		Weapon weapon = player->getWeapon();

		//Gimmick for Self-sharpening Knife (Calphalon, The Blade of Infinite Trials)
		if (attackName == "Attack" && weapon.getName() == "Self-sharpening Knife (Calphalon, The Blade of Infinite Trials)") {
			weapon.increaseDamage();
			player->setWeapon(weapon);
			sliceUp++;
		}

	}
	else {
		units[defender]->setHP(units[defender]->getHP() - units[attacker]->getdamage());
		cout << units[defender]->getNAME() << " took " << units[attacker]->getdamage() << " damage";
		if (statusEffect != "None") {
			if (statusEffect == "Stun") {
				if (units[defender]->getNAME() == "The Behemoth") {
					if (randomNumber(3, 0) == 1){
						units[defender]->setStatusEffects("Stun", duration);
						cout << " and was stunned";
					}
				}
				else {
					units[defender]->setStatusEffects("Stun", duration);
					cout << " and was stunned";
				}
			}
			if (statusEffect == "Bleed") {
				units[defender]->setStatusEffects("Bleed", duration);
				cout << " and is bleeding";
			}
			if (statusEffect == "Poison") {
				units[defender]->setStatusEffects("Poison", duration);
				cout << " and is poisoned";
			}
			if (statusEffect == "Confusion") {
				units[defender]->setStatusEffects("Confusion", duration);
				cout << " and is confused";
			}
		}
		cout << "! They now have " << units[defender]->getHP() << "HP.";
		//Formatting.
		if (confused) {
			cout << endl << "---------------------------------------------------------------";
		}

	}


}

int Battle::randomNumber(int num, int plus) {
	return (rand() % num + plus);
}

//Attacker deals damage to multiple defenders.
void Battle::dealSplashDamage(int attacker, vector<int> defenders, string attackname, string statuseffect, int length) {

}

//Player *h = new Player("Mr. Nugs", 3, Stick, {});
//Sets up turn order.
bool Battle::requestBattle(vector<unique_ptr<Unit>> goodUnits, vector<unique_ptr<Unit>> badUnits) {
	enemies = 0;
	for (int i = 0; i < goodUnits.size(); i++) {
		units.emplace_back(move(goodUnits[i]));
	}
	enemies = badUnits.size();
	for (int i = 0; i < badUnits.size(); i++) {
		units.emplace_back(move(badUnits[i]));
	}

	recieveBattle();
	if (playerDied == true) {
		return true;
	}
	else {
		return false;
	}
}

Battle::~Battle()
{
}
