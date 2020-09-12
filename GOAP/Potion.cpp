#include "Potion.h"

Potion::Potion(int posX, int posY) {
	pos.push_back(posX);
	pos.push_back(posY);
}

void Potion::setPos(int nposX, int nposY) {
	pos[0] = nposX;
	pos[1] = nposY;
}

vector<int> Potion::getPos() const {
	return pos;
}