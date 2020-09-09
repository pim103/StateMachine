#pragma once

class Game {
public:
	Game();

	void initStateMachine(StateMachine& stateMachine);
	void startGame();
	void processGame(StateMachine& stm1, StateMachine& stm2);

private:

};