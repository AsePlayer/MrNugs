//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Item.h"
#include <vector>
#include <iostream>  
using namespace std;
class Player
{
private:
	string name;
	int lvl;
	int money;
	int exp;
	vector<int> expThresholds{0,10,50,75,100,150,200,250,500,1000};
	Weapon weapon = Weapon("default",0,"default constructor", 0);
	vector<Item> items = {};
	string characterClass;
	int posInStory;
	//vector for items later
public:
	Player(string name, int lvl, int exp, Weapon weapon, int money, vector<Item> items, string characterClass, int posInStory);
	~Player();

	string getName();

	string getCharacterClass();

	int getPosInStory();
	
	int getLVL();

	int getEXP();

	Weapon getWeapon();

	vector<Item> getItems();

	int getMoney();

	void setLVL(int lvl);

	void setWeapon(Weapon weapon);

	void setItems(vector<Item> items);

	void addItem(Item item);

	void removeItem(int itemIndex);

	void setMoney(int money);

	void updateEXP(int exp);

	void setCharacterClass(string characterClass);

	void setPosInStory(int posInStory);



	
};

