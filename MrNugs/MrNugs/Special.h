//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
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
	string getName();
	int getMPCost();
	string getDescription();
	string getEffect();
	int getDuration();
	void setEffect(string effect);
};

