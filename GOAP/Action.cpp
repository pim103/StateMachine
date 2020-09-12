#include "Action.h"

Action::Action() {

}

Action::Action(int nId, Effect* nEffect, int _cost, vector<Precondition*> nPreconditions, string desc) {
	id = nId;
	effect = nEffect;
	cost = _cost;
	preconditions = nPreconditions;
	description = desc;
}

vector<Precondition*> Action::getPreconditions() const {
	return preconditions;
}

Effect* Action::getEffect() const {
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