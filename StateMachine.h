#pragma once

class StateMachine {
public:
	StateMachine(int _id);

	State getCurrentState();
	void setCurrentState(State newCurrentState);
	void processState(const StateMachine otherStateMachine);

private:
	int id;

	State currentState;
};