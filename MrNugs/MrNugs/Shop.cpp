#include "pch.h"
#include "Shop.h"
#include "Player.h"


Shop::Shop()
{

}

vector<Weapon> Shop::getWeaponsForSale(Weapon currentWeapon) {
	for (int i = 0; i < cheapWeapons.size(); i++) {
		if (currentWeapon.getName() == cheapWeapons[i].getName()) {
			cheapWeapons.erase(cheapWeapons.begin() + i);
		}
	}
	for (int i = 0; i < expensiveWeapons.size(); i++) {
		if (currentWeapon.getName() == expensiveWeapons[i].getName()) {
			expensiveWeapons.erase(expensiveWeapons.begin() + i);
		}
	}

	vector<Weapon> weaponsGot;
	int cheapWepCount = 1 + randomNumber(3, 0);
	int expensiveWepCount = 1;

	Weapon cheapWeapon = Weapon("Shop Default", 0, "\"You shouldn't be seeing this.\"", 0);
	int cheapNumber;

	for (int i = 0; i < cheapWepCount; i++){
		cheapNumber = randomNumber(cheapWeapons.size(), 0);
		cheapWeapon = cheapWeapons[cheapNumber];
		cheapWeapons.erase(cheapWeapons.begin() + cheapNumber);
		weaponsGot.push_back(cheapWeapon);
	}

	Weapon expensiveWeapon = Weapon("Shop Default", 0, "\"You shouldn't be seeing this.\"", 0);
	int expensiveNumber;
	for (int i = 0; i < expensiveWepCount; i++) {
		expensiveNumber = randomNumber(expensiveWeapons.size(), 0);
		expensiveWeapon = expensiveWeapons[expensiveNumber];
		expensiveWeapons.erase(expensiveWeapons.begin() + expensiveNumber);
		weaponsGot.push_back(expensiveWeapon);
	}

	return weaponsGot;
}

void Shop::shop(Player *player) {
	bool exit = false;
	weaponsForSale = getWeaponsForSale(player->getWeapon());


	/*Item("Ketchup Packet", 100, 75, "Heals 100 HP", "HP"),
	Item("Mustard Packet", 100, 75, "Recovers 100 MP", "MP"),
	Item("Thousand Island Packet", 250, 150, "Heals and Recovers 150 HP and MP", "HP&MP"),
	Item("Ketchup Bottle", 300, 250, "Heals 250 HP", "HP"),
	Item("Mustard Bottle", 300, 300, "Recovers 250 MP", "MP"),
	Item("Ranch Bottle", 0, 450, "Cures all status effects", "Cure"),
	Item("Thousand Island Bottle", 500, 1000, "Heals and Recovers 500 HP and MP", "HP&MP")*/


	//Remove items from item pool depending on what point of the story player is at.
	if (player->getPosInStory() < 7) {
		items.erase(items.begin() + 6);
	}
	if (player->getPosInStory() < 6) {
		items.erase(items.begin() + 5);
	}
	if (player->getPosInStory() < 5) {
		items.erase(items.begin() + 4);
	}
	if (player->getPosInStory() < 4) {
		items.erase(items.begin() + 3);
	}
	if (player->getPosInStory() < 3) {
		items.erase(items.begin() + 2);
	}

	while (!exit) {
		int option = displayDeals(player);
		//Leave shop
		if (option == -2) {
			exit = true;
			break;
		}

	}
}

