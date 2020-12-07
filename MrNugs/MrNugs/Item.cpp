#include "pch.h"
#include "Item.h"


Item::Item(string name, int value, int price, string description, string type)
{
	this->name = name;
	this->value = value;
	this->price = price;
	this->description = description;
	this->type = type;
}


Item::~Item()
{
}
