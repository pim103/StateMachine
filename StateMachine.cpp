#include "StateMachine.h"

StateMachine::StateMachine(int _id) : id(_id) {}

void StateMachine::setCurrentState(State newCurrentState) {
	currentState = newCurrentState;

	cout << "Joueur " << id << " fait " << currentState.getStateName() << endl;
}

State StateMachine::getCurrentState() {
	return currentState;
}

void StateMachine::processState(StateMachine otherStateMachine) {
	State currentState = getCurrentState();
	int idOtherCurrentState = otherStateMachine.getCurrentState().getId();

	vector<Transition> transitionList = currentState.getTransitions();
	int transitionSize = transitionList.size();

	vector<int> possibleNextStateIndex;

	for (int i = 0; i < transitionSize; ++i) {
		if (transitionList[i].checkCondition(idOtherCurrentState)) {
			possibleNextStateIndex.push_back(i);
		}
	}

	int possibleTransitionSize = possibleNextStateIndex.size();

	try {
		State newCurrentState = currentState.getStateByIndexTransition(rand() % possibleTransitionSize);
		setCurrentState(newCurrentState);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}