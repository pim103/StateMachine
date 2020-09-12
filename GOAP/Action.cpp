#include "Action.h"

Action::Action() {

}

Action::Action(int nId, const Effect* nEffect, int _cost, vector<const Precondition*> nPreconditions, string desc) {
	id = nId;
	effect = nEffect;
	cost = _cost;
	preconditions = nPreconditions;
	description = desc;
}

vector<const Precondition*> Action::getPreconditions() const {
	return preconditions;
}

const Effect* Action::getEffect() const {
	return effect;
}

int Action::getId() const {
	return id;
}

int Action::getCost() const {
	return cost;
}

void Action::setCost(int nCost) {
	cost = nCost;
}
string Action::getDescription() const {
	return description;
}