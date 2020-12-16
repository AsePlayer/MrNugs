#include "pch.h"
#include "Game.h"



Game::Game()
{
}

void Game::beginGame() {

	
	int option = 0;
	//Player(string name, int lvl, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory)

	cout << "  WELCOME TO MR. NUGS!" << endl << "A game made by Ryan Scott" << endl << "=========================" << endl << endl << "Would you like to start a new game or load a previous save?" << endl << endl;
	cout << "[1] New Game" << endl << "[2] Load Game" << endl << endl;

	cin >> option;
	while (option < 1 || option > 2 || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pick a number between 1 and 2" << endl;
		cin >> option;
	}

	if (option == 1) {
		newGame();
	}
	else if (option == 2) {
		loadGame();
	}

	Battle battle;
	Campaign controller;
	int getSaveReq;
	
	while (h->getPosInStory() < gameLength) {
		
		if (!controller.progress(h)) {
			cout << endl << endl << "You died! Would you like to retry or load back to previous save?" << endl;
			cout << endl << "[1] Retry" << endl << "[2] Load Save" << endl << endl;
			
			cin >> option;
			while (option < 1 || option > 2 || cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Pick a number between 1 and 2" << endl;
				cin >> option;
			}

			if (option == 1) {
				
			}
			else if (option == 2) {
				loadGame();
			}


		}
		else {
			cout << endl << "Would you like to save the game?" << endl;
			cout << "[1] Yes" << endl << endl << "[0] No" << endl << endl;
			cin >> getSaveReq;
			if (getSaveReq == 1) {
				ofstream SaveFile("save.txt");
				saveGame();
			}
		}


	}
}

void Game::newGame() {
	int option;
	cout << "What class do you want to be?" << endl << endl;
	for (int i = 0; i < classes.size(); i++) {
		cout << "[" << i + 1 << "]: " << classes[i] << " - " << classDescriptions[i] << endl << endl;
	}

	cin >> option;
	while (option < 1 || option > classes.size() || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pick a number between 1 and " << classes.size() << endl;
		cin >> option;
	}

	h = new Player{"Mr. Nugs", 1, Weapon("Used Toothpick", 5, "A used toothpick. One side is still wet... ew.", 2), 100 , {}, classes[option - 1], 0};
	cout << endl << "--- You have chosen the path of the " << classes[option - 1] << " ---" << endl << endl;
	Sleep(1500);
}

void Game::saveGame() {

	vector<Item> playerItems = h->getItems();
	Weapon playerWeapon = h->getWeapon();
	
	ofstream SaveFile("save.txt");
	SaveFile << "<name>" << endl << h->getName() << endl << "</name>" << endl;
	SaveFile << "<lvl>" << endl << h->getLVL() << endl << "</lvl>" << endl;

	//Build weapon in save.
	//Weapon(string name, int damage, string description, int price);
	SaveFile << "<weapon>" << endl;
	SaveFile << playerWeapon.getName() << endl << playerWeapon.getDamage() << endl << playerWeapon.getDescription() << endl << playerWeapon.getPrice() << endl;
	SaveFile << "</weapon>" << endl;

	SaveFile << "<money>" << endl << h->getMoney() << endl << "</money>" << endl;

	//Build items in save.
	//Item(string name, int value, int price, string description, string type);
	SaveFile << "<items>" << endl;

	for (int i = 0; i < playerItems.size(); i++) {
		SaveFile << "<item>" << endl;
		SaveFile << playerItems[i].getName() << endl;
		SaveFile << playerItems[i].getValue() << endl;
		SaveFile << playerItems[i].getPrice() << endl;
		SaveFile << playerItems[i].getDescription() << endl;
		SaveFile << playerItems[i].getType() << endl;
		SaveFile << "</item>" << endl;
	}
	SaveFile << "</items>" << endl;

	SaveFile << "<class>" << endl << h->getCharacterClass() << endl << "</class>" << endl;
	SaveFile << "<pos>" << endl << h->getPosInStory() << endl << "</pos>";

	SaveFile.close();
}

void Game::loadGame() {
	string text;

	string name;
	int lvl;
	Weapon weapon = {"",1,"",1};
	int money;
	vector<Item> items = {};
	string characterClass;
	int posInStory;

	ifstream LoadFile("save.txt");
	getline(LoadFile, text);
	if (text == "") {
		cout << endl << "Error: You don't have a save file" << endl << endl;
		beginGame();
	}
	else {
		if (text == "<name>") {
			getline(LoadFile, text);
			name = text;
		}
	}

	while (getline(LoadFile, text)) {
		 
		//Player(string name, int lvl, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory)
		if (text == "<lvl>") {
			getline(LoadFile, text);
			//string-to-integer
			lvl = stoi(text);
		}
		if (text == "<weapon>") {
			getline(LoadFile, text);
			string name = text;
			getline(LoadFile, text);
			int damage = stoi(text);
			getline(LoadFile, text);
			string description = text;
			getline(LoadFile, text);
			int price = stoi(text);
			weapon = {name, damage, description, price};
		}
		if (text == "<money>") {
			getline(LoadFile, text);
			money = stoi(text);
		}//Item(string name, int value, int price, string description, string type);
		if (text == "<items>") {
			getline(LoadFile, text);
			while (text != "</items>") {
				if (text == "<item>") {
					getline(LoadFile, text);
					string name = text;
					getline(LoadFile, text);
					int value = stoi(text);
					getline(LoadFile, text);
					int price = stoi(text);
					getline(LoadFile, text);
					string description = text;
					getline(LoadFile, text);
					string type = text;
					items.push_back(Item(name, value, price, description, type));
				}
				getline(LoadFile, text);
			}
		}
		if (text == "<class>") {
			getline(LoadFile, text);
			characterClass = text;
		}
		if (text == "<pos>") {
			getline(LoadFile, text);
			posInStory = stoi(text);
		}

	}//Player(string name, int lvl, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory)
	h = new Player{name,lvl,weapon,money,items,characterClass,posInStory};
}


Game::~Game()
{
}
