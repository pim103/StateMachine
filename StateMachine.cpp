#include "StateMachine.h"

StateMachine::StateMachine(int _id) : id(_id) {}

void StateMachine::setCurrentState(State* newCurrentState) {
	currentState = newCurrentState;

	cout << "Joueur " << id << " fait " << currentState->getStateName() << endl;
}

State* StateMachine::getCurrentState() {
	return currentState;
}

void StateMachine::processState(StateMachine otherStateMachine) {
	State* currentState = getCurrentState();
	int idOtherCurrentState = otherStateMachine.getCurrentState()->getId();

	vector<TransitionToState*> transitionList = currentState->getTransitions();
	int transitionSize = transitionList.size();

	vector<int> possibleNextStateIndex;

	cout << "Nb transitions " << transitionSize << endl;

	for (int i = 0; i < transitionSize; ++i) {
		if (transitionList[i]->transition->checkCondition(idOtherCurrentState)) {
			possibleNextStateIndex.push_back(i);
		}
	}

	int possibleTransitionSize = possibleNextStateIndex.size();

	State* newCurrentState = transitionList[possibleNextStateIndex[rand() % possibleTransitionSize]]->state;
	setCurrentState(newCurrentState);
}