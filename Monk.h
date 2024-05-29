#pragma once
#include <string>
#include "Character.h"
using namespace std;


class Monk : public Character {
private:
	string monkName;
	string monkDescription;	
	int monkAP;
	int currentHP;
	int maxHP;


public:
	Monk(string name, string description);

	string getName();
	void setName(string name);

	string getDescription();
	void setDescription(string description);

	int getMonkAP();
	void setMonkAP(int newAP);

	int getCurrentHP();
	void setCurrentHP(int newHP);

    int getMaxHP();
	void setMaxHP(int newMaxHP);

};
