#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Potion.h"
#include <vector>

using namespace std;

class WorldState
{
private:
	Player* player;
	vector<Enemy*> enemies;
	vector<Potion*> potions;
public:
	WorldState();
	Player* getPlayer();
	vector<Enemy*> getEnemies();
	vector<Potion*> getPotions();
};

