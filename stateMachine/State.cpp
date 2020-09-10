#include "State.h"

State::State() {}

State::State(const string _stateName, const GameState _gameState): stateName(_stateName), gameState(_gameState) {}

string State::getStateName() const {
	return stateName;
}

void State::setStateName(const string newStateName) {
	stateName = newStateName;
}

void State::addTransition(const Transition* newTransition, const State* nextState) {
	const TransitionToState* tts = new TransitionToState(newTransition, nextState);
	
	transitionList.push_back(tts);
}

vector<const TransitionToState* const> State::getTransitions() const {
	return transitionList;
}

GameState State::getGameState() const {
	return gameState;
}