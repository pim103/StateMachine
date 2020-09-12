#include "GOAPSolver.h"

GOAPSolver::GOAPSolver() {

}
GOAPSolver::GOAPSolver(WorldState*nWorldState) {
	worldState = nWorldState;

	// =================== INIT EFFECTS =================== //
	const Effect* enemyDies = new Effect(EffectType::KILL_ENEMY, 1, [](WorldState* worldState) {
		cout << "called enemydies" << endl;
		vector<Enemy*> enemies = worldState->getEnemies();
		Player* player = worldState->getPlayer();
		int enemiesSize = enemies.size();
		int minDistance = 10000;
		Enemy* currentEnemy = enemies[0];
		for (int i = 0; i < enemiesSize; ++i) {
			if (enemies[i]->getHp() <= 0) {
				cout << "enemy dead" << endl;
				currentEnemy = enemies[i];
				enemies.erase(enemies.begin()+i);
				delete currentEnemy;
				break;
			}
		}
	});
	
	const Effect* attackDamages = new Effect(EffectType::DO_DAMAGES, 1, [](WorldState* worldState) {
		vector<Enemy*> enemies = worldState->getEnemies();
		Player* player = worldState->getPlayer();
		int enemiesSize = enemies.size();
		int minDistance = 10000;
		Enemy* currentEnemy = enemies[0];
		for (int i = 0; i < enemiesSize; ++i) {
			int dist = sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2));
			if (dist < minDistance) {
				minDistance = dist;
				currentEnemy = enemies[i];
			}
		}
		currentEnemy->setHp(currentEnemy->getHp()-1);
	});
	
	const Effect* spellDamages = new Effect(EffectType::DO_DAMAGES, 4, [](WorldState* worldState) {
		vector<Enemy*> enemies = worldState->getEnemies();
		Player* player = worldState->getPlayer();
		int enemiesSize = enemies.size();
		int minDistance = 10000;
		Enemy* currentEnemy = enemies[0];
		for (int i = 0; i < enemiesSize; ++i) {
			int dist = sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2));
			if (dist < minDistance) {
				minDistance = dist;
				currentEnemy = enemies[i];
			}
		}
		currentEnemy->setHp(currentEnemy->getHp()-4);
		player->setMana(player->getMana() - 3);
	});
	
	const Effect* getPotion = new Effect(EffectType::GET_POTION, 1, [](WorldState* worldState) {
		vector<Potion*> potions = worldState->getPotions();
		Player* player = worldState->getPlayer();
		int potionsSize = potions.size();
		int minDistance = 10000;
		Potion* currentPotion = potions[0];
		int currentPotionIndex = 0;
		for (int i = 0; i < potionsSize; ++i) {
			int dist = sqrt(pow((player->getPos()[0] - potions[i]->getPos()[0]), 2) + pow((player->getPos()[1] - potions[i]->getPos()[1]), 2));
			if (dist < minDistance) {
				minDistance = dist;
				currentPotion = potions[i];
				currentPotionIndex = i;
			}
		}
		player->setPotions(player->getPotions() + 1);
		//remove potion
		potions.erase(potions.begin() + currentPotionIndex);
		delete currentPotion;
	});
	
	const Effect* getManaWithPotion = new Effect(EffectType::GET_MANA, 6, [](WorldState* worldState) {
		Player* player = worldState->getPlayer();
		player->setPotions(player->getPotions() - 1);
		player->setMana(player->getMana() + 6);
	});
	
	const Effect* getManaWithRegen = new Effect(EffectType::GET_MANA, 2, [](WorldState* worldState) {
		Player* player = worldState->getPlayer();
		player->setMana(player->getMana() + 2);
	});

	const Effect* moveTowardsClosestEnemy = new Effect(EffectType::MOVE_TOWARDS_ENEMY, 1, [](WorldState* worldState) {
		vector<Enemy*> enemies = worldState->getEnemies();
		Player* player = worldState->getPlayer();
		int enemiesSize = enemies.size();
		int minDistance = 10000;
		Enemy* currentEnemy = enemies[0];
		for (int i = 0; i < enemiesSize; ++i) {
			int dist = sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2));
			if (dist < minDistance) {
				minDistance = dist;
				currentEnemy = enemies[i];
			}
		}
		vector<int> enemyPos = currentEnemy->getPos();
		vector<int> playerPos = player->getPos();
		if (enemyPos[0] < playerPos[0]) {
			player->setPos(playerPos[0] - 1, playerPos[1]);
		}
		else if (enemyPos[0] > playerPos[0]) {
			player->setPos(playerPos[0] + 1, playerPos[1]);
		} 
		else if (enemyPos[1] < playerPos[1]) {
			player->setPos(playerPos[0], playerPos[1] - 1);
		}
		else if (enemyPos[0] > playerPos[0]) {
			player->setPos(playerPos[0], playerPos[1] + 1);
		}
	});
	
	const Effect* moveTowardsClosestPotion = new Effect(EffectType::MOVE_TOWARDS_POTION, 1, [](WorldState* worldState) {
		vector<Potion*> potions = worldState->getPotions();
		Player* player = worldState->getPlayer();
		int potionsSize = potions.size();
		int minDistance = 10000;
		Potion* currentPotion = potions[0];
		for (int i = 0; i < potionsSize; ++i) {
			int dist = sqrt(pow((player->getPos()[0] - potions[i]->getPos()[0]), 2) + pow((player->getPos()[1] - potions[i]->getPos()[1]), 2));
			if (dist < minDistance) {
				minDistance = dist;
				currentPotion = potions[i];
			}
		}
		vector<int> potionPos = currentPotion->getPos();
		vector<int> playerPos = player->getPos();
		if (potionPos[0] < playerPos[0]) {
			player->setPos(playerPos[0] - 1, playerPos[1]);
		}
		else if (potionPos[0] > playerPos[0]) {
			player->setPos(playerPos[0] + 1, playerPos[1]);
		} 
		else if (potionPos[1] < playerPos[1]) {
			player->setPos(playerPos[0], playerPos[1] - 1);
		}
		else if (potionPos[0] > playerPos[0]) {
			player->setPos(playerPos[0], playerPos[1] + 1);
		}
	});


	effects.push_back(attackDamages);
	effects.push_back(spellDamages);
	effects.push_back(getPotion);
	effects.push_back(getManaWithPotion);
	effects.push_back(getManaWithRegen);
	effects.push_back(moveTowardsClosestEnemy);
	effects.push_back(moveTowardsClosestPotion);
	effects.push_back(enemyDies);

	// ================ INIT PRECONDITION ================ //

	const Precondition* preconditionDrinkPotion = new Precondition(PreconditionType::HAS_POTION, 1, EffectType::GET_POTION);
	const Precondition* preconditionBasicAttack = new Precondition(PreconditionType::IS_IN_RANGE_ENEMY, 2, EffectType::MOVE_TOWARDS_ENEMY);
	const Precondition* preconditionSpell = new Precondition(PreconditionType::IS_IN_RANGE_ENEMY, 3, EffectType::MOVE_TOWARDS_ENEMY);
	const Precondition* preconditionSpell2 = new Precondition(PreconditionType::HAS_MANA, 2, EffectType::GET_MANA);
	const Precondition* preconditionGetAPotion = new Precondition(PreconditionType::IS_IN_RANGE_POTION, 1, EffectType::MOVE_TOWARDS_POTION);
	const Precondition* preconditionKillEnemy = new Precondition(PreconditionType::ENEMY_AT_ZERO_HP, 1, EffectType::DO_DAMAGES);

	preconditions.push_back(preconditionDrinkPotion);
	preconditions.push_back(preconditionBasicAttack);
	preconditions.push_back(preconditionSpell);
	preconditions.push_back(preconditionSpell2);
	preconditions.push_back(preconditionGetAPotion);
	preconditions.push_back(preconditionKillEnemy);

	// ================ INIT ACTIONS ================ //

	vector<const Precondition*> preconditionsForAction;

	preconditionsForAction.push_back(preconditionBasicAttack);

	const Action* doABarrelRoll = new Action(1, attackDamages, 4, preconditionsForAction, "Faire une attaque simple");

	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionSpell2);
	preconditionsForAction.push_back(preconditionSpell);

	const Action* launchSpell = new Action(2, spellDamages, 1, preconditionsForAction, "Lancer un spell");
	
	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionDrinkPotion);

	const Action* drinkPotion = new Action(3, getManaWithPotion, 1, preconditionsForAction, "Boire une potion");

	preconditionsForAction.clear();

	const Action* moveTowardEnemy = new Action(4, moveTowardsClosestEnemy, 1, preconditionsForAction, "Bouger a distance d'un ennemi");
	const Action* moveTowardPotion = new Action(5, moveTowardsClosestPotion, 1, preconditionsForAction, "Bouger a distance d'une potion");

	preconditionsForAction.push_back(preconditionGetAPotion);

	const Action* getAPotion = new Action(6, getPotion, 1, preconditionsForAction, "Recuperer une potion");

	preconditionsForAction.clear();

	const Action* regenMan = new Action(7, getManaWithRegen, 4, preconditionsForAction, "Regenerer sa mana");

	preconditionsForAction.push_back(preconditionKillEnemy);

	const Action* killEnemy = new Action(8, enemyDies, 4, preconditionsForAction, "Achever un ennemi");

	possibleActions.push_back(doABarrelRoll);
	possibleActions.push_back(launchSpell);
	possibleActions.push_back(drinkPotion);
	possibleActions.push_back(moveTowardEnemy);
	possibleActions.push_back(moveTowardPotion);
	possibleActions.push_back(getAPotion);
	possibleActions.push_back(regenMan);
	possibleActions.push_back(killEnemy);
}

