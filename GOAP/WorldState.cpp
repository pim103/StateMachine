#include "WorldState.h"

WorldState::WorldState() {
	player = new Player();
	for (int i = 0; i < 3; ++i) {
		bool positionAlreadyExist;
		int x, y;

		do {
			positionAlreadyExist = false;
			int x = rand() % 10;
			int y = rand() % 10;

			int enemiesSize = enemies.size();
			for (int j = 0; j < enemiesSize; ++j) {
				vector<int> pos = enemies[i]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}
		} while (positionAlreadyExist);

		enemies.push_back(new Enemy(x, y));
	}

	for (int i = 0; i < 5; ++i) {
		bool positionAlreadyExist;
		int x, y;

		do {
			positionAlreadyExist = false;
			int x = rand() % 10;
			int y = rand() % 10;

			int enemiesSize = enemies.size();
			for (int j = 0; j < enemiesSize; ++j) {
				vector<int> pos = enemies[i]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}

			int potionsSize = potions.size();
			for (int j = 0; j < potionsSize; ++j) {
				vector<int> pos = potions[i]->getPos();

				if (pos[0] == x && pos[1] == y) {
					positionAlreadyExist = true;
				}
			}
		} while (positionAlreadyExist);

		potions.push_back(new Potion(x, y));
	}
}

void WorldState::runWorld() {
	int turnCount = 0;
	while (turnCount < 100) {
		
		++turnCount;
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