int Shop::displayDeals(Player *player) {
	Weapon currentWeapon = player->getWeapon();
	int money = player->getMoney();
	int option = 0;
	int confirm = 0;


	cout << "\"What can I do for ya?\"" << endl << "(You currently have " << money << " gold)" << endl << endl;
	cout << "[1] Weapons" << endl;
	cout << "[2] Items" << endl;

	cout << endl << "[0] Leave Shop" << endl << endl;

	cin >> option;
	while (option < 0 || option > 3 || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pick a number between 0 and 3" << endl;
		cin >> option;
	}

	switch (option) {
		//[1] Weapons
	case 1:
		//TODO: randomize greeting maybe :)
		cout << "\"Here's what I got in stock today.\"" << endl << endl;
		for (int i = 0; i < weaponsForSale.size(); i++) {
			//Not enough money, gray out.
			if ((player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[i].getPrice()) {
				SetConsoleTextAttribute(hConsole, 8);
			}
			cout << "[" << i + 1 << "] " << weaponsForSale[i].getName() << " (" << weaponsForSale[i].getPrice() << " gold)" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl << "[0] Nevermind" << endl;

		cin >> option;
		while (option < 1 || option > weaponsForSale.size() || cin.fail() || (player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[option - 1].getPrice()) {

			cin.clear();
			cin.ignore(256, '\n');
			//Send player back to shop menu
			if (option == 0) {
				return 0;
			}
			else if (option < 1 || option > weaponsForSale.size()) {
				cout << "Pick a number between 1 and " << weaponsForSale.size() << endl;
			}
			//If selling current weapon at half price + current money still doesn't pay for weapon, deny the purchase.
			else if ((player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy.\"" << endl;
			}
			else {
				cout << "Pick a number between 1 and " << weaponsForSale.size() << endl;
			}

			cin >> option;
		}

		if (option == 0) {
			return 0;
		}
		else {
			cout << endl << "--------------------------------------" << endl;
			cout << "Name: " << weaponsForSale[option - 1].getName() << endl;
			cout << "Description: " << weaponsForSale[option - 1].getDescription() << endl;
			cout << "DMG: " << weaponsForSale[option - 1].getDamage() << endl;
			cout << "Cost: " << weaponsForSale[option - 1].getPrice() << endl;
			cout << "--------------------------------------" << endl << endl;
			Sleep(1500);

			while ((player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy.\"" << endl;
			}

			cout << "Sell your " << currentWeapon.getName() << " for " << currentWeapon.getPrice() / 2 << " gold and purchase " << weaponsForSale[option - 1].getName() << " for " << weaponsForSale[option - 1].getPrice() << " gold?" << endl;
			cout << endl << "[1] Confirm purchase" << endl;
			cout << "[0] Nevermind" << endl;

			cin >> confirm;
			while (confirm < 0 || confirm > 1 || cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Pick a number between 0 and 1" << endl;
				cin >> confirm;
			}

			if (confirm == 1) {
				player->setMoney((player->getMoney() + (currentWeapon.getPrice() / 2)) - weaponsForSale[option - 1].getPrice());
				cout << endl << "\"Congratulations lad, yer now the proud owner of a " << weaponsForSale[option - 1].getName() << "\"" << endl << endl;
				weaponsForSale.push_back(currentWeapon);
				player->setWeapon(weaponsForSale[option - 1]);
				weaponsForSale.erase(weaponsForSale.begin() + option - 1);
				confirm = 0;
			}
			return 0;

		}

		//[2] Item
	case 2:
		cout << "\"Here's what I got in stock today.\"" << endl << endl;
		for (int i = 0; i < items.size(); i++) {
			//Not enough money, gray out.
			if (player->getMoney() < items[i].getPrice()) {
				SetConsoleTextAttribute(hConsole, 8);
			}
			cout << "[" << i + 1 << "] " << items[i].getName() << " (" << items[i].getPrice() << " gold)" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl << "[0] Nevermind" << endl << endl;
		cin >> option;
		while (option < 1 || option > items.size() || cin.fail() || player->getMoney() < items[option - 1].getPrice()) {
			cin.clear();
			cin.ignore(256, '\n');
			//Send player back to shop menu
			if (option == 0) {
				return 0;
			}
			else if (option < 1 || option > items.size()) {
				cout << "Pick a number between 1 and " << items.size() << endl;
			}
			//If selling current weapon at half price + current money still doesn't pay for weapon, deny the purchase.
			else if (player->getMoney() < items[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy. \"" << endl;
			}
			else {
				cout << "Pick a number between 1 and " << items.size() << endl;
			}

			cin >> option;
		}

		if (option == 0) {
			return 0;
		}
		else {
			cout << endl << "--------------------------------------" << endl;
			cout << "Name: " << items[option - 1].getName() << endl;
			cout << "Description: " << items[option - 1].getDescription() << endl;
			cout << "Cost: " << items[option - 1].getPrice() << endl;
			cout << "--------------------------------------" << endl << endl;
			Sleep(1500);
			while (player->getMoney() < items[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy. \"" << endl;
			}

			cout << "Buy " << items[option - 1].getName() << " for " << items[option - 1].getPrice() << " gold?" << endl;
			cout << "[1] Confirm purchase" << endl;
			cout << endl << "[0] Nevermind" << endl;

			cin >> confirm;
			while (confirm < 0 || confirm > 1 || cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Pick a number between 0 and 1" << endl;
				cin >> confirm;
			}

			if (confirm == 1) {
				player->setMoney(player->getMoney() - items[option - 1].getPrice());
				cout << endl << "\"Congratulations lad, yer now the proud owner of a " << items[option - 1].getName() << "\"" << endl << endl;
				player->addItem(items[option - 1]);
				confirm = 0;
			}
			return 0;

		}


	default:
		return -2;
		break;
	}

	return -2;
}

int Shop::randomNumber(int num, int plus) {
	return (rand() % num + plus);
}


void Shop::requestShop(Player *player) {
	cout << endl << "Welcome to the Shop!" << endl << "====================" << endl << endl;
	shop(player);

	cout << endl << "\"See ya later!\"" << endl << endl;
	Sleep(1500);
}


Shop::~Shop()
{
}
