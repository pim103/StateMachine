#include "StateMachine.h"

StateMachine::StateMachine(int _id) : id(_id) {}

void StateMachine::setCurrentState(const State* newCurrentState) {
	currentState = newCurrentState;

	//cout << "\t\tJoueur " << id << " fait >>> " << currentState->getStateName() << endl;
}

const State* StateMachine::getCurrentState() const {
	return currentState;
}

void StateMachine::processState(const Entity* selfEntity, const Entity* otherEntity) {
	vector<const TransitionToState* const> transitionList = currentState->getTransitions();
	int transitionSize = transitionList.size();

	vector<int> possibleNextStateIndex;

	for (int i = 0; i < transitionSize; ++i) {
		if (transitionList[i]->transition->checkCondition(selfEntity, otherEntity)) {
			const State* newCurrentState = transitionList[i]->state;
			setCurrentState(newCurrentState);
			break;
		}
	}
}