#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(PreconditionType type, int nAmount, EffectType neffectTypeToResolveThis) {
	preconType = type;
	amount = nAmount;
	effectTypeToResolveThis = neffectTypeToResolveThis;
}

EffectType Precondition::getEffectTypeToResolveThis() const {
	return effectTypeToResolveThis;
}

PreconditionType Precondition::getType() const {
	return preconType;
}

int Precondition::getAmount() const {
	return amount;
}