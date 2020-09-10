#include "Game.h"

Game::Game() {}

void Game::initStateMachine(StateMachine& stateMachine) {
	State st1("Attaque Haute", 1);
	State st2("Attaque Basse", 2);
	State st3("Garde Haute", 3);
	State st4("Garde Basse", 4);
	State st5("Canaliser", 5);
	State st6("Neutre", 6);

	vector<int> transitionState1;
	transitionState1.push_back(st6.getId());
	transitionState1.push_back(st5.getId());
	transitionState1.push_back(st4.getId());

	vector<int> transitionState2;
	transitionState1.push_back(st6.getId());
	transitionState1.push_back(st5.getId());
	transitionState1.push_back(st3.getId());

	vector<int> transitionState3;
	transitionState1.push_back(st1.getId());

	vector<int> transitionState4;
	transitionState1.push_back(st2.getId());

	vector<int> transitionState5;
	transitionState1.push_back(st3.getId());
	transitionState1.push_back(st4.getId());
	transitionState1.push_back(st6.getId());

	vector<int> transitionState6;

	Transition t1(transitionState1);
	Transition t2(transitionState2);
	Transition t3(transitionState3);
	Transition t4(transitionState4);
	Transition t5(transitionState5);
	Transition t6(transitionState6);

	st1.addTransition(t2, st2);
	st1.addTransition(t3, st3);
	st1.addTransition(t4, st4);
	st1.addTransition(t5, st5);
	st1.addTransition(t6, st6);

	st2.addTransition(t1, st1);
	st2.addTransition(t3, st3);
	st2.addTransition(t4, st4);
	st2.addTransition(t5, st5);
	st2.addTransition(t6, st6);

	st3.addTransition(t2, st2);
	st3.addTransition(t1, st1);
	st3.addTransition(t4, st4);
	st3.addTransition(t5, st5);
	st3.addTransition(t6, st6);

	st4.addTransition(t2, st2);
	st4.addTransition(t3, st3);
	st4.addTransition(t1, st1);
	st4.addTransition(t5, st5);
	st4.addTransition(t6, st6);

	st5.addTransition(t2, st2);
	st5.addTransition(t1, st1);

	st6.addTransition(t2, st2);
	st6.addTransition(t3, st3);
	st6.addTransition(t4, st4);
	st6.addTransition(t5, st5);
	st6.addTransition(t1, st1);

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
			currentPlayer = 1;

			stm1.processState(stm2);
		}
		else if (currentPlayer == 1) {
			currentPlayer = 0;

			stm2.processState(stm1);
		}

		if (nbLoop > 50) {
			isEnding = true;
		}
	}

	cout << "Game terminée" << endl;
}