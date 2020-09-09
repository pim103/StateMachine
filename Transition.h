#pragma once

class Transition {
public:
	Transition(State _nextState, vector<State> _possibleStateToChange);
	bool canPassToNextStep(State otherStateConditions);

	State getNextState();

private:
	State nextState;

	vector<State> possibleStateToChange;
};