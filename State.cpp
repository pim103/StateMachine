#include "State.h"

State::State() {}

State::State(string _stateName, int _id): stateName(_stateName), id(_id) {}

string State::getStateName() {
	return stateName;
}

void State::setStateName(string newStateName) {
	stateName = newStateName;
}

void State::addTransition(Transition* newTransition, State* nextState) {
	TransitionToState* tts = new TransitionToState(newTransition, nextState);
	
	transitionList.push_back(tts);
}

vector<TransitionToState*> State::getTransitions() {
	cout << "size in obj : " << transitionList.size() << endl;
	return transitionList;
}

int State::getId() {
	return id;
}