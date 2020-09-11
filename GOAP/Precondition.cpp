#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(PreconditionType type, int nAmount, vector<int> ids) {
	preconType = type;
	actionIds = ids;
	amount = nAmount;
}

vector<int> Precondition::getActionIds() {
	return actionIds;
}

PreconditionType Precondition::getType() {
	return preconType;
}

void Precondition::setActionIds(vector<int> ids) {
	actionIds = ids;
}

int Precondition::getAmount() {
	return amount;
}