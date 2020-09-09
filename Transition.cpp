#include "State.h";
#include "Transition.h"

Transition::Transition(State _nextState, vector<State> _possibleState) : nextState(_nextState), possibleStateToChange(_possibleState) {}

bool Transition::canPassToNextStep(State otherStateConditions) {
	int possibleStateSize = possibleStateToChange.size();
	string otherStateName = otherStateConditions.getStateName();

	for (int i = 0; i < possibleStateSize; ++i) {
		if (possibleStateToChange[i].getStateName() == otherStateName) {
			return true;
		}
	}

	return false;
}

State Transition::getNextState() {
	return nextState;
}