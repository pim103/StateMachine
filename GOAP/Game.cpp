#include "Game.h"

Game::Game() {
	worldState = new WorldState();
	goapSolver = GOAPSolver(worldState);
}
void Game::runGame() {
	vector<Enemy*> enemies = worldState->getEnemies();
	vector<Action*> actionsSequence = goapSolver.solve();


	while (enemies.size() > 0)
	{
		int actionsSequenceSize = actionsSequence.size();
		bool shouldBreak = false;
		for (int i = 0; i < actionsSequenceSize; ++i) {
			if (i < actionsSequenceSize - 1) {
				while (goapSolver.getUnvalidPreconditions(actionsSequence[i + 1]).size() != 0) {
					if (goapSolver.getUnvalidPreconditions(actionsSequence[i]).size() == 0) {
						actionsSequence[i]->getEffect()->execute(worldState);
						cout << "action done : " << actionsSequence[i]->getDescription() << endl;
					}
					else {
						//refaire le solve et remplacer la séquence
						actionsSequence = goapSolver.solve();
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
				if (goapSolver.getUnvalidPreconditions(actionsSequence[i]).size() == 0) {
					actionsSequence[i]->getEffect()->execute(worldState);
				}
				else {
					//refaire le solve et remplacer la séquence
					actionsSequence = goapSolver.solve();
					break;
				}
			}
		}
	}

	worldState->deleteWorld();
	goapSolver.deleteGoap();
	delete worldState;
}