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

	void addTransition(const Transition* newTransition, const State* nextState);
	vector<const TransitionToState* const> getTransitions() const;
	GameState getGameState() const;

private:
	GameState gameState;
	string stateName;
	vector<const TransitionToState* const> transitionList;
};


class TransitionToState {
public:
	TransitionToState(const Transition* _transition, const State* _state) : transition(_transition), state(_state) {}

	const Transition* transition;
	const State* state;
};