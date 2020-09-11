#include "Effect.h"

Effect::Effect() {

}
Effect::Effect(EffectType nEffectType, int nAmount, function<void(void)> nCallback) {
	effectType = nEffectType;
	amount = nAmount;
	callback = nCallback;
}
EffectType Effect::getEffectType() {
	return effectType;
}
int Effect::getAmount() {
	return amount;
}

void Effect::execute() {
	if (callback != nullptr) {
		callback();
	}
}