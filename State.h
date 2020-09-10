#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Transition.h"

using namespace std;

class State {
public:
	State();
	State(string _stateName, int _id);

	string getStateName();
	void setStateName(string newStateName);

	State getStateByIndexTransition(int index);
	void addTransition(Transition newTransition, State nextState);
	vector<Transition> getTransitions();
	int getId();

private:
	int id;
	string stateName;
	vector<Transition> transitionList;
	vector<State> transitionNextState;
};