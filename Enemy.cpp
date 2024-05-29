#include "Enemy.h"

Enemy::Enemy(string name, int hp, int ap): enemyName(name), enemyMaxHP(hp), enemyCurrentHP(hp), enemyAP(ap) {}

//Getters and Setters
string Enemy::getName() {
    return enemyName;
}

int Enemy::getEnemyCurrentHP() {
    return enemyCurrentHP;
}

int Enemy::getEnemyAP() {
    return enemyAP;
}

void Enemy::setEnemyCurrentHP(int newHP) {
    enemyCurrentHP = newHP;
}

int Enemy::getEnemyMaxHP() {
    return enemyMaxHP;
}