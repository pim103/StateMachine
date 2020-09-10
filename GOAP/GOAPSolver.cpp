#include "GOAPSolver.h"


GOAPSolver::GOAPSolver(WorldState nWorldState) {
	worldState = nWorldState;
}

void GOAPSolver::solve() {

}

bool GOAPSolver::checkPreconditions(Action action) {
	vector<Precondition> preconditionsList = action.getPreconditions();
	Effect effect = action.getEffect();
	int preconditionSize = preconditionsList.size();
	Player player = worldState.getPlayer();
	vector<Enemy> enemies = worldState.getEnemies();
	vector<Potion> potions = worldState.getPotions();

	for (int i = 0; i < preconditionSize; ++i) {
		switch (preconditionsList[i])
		{
		case Precondition::IS_IN_RANGE:
			if (effect == Effect::DO_DAMAGES) {
				int enemiesSize = enemies.size();
				for (int j = 0; j < enemiesSize; ++j) {
					if (sqrt(pow((player.getPos()[0] - enemies[i].getPos()[0]), 2) + pow((player.getPos()[1] - enemies[i].getPos()[1]), 2)) < 4) {
						//valider la condition
					}
				}
			}
			else {

			}
			
			break;
		case Precondition::HAS_MANA:
			break;
		case Precondition::HAS_POTION:
			break;
		default:
			break;
		}
	}
}