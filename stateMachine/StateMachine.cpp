#include "StateMachine.h"

StateMachine::StateMachine(int _id) : id(_id) {}

void StateMachine::setCurrentState(State* const newCurrentState) {
	currentState = newCurrentState;
}

const State* StateMachine::getCurrentState() const {
	return currentState;
}

void StateMachine::processState(const Entity* selfEntity, const Entity* otherEntity) {
	vector<TransitionToState*> transitionList = currentState->getTransitions();
	int transitionSize = transitionList.size();

	vector<int> possibleNextStateIndex;

	for (int i = 0; i < transitionSize; ++i) {
		if (transitionList[i]->transition->checkCondition(selfEntity, otherEntity)) {
			State* newCurrentState = transitionList[i]->state;
			setCurrentState(newCurrentState);
			break;
		}
	}
}