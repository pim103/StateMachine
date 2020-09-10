#include "WorldState.h"


WorldState::WorldState() {
	player = Player();
	for (int i = 0; i < 3; ++i) {
		enemies.push_back(Enemy(rand() % 10, rand() % 10));
		/*int enemiesSize = Enemies.size();
		for (int j = 0; j < enemiesSize; ++j) {
			if (Enemies[i].getPos() == Enemies[enemiesSize - 1].getPos()) {

			}
		}*/
	}
	for (int i = 0; i < 5; ++i) {
		potions.push_back(Potion(rand() % 10, rand() % 10));
	}
}

void WorldState::runWorld() {
	int turnCount = 0;
	while (turnCount < 100) {
		
		++turnCount;
	}
}

Player WorldState::getPlayer() {
	return player;
}

vector<Enemy> WorldState::getEnemies() {
	return enemies;
}

vector<Potion> WorldState::getPotions() {
	return potions;
}