#include "pch.h"
#include "Shop.h"
#include "Player.h"


Shop::Shop()
{

}

vector<Weapon> Shop::getWeaponsForSale(Weapon currentWeapon) {
	vector<Weapon> weaponsGot;
	int cheapNumber = randomNumber(cheapWeapons.size(), 0);
	int expensiveNumber = randomNumber(expensiveWeapons.size(), 0);

	Weapon cheapWeapon = cheapWeapons[cheapNumber];
	Weapon expensiveWeapon = expensiveWeapons[expensiveNumber];

	//Refresh weapon for sale if it is a weapon the player currently has.
	if (currentWeapon.getName() == cheapWeapon.getName()) {
		cheapWeapons.erase(cheapWeapons.begin() + cheapNumber);
		cheapNumber = randomNumber(cheapWeapons.size() - 1, 0);
		cheapWeapon = cheapWeapons[cheapNumber];
	}
	else if (currentWeapon.getName() == expensiveWeapon.getName()) {
		expensiveWeapons.erase(expensiveWeapons.begin() + expensiveNumber);
		expensiveNumber = randomNumber(expensiveWeapons.size() - 1, 0);
		expensiveWeapon = expensiveWeapons[expensiveNumber];
	}

	weaponsGot.push_back(cheapWeapon);
	weaponsGot.push_back(expensiveWeapon);

	return weaponsGot;
}

void Shop::shop(Player *player) {
	bool exit = false;
	weaponsForSale = getWeaponsForSale(player->getWeapon());

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
			//If selling current weapon at half price + current money still doesn't pay for weapon, deny the purchase.
			else if ((player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy. \"" << endl;
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
			cout << endl << "Name: " << weaponsForSale[option - 1].getName() << endl;
			cout << "Description: " << weaponsForSale[option - 1].getDescription() << endl;
			cout << "DMG: " << weaponsForSale[option - 1].getDamage() << endl;
			cout << "Cost: " << weaponsForSale[option - 1].getPrice() << endl << endl;

			while ((player->getMoney() + (currentWeapon.getPrice() / 2)) < weaponsForSale[option - 1].getPrice()) {
				cout << "\"Yer pockets ain't deep enough, laddy. \"" << endl;
			}

			cout << "Sell your " << currentWeapon.getName() << " for " << currentWeapon.getPrice() / 2 << " gold and purchase " << weaponsForSale[option - 1].getName() << " for " << weaponsForSale[option - 1].getPrice() << " gold?" << endl;
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
			cout << endl << "Name: " << items[option - 1].getName() << endl;
			cout << "Description: " << items[option - 1].getDescription() << endl;
			cout << "Cost: " << items[option - 1].getPrice() << endl << endl;

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
