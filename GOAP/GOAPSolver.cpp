#include "GOAPSolver.h"

GOAPSolver::GOAPSolver() {

}
GOAPSolver::GOAPSolver(WorldState nWorldState) {
	worldState = nWorldState;

	// =================== INIT EFFECTS =================== //
	Effect* attackDamages = new Effect(EffectType::DO_DAMAGES, 1, [=]() {
		cout << "oh yeah";
		vector<Enemy*> enemies = worldState.getEnemies();
		Player* player = worldState.getPlayer();
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
		if (currentEnemy->getHp() <= 0) {
			cout << "dead";
		}
	});

	attackDamages->execute();
	
	Effect* spellDamages = new Effect(EffectType::DO_DAMAGES, 4, [=]() {
		vector<Enemy*> enemies = worldState.getEnemies();
		Player* player = worldState.getPlayer();
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
		if (currentEnemy->getHp() <= 0) {
			cout << "dead";
		}
	});
	
	Effect* getPotion = new Effect(EffectType::GET_POTION, 1, [=]() {
		vector<Potion*> potions = worldState.getPotions();
		Player* player = worldState.getPlayer();
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
		player->setPotions(player->getPotions() + 1);
		//remove potion
	});
	
	Effect* getManaWithPotion = new Effect(EffectType::GET_MANA, 6, [=]() {
		Player* player = worldState.getPlayer();
		player->setPotions(player->getPotions() - 1);
		player->setMana(player->getMana() + 6);
	});
	
	Effect* getManaWithRegen = new Effect(EffectType::GET_MANA, 2, [=]() {
		Player* player = worldState.getPlayer();
		player->setMana(player->getMana() + 2);
	});

	Effect* moveTowardsClosestEnemy = new Effect(EffectType::MOVE_TOWARDS_ENEMY, 1, [=]() {
		vector<Enemy*> enemies = worldState.getEnemies();
		Player* player = worldState.getPlayer();
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
	
	Effect* moveTowardsClosestPotion = new Effect(EffectType::MOVE_TOWARDS_POTION, 1, [=]() {
		vector<Potion*> potions = worldState.getPotions();
		Player* player = worldState.getPlayer();
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

	vector<Enemy*> enemies = worldState.getEnemies();
	Enemy* currentEnemy = enemies[0];
	int enemiesSize = enemies.size();
	for (int i = 0; i < enemiesSize; ++i) {
		cout << enemies[i]->getHp();
	}
	// ================ INIT PRECONDITION ================ //
	Precondition* preconditionDrinkPotion = new Precondition(PreconditionType::HAS_POTION, 1, EffectType::GET_POTION);
	Precondition* preconditionBasicAttack = new Precondition(PreconditionType::IS_IN_RANGE_ENEMY, 2, EffectType::MOVE_TOWARDS_ENEMY);
	Precondition* preconditionSpell = new Precondition(PreconditionType::IS_IN_RANGE_ENEMY, 3, EffectType::MOVE_TOWARDS_ENEMY);
	Precondition* preconditionSpell2 = new Precondition(PreconditionType::HAS_MANA, 2, EffectType::GET_MANA);
	Precondition* preconditionGetAPotion = new Precondition(PreconditionType::IS_IN_RANGE_POTION, 1, EffectType::MOVE_TOWARDS_POTION);

	// ================ INIT ACTIONS ================ //

	vector<Precondition*> preconditionsForAction;

	preconditionsForAction.push_back(preconditionBasicAttack);

	Action* doABarrelRoll = new Action(1, attackDamages, 2, preconditionsForAction, "Faire une attaque simple");

	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionSpell2);
	preconditionsForAction.push_back(preconditionSpell);

	Action* launchSpell = new Action(2, spellDamages, 1, preconditionsForAction, "Lancer un spell");
	
	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionDrinkPotion);

	Action* drinkPotion = new Action(3, getManaWithPotion, 1, preconditionsForAction, "Boire une potion");

	preconditionsForAction.clear();

	Action* moveTowardEnemy = new Action(4, moveTowardsClosestEnemy, 1, preconditionsForAction, "Bouger a distance d'un ennemi");
	Action* moveTowardPotion = new Action(5, moveTowardsClosestPotion, 1, preconditionsForAction, "Bouger a distance d'une potion");

	preconditionsForAction.push_back(preconditionGetAPotion);

	Action* getAPotion = new Action(6, getPotion, 1, preconditionsForAction, "Recuperer une potion");

	preconditionsForAction.clear();
	Action* regenMan = new Action(7, getManaWithRegen, 4, preconditionsForAction, "Regenerer sa mana");

	possibleActions.push_back(doABarrelRoll);
	possibleActions.push_back(launchSpell);
	possibleActions.push_back(drinkPotion);
	possibleActions.push_back(moveTowardEnemy);
	possibleActions.push_back(moveTowardPotion);
	possibleActions.push_back(getAPotion);
	possibleActions.push_back(regenMan);
}

vector<Action*> ParseNode(NodeParser* const node) {
	vector<Action*> way;
	vector<Action*> tempWay;

	for (int i = 0; i < node->prevNodeParse.size(); ++i) {
		tempWay = ParseNode(node->prevNodeParse[i]);

		for (int j = 0; j < tempWay.size(); ++j) {
			way.push_back(tempWay[j]);
		}
	}

	way.push_back(node->action);

	return way;
}

void printWay(vector<Action*> way) {
	for (int i = 0; i < way.size(); ++i) {
		cout << way[i]->getDescription() << endl;
	}
}

void GOAPSolver::solve() {
	//vector<Enemy*> enemies = worldState.getEnemies();
	//Precondition* firstUnvalidPrecondition;

	Player* player = worldState.getPlayer();
	player->setMana(0);
	player->setPotions(0);

	worldState.getPotions()[0]->setPos(0, 0);

	NodeParser* node = getCostAction(getActionById(2));
	cout << " Pour executer : " << getActionById(2)->getDescription() << " il faudra " << endl;

	vector<Action*> way = ParseNode(node);
	printWay(way);

	//return;
	//while (enemies.size() > 0) {
	//	firstUnvalidPrecondition = getFirstUnvalidPrecondition(currentGoal);

	//	if (firstUnvalidPrecondition != nullptr) {
	//		vector<int> actionIds = firstUnvalidPrecondition->getActionIds();
	//		int actionIdsSize = actionIds.size();

	//		for (int i = 0; i < actionIdsSize; ++i) {
	//			currentGoal = possibleActions[i];
	//		}
	//	}
	//	else {
	//		currentGoal->executeAction();
	//		currentGoal = topGoal;
	//	}
	//}
}

vector<Action*> GOAPSolver::findActionToFillPrecondition(Precondition* const precondition) {
	int possibleActionSize = possibleActions.size();
	vector<Action*> actionsFound;

	for (int i = 0; i < possibleActionSize; ++i) {
		if (precondition->getEffectTypeToResolveThis() == possibleActions[i]->getEffect()->getEffectType()) {
			actionsFound.push_back(possibleActions[i]);
		}
	}

	return actionsFound;
}

NodeParser* GOAPSolver::getCostAction(Action* action) {
	NodeParser* newNode = new NodeParser();
	newNode->action = action;
	newNode->cost = action->getCost();

	// Je veux r�cup�rer pour cette action les pr�conditions qui ne sont pas remplis
	// Si il n'y en a pas, je renvoie le nodeParser avec une seule action a faire
	
	// Si il y en a, je boucle sur les preconditions � remplir
		// Chaque pr�condition doit �tre un nouveau NodeParser
		// Pour chaque pr�condition je boucle sur les action me permettant de remplir la condition
		// J'appelle en r�cursif et je garde le node dont le cost est le moins �lev�

	vector<Precondition*> unvalidPreconditions = getUnvalidPreconditions(action);
	int unvalidPreconditionsSize = unvalidPreconditions.size();

	if (unvalidPreconditionsSize >= 0) {
		for (int i = 0; i < unvalidPreconditionsSize; ++i) {
			vector<Action*>	actionsToFillPrecondition = findActionToFillPrecondition(unvalidPreconditions[i]);
			int actionIdsSize = actionsToFillPrecondition.size();

			NodeParser* possibleNodeParserToFillPrecondition = nullptr;
			NodeParser* savedNodeParserToFillPrecondition = nullptr;

			for (int j = 0; j < actionIdsSize; ++j) {
				Action* actionParsed = actionsToFillPrecondition[j];

				possibleNodeParserToFillPrecondition = getCostAction(actionParsed);

				if (savedNodeParserToFillPrecondition == nullptr || savedNodeParserToFillPrecondition->cost > possibleNodeParserToFillPrecondition->cost) {
					savedNodeParserToFillPrecondition = possibleNodeParserToFillPrecondition;
				}
			}

			if (savedNodeParserToFillPrecondition != nullptr) {
				newNode->cost += savedNodeParserToFillPrecondition->cost;
				newNode->prevNodeParse.push_back(savedNodeParserToFillPrecondition);
			}
		}
	}

	return newNode;
}

vector<Precondition*> GOAPSolver::getUnvalidPreconditions(Action* action) {
	cout << " Action Id " << action->getId() << endl;

	vector<Precondition*> preconditionsList = action->getPreconditions();
	Effect* effect = action->getEffect();

	int preconditionSize = preconditionsList.size();
	Player* player = worldState.getPlayer();

	vector<Enemy*> enemies = worldState.getEnemies();
	vector<Potion*> potions = worldState.getPotions();
	
	vector<Precondition*> preconditionsToFill;
	int preconCpt = 0;

	bool hasEnemyInRange = false;
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
			cout << player->getPotions() << " " << preconditionsList[i]->getAmount() << endl;
			if (player->getPotions() < preconditionsList[i]->getAmount()) {
				preconditionsToFill.push_back(preconditionsList[i]);
			}
			break;
		default:
			break;
		}
	}

	return preconditionsToFill;
}

Action* GOAPSolver::getActionById(int id) {
	int possibleActionSize = possibleActions.size();
	
	for (int i = 0; i < possibleActionSize; ++i) {
		if (possibleActions[i]->getId() == id) {
			return possibleActions[i];
		}
	}

	return nullptr;
}