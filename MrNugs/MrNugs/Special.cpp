#include "pch.h"
#include "Special.h"


Special::Special(string name, int MPCost, string description)
{
	this->name = name;
	this->MPCost = MPCost;
	this->description = description;
}


Special::~Special()
{
}
