#include "Enemy.h"


Enemy::Enemy(int posX, int posY) {
	hp = 10;
	pos.push_back(posX);
	pos.push_back(posY);
}

int Enemy::getHp() {
	return hp;
}

void Enemy::setHp(int nHp) {
	hp = nHp;
}

void Enemy::setPos(int nposX, int nposY) {
	pos[0] = nposX;
	pos[1] = nposY;
}

vector<int> Enemy::getPos() {
	return pos;
}
