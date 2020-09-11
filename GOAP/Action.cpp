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
string Action::getDescription() {
	return description;
}