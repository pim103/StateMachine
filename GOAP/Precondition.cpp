#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(PreconditionType type, int nAmount, EffectType neffectTypeToResolveThis) {
	preconType = type;
	amount = nAmount;
	effectTypeToResolveThis = neffectTypeToResolveThis;
}

EffectType Precondition::getEffectTypeToResolveThis() {
	return effectTypeToResolveThis;
}

PreconditionType Precondition::getType() {
	return preconType;
}

int Precondition::getAmount() {
	return amount;
}