#pragma once
#include <string>
using namespace std;
class Special
{
private:

	string name;
	string description;
	int MPCost;
	string effect;
	int duration;

public:
	Special(string name, int MPCost, string description, string effect, int duration);
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
	string getEffect() {
		return effect;
	}
	int getDuration() {
		return duration;
	}
};

