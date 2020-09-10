#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Transition.h"

using namespace std;

class TransitionToState;

class State {
public:
	State();
	State(string _stateName, int _id);

	string getStateName();
	void setStateName(string newStateName);

	void addTransition(Transition* newTransition, State* nextState);
	vector<TransitionToState*> getTransitions();
	int getId();

private:
	int id;
	string stateName;
	vector<TransitionToState*> transitionList;
};


class TransitionToState {
public:
	TransitionToState(Transition* _transition, State* _state) : transition(_transition), state(_state) {}

	Transition* transition;
	State* state;
};