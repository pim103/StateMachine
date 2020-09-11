#pragma once

#include "State.h"

class StateMachine {
public:
	StateMachine(int _id);

	const State* getCurrentState() const;
	void setCurrentState(State* const newCurrentState);
	void processState(const Entity* selfEntity, const Entity* otherEntity);

private:
	int id;

	State* currentState;
};