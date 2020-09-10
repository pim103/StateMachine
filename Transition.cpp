#include "Transition.h"

TransitionState::TransitionState(vector<int> _checkStateId) : checkStateId(_checkStateId) { }

bool TransitionState::checkCondition(int stateId) {
	for (int i = 0; i < checkStateId.size(); ++i) {
		if (stateId == checkStateId[i]) {
			return true;
		}
	}

	return false;
}