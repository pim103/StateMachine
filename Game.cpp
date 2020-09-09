#include "Transition.h";
#include "State.h";
#include "StateMachine.h";
#include "Game.h"

Game::Game() {}

void Game::initStateMachine(StateMachine& stateMachine) {
	State st1("Attaque Haute");
	State st2("Attaque Basse");
	State st3("Garde Haute");
	State st4("Garde Basse");
	State st5("Canaliser");
	State st6("Neutre");

	vector<State> transitionState1;
	transitionState1.push_back(st6);
	transitionState1.push_back(st5);
	transitionState1.push_back(st4);

	vector<State> transitionState2;
	transitionState1.push_back(st6);
	transitionState1.push_back(st5);
	transitionState1.push_back(st3);

	vector<State> transitionState3;
	transitionState1.push_back(st1);

	vector<State> transitionState4;
	transitionState1.push_back(st2);

	vector<State> transitionState5;
	transitionState1.push_back(st3);
	transitionState1.push_back(st4);
	transitionState1.push_back(st6);

	vector<State> transitionState6;

	Transition t1(st1, transitionState1);
	Transition t2(st2, transitionState2);
	Transition t3(st3, transitionState3);
	Transition t4(st4, transitionState4);
	Transition t5(st5, transitionState5);
	Transition t6(st6, transitionState6);

	st1.addTransition(t2);
	st1.addTransition(t3);
	st1.addTransition(t4);
	st1.addTransition(t5);
	st1.addTransition(t6);

	st2.addTransition(t1);
	st2.addTransition(t3);
	st2.addTransition(t4);
	st2.addTransition(t5);
	st2.addTransition(t6);

	st3.addTransition(t2);
	st3.addTransition(t4);
	st3.addTransition(t4);
	st3.addTransition(t5);
	st3.addTransition(t6);

	st4.addTransition(t2);
	st4.addTransition(t3);
	st4.addTransition(t1);
	st4.addTransition(t5);
	st4.addTransition(t6);

	st5.addTransition(t2);
	st5.addTransition(t1);

	st6.addTransition(t2);
	st6.addTransition(t3);
	st6.addTransition(t4);
	st6.addTransition(t5);
	st6.addTransition(t1);

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