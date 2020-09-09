#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class State {
public:
	State();
	State(string _stateName);

	string getStateName();
	void setStateName(string newStateName);

	void addTransition(Transition newTransition);
	vector<Transition> getTransitions();

private:
	string stateName;
	vector<Transition> transitionList;
};