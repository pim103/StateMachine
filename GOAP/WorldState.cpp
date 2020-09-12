#include "WorldState.h"

WorldState::WorldState() {
	player = new Player();
	int x, y;

	for (int i = 0; i < 3; ++i) {
		bool positionAlreadyExist;

		do {
			positionAlreadyExist = false;
			x = rand() % 10;
			y = rand() % 10;

			int enemiesSize = enemies.size();
			for (int j = 0; j < enemiesSize; ++j) {
				vector<int> pos = enemies[j]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}
		} while (positionAlreadyExist);

		enemies.push_back(new Enemy(x, y));
	}
	
	for (int i = 0; i < 5; ++i) {
		bool positionAlreadyExist;

		do {
			positionAlreadyExist = false;
			x = rand() % 10;
			y = rand() % 10;

			int enemiesSize = enemies.size();
			for (int j = 0; j < enemiesSize; ++j) {
				vector<int> pos = enemies[j]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}

			int potionsSize = potions.size();
			for (int j = 0; j < potionsSize; ++j) {
				vector<int> pos = potions[j]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}
		} while (positionAlreadyExist);

		potions.push_back(new Potion(x, y));
	}
}

Player* WorldState::getPlayer() {
	return player;
}

vector<Enemy*> WorldState::getEnemies() {
	return enemies;
}

vector<Potion*> WorldState::getPotions() {
	return potions;
}

void WorldState::deleteWorld() {
	int enemiesSize = enemies.size();
	int potionSize = potions.size();

	for (int i = 0; i < enemiesSize; ++i) {
		delete enemies[i];
	}

	for (int i = 0; i < potionSize; ++i) {
		delete potions[i];
	}

	delete player;
}