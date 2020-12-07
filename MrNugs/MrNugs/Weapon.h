#pragma once
#include <vector>
using namespace std;


class Weapon
{
private:
	string name;
	string description;
	int damage;
	int price;

public:
	Weapon(string name, int damage, string description, int price);
	~Weapon();
	string getName() {
		return name;
	}
	int getDamage() {
		return damage;
	}
	string getDescription() {
		return description;
	}
	int getPrice() {
		return price;
	}
};

