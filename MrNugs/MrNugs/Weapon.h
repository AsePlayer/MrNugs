//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
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
	string getName();
	int getDamage();
	string getDescription();
	int getPrice();
	void increaseDamage();
};

