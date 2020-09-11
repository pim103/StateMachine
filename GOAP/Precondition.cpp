#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(Type type, int id) {
	preconType = type;
	actionId = id;
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