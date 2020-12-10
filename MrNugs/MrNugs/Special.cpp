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


Special::~Special()
{
}
