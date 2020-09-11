#include "GOAPSolver.h"


GOAPSolver::GOAPSolver(WorldState nWorldState) {
	worldState = nWorldState;

	Precondition* preconditionDrinkPotion = new Precondition(PreconditionType::HAS_POTION, 1, 1);
}

void GOAPSolver::solve() {
	vector<Enemy*> enemies = worldState.getEnemies();
	vector<Precondition*> preconditionsToFill;
	while (enemies.size() > 0) {
		preconditionsToFill = checkPreconditions(currentGoal);
		int preconditionsToFillSize = preconditionsToFill.size();
		if (preconditionsToFillSize > 0) {
			for (int i = 0; i < preconditionsToFillSize; ++i) {

			}
		}
		else {
			currentGoal->executeAction();
			currentGoal = topGoal;
		}
	}
}

vector<Precondition*> GOAPSolver::checkPreconditions(Action* action) {
	vector<Precondition*> preconditionsList = action->getPreconditions();
	Effect effect = action->getEffect();
	int preconditionSize = preconditionsList.size();
	Player* player = worldState.getPlayer();
	vector<Enemy*> enemies = worldState.getEnemies();
	vector<Potion*> potions = worldState.getPotions();
	vector<Precondition*> preconditionsToFill;
	int preconCpt = 0;

	for (int i = 0; i < preconditionSize; ++i) {
		switch (preconditionsList[i]->getType())
		{
		case IS_IN_RANGE:
			if (effect == Effect::DO_DAMAGES) {
				int enemiesSize = enemies.size();
				for (int j = 0; j < enemiesSize; ++j) {
					if (sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2)) > preconditionsList[i]->getAmount()) {
						preconditionsToFill.push_back(preconditionsList[i]);
					}
				}
			}
			else {
				int potionsSize = potions.size();
				for (int j = 0; j < potionsSize; ++j) {
					if (sqrt(pow((player->getPos()[0] - potions[i]->getPos()[0]), 2) + pow((player->getPos()[1] - potions[i]->getPos()[1]), 2)) > preconditionsList[i]->getAmount()) {
						preconditionsToFill.push_back(preconditionsList[i]);
					}
				}
			}
			
			break;
		case HAS_MANA:
			if (player->getMana() < preconditionsList[i]->getAmount()) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		case HAS_POTION:
			if (potions.size() < preconditionsList[i]->getAmount()) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		default:
			break;
		}
	}

	return preconditionsToFill;
	/*if (preconCpt >= preconditionSize) {
		return true;
	}
	else
	{
		return false;
	}*/
}