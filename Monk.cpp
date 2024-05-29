#include "Monk.h"
#include "Character.h"
#include <string>
using namespace std;


//Default Constructor 
Monk::Monk(string name, string description) : Character(name, description)
{
	monkName = name;
	monkDescription = description;
	setMonkAP(3);
	setMaxHP(15);
	setCurrentHP(maxHP);
}
	

//Getters and setters
string Monk::getName()
{
	return monkName;
}
void Monk::setName(string name)
{
	monkName = name;
}

string Monk::getDescription()
{
	return monkDescription;
}
void Monk::setDescription(string description)
{
	monkDescription = description;
}

int Monk::getMonkAP()
{
	 return monkAP;
}
void Monk::setMonkAP(int newAP)
{
	 monkAP = newAP;
}

int Monk::getCurrentHP()
{
	 return currentHP;
}
void Monk::setCurrentHP (int newHP)
{
	 currentHP = newHP;
}

int Monk::getMaxHP()
{
	 return maxHP;
}
void Monk::setMaxHP(int newMaxHP)
{
	 maxHP = newMaxHP;
}








