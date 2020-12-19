//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
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
void Special::setEffect(string effect) {
	this->effect = effect;
}


Special::~Special()
{
}
