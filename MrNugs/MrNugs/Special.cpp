#include "pch.h"
#include "Special.h"


Special::Special(string name, int MPCost, string description, string effect, int duration)
{
	this->name = name;
	this->MPCost = MPCost;
	this->description = description;
	this->effect = effect;
	this->duration = duration;
}

string Special::getName() {
	return name;
}
int Special::getMPCost() {
	return MPCost;
}
string Special::getDescription() {
	return description;
}
string Special::getEffect() {
	return effect;
}
int Special::getDuration() {
	return duration;
}


Special::~Special()
{
}
