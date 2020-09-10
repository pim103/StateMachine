#include "State.h"

State::State() {}

State::State(string _stateName, int _id): stateName(_stateName), id(_id) {}

string State::getStateName() {
	return stateName;
}

void State::setStateName(string newStateName) {
	stateName = newStateName;
}

void State::addTransition(Transition newTransition, State nextState) {
	transitionList.push_back(newTransition);
	transitionNextState.push_back(nextState);
}

vector<Transition> State::getTransitions() {
	return transitionList;
}

State State::getStateByIndexTransition(int index) {
	return transitionNextState[index];
}

int State::getId() {
	return id;
}