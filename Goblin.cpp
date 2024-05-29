#include "Goblin.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

//Getters and setters for the enemy/goblin
string Goblin::getName()
{
	return enemyName;
}

int Goblin::getEnemyCurrentHP()
{
	return enemyCurrentHP;
}

int Goblin::getEnemyAP()
{
	return enemyAP;
}

int Goblin::getEnemyMaxHP()
{
	return enemyMaxHP;
}
