#pragma once

#include "StateMachine.h";

class Game {
public:
	Game();

	void initStateMachine(StateMachine& stateMachine);
	void startGame();
	void processGame(Entity* const entity1, Entity* const entity2, StateMachine* const stm1, StateMachine* const stm2);
	void endGame();

private:

};