void printWay(vector<const Action*> way) {
	for (int i = 0; i < way.size(); ++i) {
		cout << way[i]->getDescription() << endl;
	}
}

vector<const Action*> GOAPSolver::solve() {
	//vector<Enemy*> enemies = worldState.getEnemies();
	//Precondition* firstUnvalidPrecondition;

	Player* player = worldState->getPlayer();
	//player->setMana(0);
	//player->setPotions(0);

	//worldState.getPotions()[0]->setPos(0, 0);

	NodeParser* node = getNodeParserForAction(getActionById(8));
	cout << " Pour executer : " << getActionById(8)->getDescription() << " il faudra " << endl;

	vector<const Action*> way = node->createWay();
	printWay(way);

	delete node;

	return way;
}

vector<const Action*> GOAPSolver::findActionToFillPrecondition(const Precondition* precondition) const {
	int possibleActionSize = possibleActions.size();
	vector<const Action*> actionsFound;

	for (int i = 0; i < possibleActionSize; ++i) {
		if (precondition->getEffectTypeToResolveThis() == possibleActions[i]->getEffect()->getEffectType()) {
			actionsFound.push_back(possibleActions[i]);
		}
	}

	return actionsFound;
}


NodeParser* GOAPSolver::getNodeParserForAction(const Action* action) const {
	NodeParser* newNode = new NodeParser(action, action->getCost());

	// Je veux r�cup�rer pour cette action les pr�conditions qui ne sont pas remplis
	// Si il n'y en a pas, je renvoie le nodeParser avec une seule action a faire
	
	// Si il y en a, je boucle sur les preconditions � remplir
		// Chaque pr�condition doit �tre un nouveau NodeParser
		// Pour chaque pr�condition je boucle sur les action me permettant de remplir la condition
		// J'appelle en r�cursif et je garde le node dont le cost est le moins �lev�

	vector<const Precondition*> unvalidPreconditions = getUnvalidPreconditions(action);
	int unvalidPreconditionsSize = unvalidPreconditions.size();

	if (unvalidPreconditionsSize >= 0) {
		for (int i = 0; i < unvalidPreconditionsSize; ++i) {
			vector<const Action*>	actionsToFillPrecondition = findActionToFillPrecondition(unvalidPreconditions[i]);
			int actionIdsSize = actionsToFillPrecondition.size();

			NodeParser* possibleNodeParserToFillPrecondition = nullptr;
			NodeParser* savedNodeParserToFillPrecondition = nullptr;

			for (int j = 0; j < actionIdsSize; ++j) {
				const Action* actionParsed = actionsToFillPrecondition[j];

				possibleNodeParserToFillPrecondition = getNodeParserForAction(actionParsed);

				if (savedNodeParserToFillPrecondition == nullptr || savedNodeParserToFillPrecondition->getCost() > possibleNodeParserToFillPrecondition->getCost()) {
					if (savedNodeParserToFillPrecondition != nullptr) {
						// Delete old savedNode
						delete savedNodeParserToFillPrecondition;
					}
					
					savedNodeParserToFillPrecondition = possibleNodeParserToFillPrecondition;
				}
				else {
					// Delete possible node not saved
					delete possibleNodeParserToFillPrecondition;
				}
			}

			if (savedNodeParserToFillPrecondition != nullptr) {
				newNode->setCost(newNode->getCost() +savedNodeParserToFillPrecondition->getCost());
				newNode->addNodeParser(savedNodeParserToFillPrecondition);
			}
		}
	}

	return newNode;
}

