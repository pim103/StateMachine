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
	State(const string _stateName, const GameState _id);

	string getStateName() const;
	void setStateName(const string newStateName);

	void addTransition(Transition* const newTransition, State* const nextState);
	vector<TransitionToState*> getTransitions() const;
	GameState getGameState() const;

private:
	GameState gameState;
	string stateName;
	vector<TransitionToState*> transitionList;
};


class TransitionToState {
public:
	TransitionToState(Transition* _transition, State* _state) : transition(_transition), state(_state) {}

	Transition* transition;
	State* state;
};