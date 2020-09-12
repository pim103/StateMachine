#include "Effect.h"

Effect::Effect() {

}
Effect::Effect(EffectType nEffectType, int nAmount, function<void(WorldState*)> nCallback) {
	effectType = nEffectType;
	amount = nAmount;
	callback = nCallback;
}
EffectType Effect::getEffectType() const {
	return effectType;
}
int Effect::getAmount() const {
	return amount;
}

void Effect::execute(WorldState* worldState) const {
	if (callback != nullptr) {
		callback(worldState);
	}
}