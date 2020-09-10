#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transition {
public:
	Transition(vector<int> _checkStateId);

	bool checkCondition(int stateId);

private:
	vector<int> checkStateId;
};