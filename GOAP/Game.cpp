#include "Game.h"

Game::Game() {
	worldState = new WorldState();
	goapSolver = GOAPSolver(worldState);
}

void Game::runGame() {
	vector<Enemy*> enemies = worldState->getEnemies();
	vector<const Action*> actionsSequence = goapSolver.solve();
	int nbLoop = 0;

	while (enemies.size() > 0 && nbLoop < 50)
	{
		++nbLoop;

		enemies = worldState->getEnemies();
		cout << "Enemies remaining : " << enemies.size() << endl;

		int actionsSequenceSize = actionsSequence.size();
		bool shouldBreak = false;

		for (int i = 0; i < actionsSequenceSize; ++i) {
			if (i < actionsSequenceSize - 1) {
				int nbLoop2 = 0;
				while (goapSolver.getUnvalidPreconditions(actionsSequence[i + 1]).size() != 0 && nbLoop2 < 25) {
					++nbLoop2;
					if (goapSolver.getUnvalidPreconditions(actionsSequence[i]).size() == 0) {
						cout << "Notre position : " << worldState->getPlayer()->getPos()[0] << " " << worldState->getPlayer()->getPos()[1] << endl;
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
					cout << "achever last" << endl;
					actionsSequence[i]->getEffect()->execute(worldState);
				}

				actionsSequence = goapSolver.solve();
			}
		}
	}

	worldState->deleteWorld();
	goapSolver.deleteGoap();
	delete worldState;
}