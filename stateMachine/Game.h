#pragma once

#include "StateMachine.h";

class Game {
public:
	Game();

	void initStateMachine(StateMachine& stateMachine);
	void startGame();
	void processGame();
	void endGame();

private:
	vector<Transition*> transitionList;
	vector<State*> stateList;
	vector<StateMachine*> stateMachines;
	vector<Entity*> entities;
};