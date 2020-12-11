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

string Item::getName() {
	return name;
}
int Item::getValue() {
	return value;
}
int Item::getPrice() {
	return price;
}
string Item::getDescription() {
	return description;
}
string Item::getType() {
	return type;
}

Item::~Item()
{
}
