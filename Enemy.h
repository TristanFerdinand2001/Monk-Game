#pragma once
#include <string>
using namespace std;

class Enemy {
private:
	string enemyName;
	int enemyAP;
	int enemyCurrentHP;
	int enemyMaxHP;


public:
	Enemy(string name, int hp, int ap);

	string getName();
	int getEnemyCurrentHP();
	void setEnemyCurrentHP(int newMaxHP);
	int getEnemyAP();
	int getEnemyMaxHP();


};