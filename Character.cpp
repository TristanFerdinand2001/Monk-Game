#include "Character.h"
#include "Monk.h"
#include <string>
using namespace std;

 //Default constructor 
Character::Character(string name, string description)
	{
		characterName = name;
		characterDescription = description;
		setCharacterAP(3); 
		setMaxHP(15);
		setCurrentHP(maxHP);
	}

     
	///Getters and Setters
	string Character::getName()
	{
		return characterName;
	}
	void Character::setName(string name)
	{
		characterName = name;
	}

	string Character::getDescription()
	{
		return characterDescription;
	}
	void Character::setDescription(string description)
	{
		characterDescription = description;
	}

    int Character::getCharacterAP()
	{
		return characterAP;
	}
	void Character::setCharacterAP(int newAP)
	{
		characterAP = newAP;
	}

    int Character::getCurrentHP()
	{
		return currentHP;
	}
	void Character::setCurrentHP(int newHP)
	{
		currentHP = newHP;
	}
	int Character::getMaxHP()
	{
		return maxHP;
	}
	void Character::setMaxHP(int newMaxHP)
	{
		maxHP = newMaxHP;
	}

	

	





