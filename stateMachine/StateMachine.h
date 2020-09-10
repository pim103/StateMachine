#pragma once

#include "State.h"

class StateMachine {
public:
	StateMachine(int _id);

	const State* getCurrentState() const;
	void setCurrentState(const State* newCurrentState);
	void processState(const Entity* selfEntity, const Entity* otherEntity);

private:
	int id;

	const State* currentState;
};