vector<const Precondition*> GOAPSolver::getUnvalidPreconditions(const Action* action) const {
	vector<const Precondition*> preconditionsList = action->getPreconditions();
	const Effect* effect = action->getEffect();

	int preconditionSize = preconditionsList.size();
	Player* player = worldState->getPlayer();

	vector<Enemy*> enemies = worldState->getEnemies();
	vector<Potion*> potions = worldState->getPotions();
	
	vector<const Precondition*> preconditionsToFill;
	int preconCpt = 0;

	bool hasEnemyInRange = false;
	bool hasEnemyAtZero = false;
	bool hasPotionInRange = false;

	for (int i = 0; i < preconditionSize; ++i) {
		switch (preconditionsList[i]->getType())
		{
		case IS_IN_RANGE_ENEMY:
			for (int j = 0; j < enemies.size(); ++j) {
				if (sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2)) <= preconditionsList[i]->getAmount()) {
					hasEnemyInRange = true;
				}
			}

			if (!hasEnemyInRange) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		case IS_IN_RANGE_POTION:
			for (int j = 0; j < potions.size(); ++j) {
				if (sqrt(pow((player->getPos()[0] - potions[i]->getPos()[0]), 2) + pow((player->getPos()[1] - potions[i]->getPos()[1]), 2)) <= preconditionsList[i]->getAmount()) {
					hasPotionInRange = true;
				}
			}

			if (!hasPotionInRange) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		case HAS_MANA:
			if (player->getMana() < preconditionsList[i]->getAmount()) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		case HAS_POTION:
			if (player->getPotions() < preconditionsList[i]->getAmount()) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		case ENEMY_AT_ZERO_HP:
			cout << "precon zero" << endl;
			for (int j = 0; j < enemies.size(); ++j) {
				cout << "precon zero" << enemies[i]->getHp() << endl;
				if (enemies[i]->getHp() <= 0) {
					hasEnemyAtZero = true;
				}
			}

			if (!hasEnemyAtZero) {
				cout << "precon zero not filled" << endl;
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		default:
			break;
		}
	}

	return preconditionsToFill;
}

const Action* GOAPSolver::getActionById(int id) const {
	int possibleActionSize = possibleActions.size();
	
	for (int i = 0; i < possibleActionSize; ++i) {
		if (possibleActions[i]->getId() == id) {
			return possibleActions[i];
		}
	}

	return nullptr;
}

void GOAPSolver::deleteGoap() {
	int preconditionSize = preconditions.size();
	int effectsSize = effects.size();
	int actionSize = possibleActions.size();

	for (int i = 0; i < preconditionSize; ++i) {
		delete preconditions[i];
	}

	for (int i = 0; i < effectsSize; ++i) {
		delete effects[i];
	}

	for (int i = 0; i < actionSize; ++i) {
		delete possibleActions[i];
	}
}