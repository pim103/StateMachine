#include "Action.h"

Action::Action() {

}

Action::Action(int nId, Effect* nEffect, int _amount, vector<Precondition*> nPreconditions) {
	id = nId;
	effect = nEffect;
	preconditions = nPreconditions;
}

vector<Precondition*> Action::getPreconditions() {
	return preconditions;
}

Effect* Action::getEffect() {
	return effect;
}

int Action::getId() {
	return id;
}

int Action::getCost() {
	return cost;
}

void Action::setCost(int nCost) {
	cost = nCost;
}