#include "Game.h"

Game::Game() {}

void Game::initStateMachine(StateMachine& stateMachine) {
	State* st1 = new State("Attaque Haute", 1);
	State* st2 = new State("Attaque Basse", 2);
	State* st3 = new State("Garde Haute", 3);
	State* st4 = new State("Garde Basse", 4);
	State* st5 = new State("Canaliser", 5);
	State* st6 = new State("Neutre", 6);

	// Ajoute les state vérifié par la transition
	vector<int> transitionState1;
	transitionState1.push_back(st6->getId());
	transitionState1.push_back(st5->getId());
	transitionState1.push_back(st4->getId());

	vector<int> transitionState2;
	transitionState2.push_back(st6->getId());
	transitionState2.push_back(st5->getId());
	transitionState2.push_back(st3->getId());

	vector<int> transitionState3;
	transitionState3.push_back(st1->getId());

	vector<int> transitionState4;
	transitionState4.push_back(st2->getId());

	vector<int> transitionState5;
	transitionState5.push_back(st3->getId());
	transitionState5.push_back(st4->getId());
	transitionState5.push_back(st6->getId());

	vector<int> transitionState6;

	Transition* t1 = new TransitionState(transitionState1);
	Transition* t2 = new TransitionState(transitionState2);
	Transition* t3 = new TransitionState(transitionState3);
	Transition* t4 = new TransitionState(transitionState4);
	Transition* t5 = new TransitionState(transitionState5);
	Transition* t6 = new TransitionState(transitionState6);

	// Ajoute les transitions possibles aux états
	st1->addTransition(t2, st2);
	st1->addTransition(t3, st3);
	st1->addTransition(t4, st4);
	st1->addTransition(t5, st5);
	st1->addTransition(t6, st6);

	st2->addTransition(t1, st1);
	st2->addTransition(t3, st3);
	st2->addTransition(t4, st4);
	st2->addTransition(t5, st5);
	st2->addTransition(t6, st6);

	st3->addTransition(t2, st2);
	st3->addTransition(t1, st1);
	st3->addTransition(t4, st4);
	st3->addTransition(t5, st5);
	st3->addTransition(t6, st6);

	st4->addTransition(t2, st2);
	st4->addTransition(t3, st3);
	st4->addTransition(t1, st1);
	st4->addTransition(t5, st5);
	st4->addTransition(t6, st6);

	st5->addTransition(t1, st1);
	st5->addTransition(t2, st2);
	st5->addTransition(t3, st1);
	st5->addTransition(t4, st2);

	st6->addTransition(t2, st2);
	st6->addTransition(t3, st3);
	st6->addTransition(t4, st4);
	st6->addTransition(t5, st5);
	st6->addTransition(t1, st1);

	stateMachine.setCurrentState(st6);
}

void Game::startGame() {
	StateMachine stm1(1), stm2(2);

	initStateMachine(stm1);
	initStateMachine(stm2);

	processGame(stm1, stm2);
}

void Game::processGame(StateMachine& stm1, StateMachine& stm2) {
	bool isEnding = false;
	
	int currentPlayer = 0;
	int nbLoop = 0;

	while (!isEnding) {
		++nbLoop;

		cout << "Tour numéro : " << nbLoop << endl;

		if (currentPlayer == 0) {
			cout << "Joueur numéro 1 joue" << endl;
			currentPlayer = 1;

			stm1.processState(stm2);
		}
		else if (currentPlayer == 1) {
			cout << "Joueur numéro 2 joue" << endl;
			currentPlayer = 0;

			stm2.processState(stm1);
		}

		if (nbLoop > 50) {
			isEnding = true;
		}
	}

	cout << "Game terminée" << endl;
}