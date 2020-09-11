#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(Type type, int id, int nAmount) {
	preconType = type;
	actionId = id;
	amount = nAmount;
}

int Precondition::getActionId() {
	return actionId;
}
Type Precondition::getType() {
	return preconType;
}
void Precondition::setActionId(int id) {
	actionId = id;
}
int Precondition::getAmount() {
	return amount;
}