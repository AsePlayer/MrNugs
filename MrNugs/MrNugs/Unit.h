#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Special.h"
#include "Item.h"
using namespace std;
class Unit
{

	string NAME = "Unit";
	string TYPE = "Default";
	string DESC = "Default Description";

	vector<Special> moves = { Special{"Special",5,"special description", "None", 0} };
	vector<Special> unlockedMoves = { Special{"Special",5,"special description", "None", 0} };
	int bleed, stun;

	int LVL = -1000;
	int MAXHP = -1000;
	int HP = -1000;
	int MAXMP = -1000;
	int MP = -1000;
	int DMG = -1000;
	int DEF = -1000;
	int GOLD = -1000;
	int XP = -1000;
	int damage = -1000;
	bool isDead = false;
public:
	Unit();
	~Unit();

	virtual void decideDamage(string attackName);

	void setLVL(int lvl);

	virtual void setPlayerLVL(int lvl);

	int randomNumber(int num, int plus);

	virtual string customAI(int HP);

	virtual vector<Special> getMoves();

	virtual vector<Item> getItems();

	virtual void removeItem(int num);

	virtual void updatePlayer(int exp, int gold);

	void heal(int value);

	void recover(int value);

	void cureStatusEffects();

	string getNAME();
	string getTYPE();
	string getDESC();
	int getXP();
	int getGOLD();
	int getLVL();
	int getMAXHP();
	int getHP();
	int getMAXMP();
	int getMP();
	int getDMG();
	int getDEF();
	int getdamage();
	bool getIsDead();
	vector<int> getStatusEffects();
	
	void setStatusEffects(string effect, int amount);

	void setNAME(string name);
	void setTYPE(string type);
	void setDESC(string desc);
	void setXP(int xp);
	void setGOLD(int gold);
	void setMAXHP(int maxhp);
	void setHP(int hp);
	void setMAXMP(int maxmp);
	void setMP(int mp);
	void setDMG(int dmg);
	void setDEF(int def);
	void setdamage(int passDamage);
	void setIsDead(bool dead);



};
