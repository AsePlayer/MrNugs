//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include <string>
using namespace std;
class Item
{
private:
	string name;
	string description;
	string type;
	int value;
	int price;

public:
	Item(string name, int value, int price, string description, string type);
	~Item();

	string getName();
	int getValue();
	int getPrice();
	string getDescription();
	string getType();
};

