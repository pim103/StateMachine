#include "GOAPSolver.h"

GOAPSolver::GOAPSolver() {

}
GOAPSolver::GOAPSolver(WorldState nWorldState) {
	worldState = nWorldState;

	// =================== INIT EFFECTS =================== //
	Effect* AttackDamages = new Effect(EffectType::DO_DAMAGES, 1, [=]() {
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

	AttackDamages->execute();
	
	Effect* SpellDamages = new Effect(EffectType::DO_DAMAGES, 4, [=]() {
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
	
	Effect* GetPotion = new Effect(EffectType::GET_POTION, 1, [=]() {
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
	
	Effect* GetManaWithPotion = new Effect(EffectType::GET_MANA, 6, [=]() {
		Player* player = worldState.getPlayer();
		player->setPotions(player->getPotions() - 1);
		player->setMana(player->getMana() + 6);
	});
	
	Effect* GetManaWithRegen = new Effect(EffectType::GET_MANA, 2, [=]() {
		Player* player = worldState.getPlayer();
		player->setMana(player->getMana() + 2);
	});

	Effect* MoveTowardsClosestEnemy = new Effect(EffectType::MOVE_TOWARDS_ENEMY, 1, [=]() {
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
	
	Effect* MoveTowardsClosestPotion = new Effect(EffectType::MOVE_TOWARDS_POTION, 1, [=]() {
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

	Action* doABarrelRoll = new Action(1, AttackDamages, 1, preconditionsForAction);

	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionSpell);
	preconditionsForAction.push_back(preconditionSpell2);

	Action* launchSpell = new Action(2, SpellDamages, 3, preconditionsForAction);
	
	preconditionsForAction.clear();
	preconditionsForAction.push_back(preconditionDrinkPotion);

	Action* drinkPotion = new Action(3, GetManaWithPotion, 4, preconditionsForAction);

	preconditionsForAction.clear();

	Action* moveTowardEnemy = new Action(4, MoveTowardsClosestEnemy, 1, preconditionsForAction);
	Action* moveTowardPotion = new Action(5, MoveTowardsClosestPotion, 1, preconditionsForAction);

	preconditionsForAction.push_back(preconditionGetAPotion);

	Action* getAPotion = new Action(6, GetPotion, 1, preconditionsForAction);

	preconditionsForAction.clear();
	Action* regenMan = new Action(7, GetManaWithRegen, 1, preconditionsForAction);

	possibleActions.push_back(doABarrelRoll);
	possibleActions.push_back(launchSpell);
	possibleActions.push_back(drinkPotion);
	possibleActions.push_back(moveTowardEnemy);
	possibleActions.push_back(moveTowardPotion);
	possibleActions.push_back(getAPotion);
	possibleActions.push_back(regenMan);
}

void GOAPSolver::solve() {
	//vector<Enemy*> enemies = worldState.getEnemies();
	//Precondition* firstUnvalidPrecondition;

	//Player* player = worldState.getPlayer();
	//player->setMana(0);
	//player->setPotions(0);

	////worldState.getPotions()[0]->setPos(0, 0);

	//cout << " launchSpell " << getCostAction(getActionById(6)) << endl;

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

//vector<Action*> GOAPSolver::getCostAction(Action* action) {
//	//vector<Action*> actions;
//
//	//if (action != nullptr) {
//	//	vector<Precondition*> unvalidPreconditions = getUnvalidPreconditions(action);
//	//	int unvalidPreconditionsSize = unvalidPreconditions.size();
//
//	//	if (unvalidPreconditionsSize > 0) {
//	//		// Parcours les precondition necessaire à l'action
//	//		for (int i = 0; i < unvalidPreconditionsSize; ++i) {
//	//			vector<int> actionIds = unvalidPreconditions[i]->getActionIds();
//	//			int actionIdsSize = actionIds.size();
//	//			vector<vector<Action*>> subActionsPossible;
//	//			
//	//			// Recupere le cout de l'action remplissant la precondition la moins chère
//	//			for (int j = 0; j < actionIdsSize; ++j) {
//	//				Action* action = getActionById(actionIds[j]);
//	//				subActionsPossible.push_back(getCostAction(action));
//	//			}
//	//		}
//	//	}
//
//	//	actions.push_back(action);
//	//}
//
//	//return actions;
//}
//
//vector<Action*> GOAPSolver::findBestWay(Precondition* precondition) {
//	vector<Action*> actions;
//	vector<int> actionIds = precondition->getActionIds();
//	int actionIdsSize = actionIds.size();
//
//	// Recupere le cout de l'action remplissant la precondition la moins chère
//	for (int j = 0; j < actionIdsSize; ++j) {
//
//	}
//
//	return actions;
//}
//
//map<int, vector<Action*>> GOAPSolver::findWaysToExecute(Action* actionToResolve) {
//	// int : index of unvalid preconditions | vector<Actions*> best way to execute
//	map<int, vector<Action*>> ways;
//
//	if (actionToResolve != nullptr) {
//		vector<Precondition*> unvalidPreconditions = getUnvalidPreconditions(actionToResolve);
//		int unvalidPreconditionsSize = unvalidPreconditions.size();
//
//		if (unvalidPreconditionsSize > 0) {
//			// Parcours les precondition necessaire à l'action
//			for (int i = 0; i < unvalidPreconditionsSize; ++i) {
//				vector<Action*> actionsToMake = findBestWay(unvalidPreconditions[i]);
//
//				ways[i] = actionsToMake;
//			}
//		}
//	}
//
//	return ways;
//}

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

	cout << " size preconditions " << preconditionSize << endl;

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
			cout << " check in range potion " << endl;
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
		default:

			cout << " default" << endl;
			break;
		}
	}

	cout << " Find preconditions failed " << preconditionsToFill.size() << endl;

	return preconditionsToFill;
}

Precondition* GOAPSolver::getFirstUnvalidPrecondition(Action* action) {
	vector<Precondition*> preconditionsList = action->getPreconditions();
	Effect* effect = action->getEffect();
	int preconditionSize = preconditionsList.size();
	Player* player = worldState.getPlayer();
	vector<Enemy*> enemies = worldState.getEnemies();
	vector<Potion*> potions = worldState.getPotions();
	vector<Precondition*> preconditionsToFill;
	int preconCpt = 0;

	for (int i = 0; i < preconditionSize; ++i) {
		switch (preconditionsList[i]->getType())
		{
		case IS_IN_RANGE_ENEMY:
			for (int j = 0; j < enemies.size(); ++j) {
				if (sqrt(pow((player->getPos()[0] - enemies[i]->getPos()[0]), 2) + pow((player->getPos()[1] - enemies[i]->getPos()[1]), 2)) > preconditionsList[i]->getAmount()) {
					return preconditionsList[i];
				}
			}
		case IS_IN_RANGE_POTION:
			for (int j = 0; j < potions.size(); ++j) {
				if (sqrt(pow((player->getPos()[0] - potions[i]->getPos()[0]), 2) + pow((player->getPos()[1] - potions[i]->getPos()[1]), 2)) > preconditionsList[i]->getAmount()) {
					return preconditionsList[i];
				}
			}
			
			break;
		case HAS_MANA:
			if (player->getMana() < preconditionsList[i]->getAmount()) {
				return preconditionsList[i];
			}
			break;
		case HAS_POTION:
			if (potions.size() < preconditionsList[i]->getAmount()) {
				return preconditionsList[i];
			}
			break;
		default:
			break;
		}
	}

	return nullptr;
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