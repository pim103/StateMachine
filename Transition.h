#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transition {
public:
	virtual bool checkCondition(int stateId) {
		return false;
	}
};

class TransitionState: public Transition{
public:
	TransitionState(vector<int> _checkStateId);
	bool checkCondition(int stateId);

private:
	vector<int> checkStateId;
};