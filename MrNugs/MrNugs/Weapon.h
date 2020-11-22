#pragma once
#include <vector>
using namespace std;


class Weapon
{
private:
	

	string name;
	string description;
	int damage;

public:
	Weapon(string name, int damage, string description);
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
};

