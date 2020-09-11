#include "Player.h"

Player::Player() {
	maxMana = 20;
	currentMana = 20;
	pos.push_back(0);
	pos.push_back(0);
	potions = 1;
}

void Player::setPotions(int _potions) {
	potions = _potions;
}

int Player::getPotions() {
	return potions;
}

int Player::getMana() {
	return currentMana;
}

void Player::setMana(int mana) {
	currentMana = mana;
}

void Player::setPos(int nposX, int nposY) {
	pos[0] = nposX;
	pos[1] = nposY;
}

vector<int> Player::getPos() {
	return pos;
}
