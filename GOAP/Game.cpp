#include "Game.h"

Game::Game() {
	worldState = WorldState();
	goapSolver = GOAPSolver(worldState);
}
void Game::runGame() {
	vector<Enemy*> enemies = worldState.getEnemies();
	vector<Action*> actionsSequence;
	while (enemies.size() > 0)
	{
		int actionsSequenceSize = actionsSequence.size();
		bool shouldBreak = false;
		for (int i = 0; i < actionsSequenceSize; ++i) {
			if (i < actionsSequenceSize - 1) {
				while (goapSolver.getFirstUnvalidPrecondition(actionsSequence[i + 1]) != nullptr) {
					if (goapSolver.getFirstUnvalidPrecondition(actionsSequence[i]) == nullptr) {
						actionsSequence[i]->getEffect()->execute();
					}
					else {
						//refaire le solve et remplacer la séquence
						shouldBreak = true;
						break;
					}
				}
				if (shouldBreak) {
					break;
				}
			}
			else
			{
				if (goapSolver.getFirstUnvalidPrecondition(actionsSequence[i]) == nullptr) {
					actionsSequence[i]->getEffect()->execute();
				}
				else {
					//refaire le solve et remplacer la séquence
					break;
				}
			}
		}
	}
}