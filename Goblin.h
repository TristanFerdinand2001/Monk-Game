#pragma once
#include <string>
#include "Enemy.h"

class Goblin : public  Enemy {
private:
	string enemyName;
	int enemyAP;
	int enemyCurrentHP;
	int enemyMaxHP;

public:
    Goblin(string name, int hp, int ap) : Enemy(name, hp, ap) {}

	string getName();
	int getEnemyCurrentHP();
	int getEnemyAP();
	int getEnemyMaxHP();


};

