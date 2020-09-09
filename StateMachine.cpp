#include "Transition.h"
#include "State.h"
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
	State otherCurrentState = otherStateMachine.getCurrentState();

	vector<Transition> transitionList = currentState.getTransitions();
	int transitionSize = transitionList.size();

	vector<Transition> possibleTransition;

	for (int i = 0; i < transitionSize; ++i) {
		if (transitionList[i].canPassToNextStep(otherCurrentState)) {
			possibleTransition.push_back(transitionList[i]);
		}
	}

	int possibleTransitionSize = possibleTransition.size();
	State newCurrentState = possibleTransition[rand() % possibleTransitionSize].getNextState();
	setCurrentState(newCurrentState);
}