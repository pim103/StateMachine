#include "State.h"
#include "Transition.h"

State::State() {}

State::State(string _stateName): stateName(_stateName) {}

string State::getStateName() {
	return stateName;
}

void State::setStateName(string newStateName) {
	stateName = newStateName;
}

void State::addTransition(Transition newTransition) {
	transitionList.push_back(newTransition);
}

vector<Transition> State::getTransitions() {
	return transitionList;
}