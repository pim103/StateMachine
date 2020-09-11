#include "Game.h"

Game::Game() {}

char e_aigu = 0x82;

void Game::initStateMachine(StateMachine& stateMachine) {
	State* const st1 = new State("Attaque", GameState::ATT);
	State* const st2 = new State("Heal", GameState::HEAL);
	State* const st3 = new State("Buff Attaque", GameState::BUFF_ATT);
	State* const st4 = new State("Buff Defense", GameState::BUFF_DEF);
	State* const st5 = new State("Neutre", GameState::NEUTRAL);

	stateList.push_back(st1);
	stateList.push_back(st2);
	stateList.push_back(st3);
	stateList.push_back(st4);
	stateList.push_back(st5);

	Transition* const checkCdHeal = new TransitionCompareInt(0, TransitionType::CD_HEAL, TransitionComparison::EQUAL);
	Transition* const transitionForHeal = new TransitionCompareInt(10, TransitionType::HP_SELF, TransitionComparison::EQUAL_INFERIOR, checkCdHeal);

	Transition* const checkCdBuffAtt = new TransitionCompareInt(0, TransitionType::CD_BUFF_ATT, TransitionComparison::EQUAL);
	Transition* const transitionForBuffAtt = new TransitionCompareInt(16, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR, checkCdBuffAtt);
	Transition* const transitionForBuffAtt2 = new TransitionCompareInt(20, TransitionType::HP_SELF, TransitionComparison::EQUAL_SUPERIOR, transitionForBuffAtt);

	Transition* const checkCdBuffDef = new TransitionCompareInt(0, TransitionType::CD_BUFF_DEF, TransitionComparison::EQUAL);
	Transition* const transitionForBuffDef = new TransitionCompareInt(20, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR, checkCdBuffDef);

	Transition* const transitionAtt = new TransitionCompareInt(0, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR);

	transitionList.push_back(checkCdHeal);
	transitionList.push_back(transitionForHeal);
	transitionList.push_back(checkCdBuffAtt);
	transitionList.push_back(transitionForBuffAtt);
	transitionList.push_back(transitionForBuffAtt2);
	transitionList.push_back(checkCdBuffDef);
	transitionList.push_back(transitionForBuffDef);
	transitionList.push_back(transitionAtt);

	st1->addTransition(transitionForHeal, st2);
	st1->addTransition(transitionForBuffDef, st4);
	st1->addTransition(transitionForBuffAtt2, st3);
	st1->addTransition(transitionAtt, st1);

	st2->addTransition(transitionForHeal, st2);
	st2->addTransition(transitionForBuffDef, st4);
	st2->addTransition(transitionForBuffAtt2, st3);
	st2->addTransition(transitionAtt, st1);

	st3->addTransition(transitionForHeal, st2);
	st3->addTransition(transitionForBuffDef, st4);
	st3->addTransition(transitionForBuffAtt2, st3);
	st3->addTransition(transitionAtt, st1);

	st4->addTransition(transitionForHeal, st2);
	st4->addTransition(transitionForBuffDef, st4);
	st4->addTransition(transitionForBuffAtt2, st3);
	st4->addTransition(transitionAtt, st1);

	st5->addTransition(transitionForHeal, st2);
	st5->addTransition(transitionForBuffDef, st4);
	st5->addTransition(transitionForBuffAtt2, st3);
	st5->addTransition(transitionAtt, st1);

	stateMachine.setCurrentState(st5);
}

void Game::startGame() {
	stateMachines.push_back(new StateMachine(1));
	stateMachines.push_back(new StateMachine(2));

	entities.push_back(new Entity(1, 100, 0, 8, Element::FIRE));
	entities.push_back(new Entity(2, 150, 0, 8, Element::WATER));

	initStateMachine(*stateMachines[0]);
	initStateMachine(*stateMachines[1]);

	processGame();
}

void Game::processGame() {
	bool isEnding = false;
	
	int currentPlayer = 0;
	int otherPlayer = 1;
	int nbLoop = 0;

	while (!isEnding) {
		currentPlayer = nbLoop % 2;
		otherPlayer = currentPlayer == 0 ? 1 : 0;
		++nbLoop;

		if (currentPlayer == 0) {
			cout << "====================== Tour : " << nbLoop << " ======================" << endl;
			entities[0]->updateEntity();
			entities[1]->updateEntity();
		}

		cout << "\tJoueur " << currentPlayer << " joue" << endl;
		stateMachines[currentPlayer]->processState(entities[currentPlayer], entities[otherPlayer]);

		GameState currentState = stateMachines[currentPlayer]->getCurrentState()->getGameState();
		entities[currentPlayer]->applyState(entities[otherPlayer], currentState);

		if (currentPlayer == 1) {
			cout << "\tJoueur 1 hp : " << entities[0]->getHp() << " Joueur 2 hp : " << entities[1]->getHp() << endl;
		}

		if (nbLoop > 50 || entities[0]->getHp() <= 0 || entities[1]->getHp() <= 0) {
			isEnding = true;
		}
	}

	cout << "====================== Game terminee ======================" << endl;
	cout << "Joueur 1 hp : " << entities[0]->getHp() << " Joueur 2 hp : " << entities[1]->getHp() << endl;

	endGame();
}

void Game::endGame() {
	int transitionSize = transitionList.size();
	int stateSize = stateList.size();
	int stmSize = stateMachines.size();
	int entitySize = entities.size();

	for (int i = transitionSize - 1; i >= 0; --i) {
		delete transitionList[i];
	}

	for (int i = stateSize - 1; i >= 0; --i) {
		delete stateList[i];
	}

	for (int i = stmSize - 1; i >= 0; --i) {
		delete stateMachines[i];
	}

	for (int i = entitySize - 1; i >= 0; --i) {
		delete entities[i];
	}
}