#include "Action.h"

Action::Action(Effect nEffect, vector<Precondition> nPreconditions, int nAmount) {
	effect = nEffect;
	preconditions = nPreconditions;
	amount = nAmount;
}

vector<Precondition> Action::getPreconditions() {
	return preconditions;
}

Effect Action::getEffect() {
	return effect;
}