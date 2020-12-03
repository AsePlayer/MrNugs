#pragma once
#include <string>
using namespace std;
class Special
{
public:

	string name;
	string description;
	int MPCost;

public:
	Special(string name, int MPCost, string description);
	~Special();
	string getName() {
		return name;
	}
	int getMPCost() {
		return MPCost;
	}
	string getDescription() {
		return description;
	}
};

