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
	Player* getPlayer() const;
	vector<Enemy*> getEnemies() const;
	vector<Potion*> getPotions() const;

	void setEnemies(vector<Enemy*> nEnemies);
	void setPotions(vector<Potion*> nPotion);
	void setPlayer(Player* nPlayer);

	void deleteWorld();
};

