#include "Game.h"

Game::Game() {}

char e_aigu = 0x82;

void Game::initStateMachine(StateMachine& stateMachine) {
	State* const st1 = new State("Attaque", GameState::ATT);
	State* const st2 = new State("Heal", GameState::HEAL);
	State* const st3 = new State("Buff Attaque", GameState::BUFF_ATT);
	State* const st4 = new State("Buff Defense", GameState::BUFF_DEF);
	State* const st5 = new State("Neutre", GameState::NEUTRAL);

	const Transition* checkCdHeal = new TransitionCompareInt(0, TransitionType::CD_HEAL, TransitionComparison::EQUAL);
	const Transition* transitionForHeal = new TransitionCompareInt(10, TransitionType::HP_SELF, TransitionComparison::EQUAL_INFERIOR, checkCdHeal);

	const Transition* checkCdBuffAtt = new TransitionCompareInt(0, TransitionType::CD_BUFF_ATT, TransitionComparison::EQUAL);
	const Transition* transitionForBuffAtt = new TransitionCompareInt(16, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR, checkCdBuffAtt);
	const Transition* transitionForBuffAtt2 = new TransitionCompareInt(20, TransitionType::HP_SELF, TransitionComparison::EQUAL_SUPERIOR, transitionForBuffAtt);

	const Transition* checkCdBuffDef = new TransitionCompareInt(0, TransitionType::CD_BUFF_DEF, TransitionComparison::EQUAL);
	const Transition* transitionForBuffDef = new TransitionCompareInt(20, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR, checkCdBuffDef);

	const Transition* transitionAtt = new TransitionCompareInt(0, TransitionType::HP_ENEMY, TransitionComparison::EQUAL_SUPERIOR);

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
	StateMachine* stm1 = new StateMachine(1);
	StateMachine* stm2 = new StateMachine(2);

	Entity* entity1 = new Entity(1, 100, 0, 8, Element::FIRE);
	Entity* entity2 = new Entity(2, 150, 0, 8, Element::WATER);

	initStateMachine(*stm1);
	initStateMachine(*stm2);

	processGame(entity1, entity2, stm1, stm2);
}

void Game::processGame(Entity* const entity1, Entity* const entity2, StateMachine* const stm1, StateMachine* const stm2) {
	bool isEnding = false;
	
	int currentPlayer = 0;
	int nbLoop = 0;

	while (!isEnding) {

		if (currentPlayer == 0) {
			++nbLoop;
			cout << "====================== Tour : " << nbLoop << " ======================" << endl;
			entity1->updateEntity();
			entity2->updateEntity();

			cout << "\tJoueur 1 joue" << endl;
			currentPlayer = 1;

			stm1->processState(entity1, entity2);
			GameState currentState = stm1->getCurrentState()->getGameState();

			entity1->applyState(entity2, currentState);
		}
		else if (currentPlayer == 1) {
			cout << "\tJoueur 2 joue" << endl;
			currentPlayer = 0;

			stm2->processState(entity2, entity1);
			GameState currentState = stm2->getCurrentState()->getGameState();

			entity2->applyState(entity1, currentState);

			cout << "\tJoueur 1 hp : " << entity1->getHp() << " Joueur 2 hp : " << entity2->getHp() << endl;
		}

		if (nbLoop > 50 || entity1->getHp() <= 0 || entity2->getHp() <= 0) {
			isEnding = true;
		}
	}

	cout << "====================== Game terminee ======================" << endl;
	cout << "Joueur 1 hp : " << entity1->getHp() << " Joueur 2 hp : " << entity2->getHp() << endl;

	endGame();
}

void Game::endGame() {

}