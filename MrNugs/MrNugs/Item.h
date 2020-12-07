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

	string getName() {
		return name;
	}
	int getValue() {
		return value;
	}
	int getPrice() {
		return price;
	}
	string getDescription() {
		return description;
	}
	string getType() {
		return type;
	}
};

