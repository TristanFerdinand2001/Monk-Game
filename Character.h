#pragma once
#include <string>
using namespace std;

class Character {
private:
	string characterName;
	string characterDescription;
	int characterAP;
	int currentHP;
	int maxHP;


public:
	Character(string name, string description);

	string getName();
	void setName(string name);

	string getDescription();
	void setDescription(string description);

	int getCharacterAP();
	void setCharacterAP(int newAP);

	int getCurrentHP();
	void setCurrentHP(int newHP);

	int getMaxHP();
	void setMaxHP(int newMaxHP);
};