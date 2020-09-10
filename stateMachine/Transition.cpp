#include "Transition.h"

Transition::Transition(TransitionType _transitiontype) : transitionType(_transitiontype) {}

TransitionState::TransitionState(vector<GameState> _checkStateId) : checkStateId(_checkStateId), Transition(TransitionType::STATE) { }

bool TransitionState::checkCondition(const Entity* selfEntity, const Entity* otherEntity) const {
	/*GameState stateId = otherEntity->getStateMachine()->getCurrentState()->getGameState();

	for (int i = 0; i < checkStateId.size(); ++i) {
		if (stateId == checkStateId[i]) {
			return true;
		}
	}*/

	return false;
}

TransitionCompareInt::TransitionCompareInt(int _valueToCompare, TransitionType _transitionType, TransitionComparison _transitionComparison) : 
	valueToCompare(_valueToCompare), 
	Transition(_transitionType),
	transitionComparison(_transitionComparison) {
	otherCheckTransition = nullptr;
}

TransitionCompareInt::TransitionCompareInt(int _valueToCompare, TransitionType _transitionType, TransitionComparison _transitionComparison, const Transition* _otherCheckTransition) :
	valueToCompare(_valueToCompare),
	Transition(_transitionType),
	transitionComparison(_transitionComparison),
	otherCheckTransition(_otherCheckTransition) {}

bool TransitionCompareInt::checkCondition(const Entity* selfEntity, const Entity* otherEntity) const {
	bool comparison = false;
	int value = getCorrectArgument(selfEntity, otherEntity);


	switch (transitionComparison) {
		case TransitionComparison::EQUAL :
			comparison = value == valueToCompare;
			break;
		case TransitionComparison::INFERIOR:
			comparison = value < valueToCompare;
			break;
		case TransitionComparison::SUPERIOR:
			comparison = value > valueToCompare;
			break;
		case TransitionComparison::EQUAL_INFERIOR:
			comparison = value <= valueToCompare;
			break;
		case TransitionComparison::EQUAL_SUPERIOR:
			comparison = value >= valueToCompare;
			break;
	}

	bool otherComparison = true;
	if (otherCheckTransition != nullptr) {
		otherComparison = otherCheckTransition->checkCondition(selfEntity, otherEntity);
	}

	return (comparison && otherComparison);
}

int TransitionCompareInt::getCorrectArgument(const Entity* selfEntity, const Entity* otherEntity) const {
	switch (transitionType) {
	case TransitionType::HP_ENEMY:
		return otherEntity->getHp();
		break;
	case TransitionType::HP_SELF:
		return selfEntity->getHp();
		break;
	case TransitionType::CD_BUFF_ATT:
		return selfEntity->getCdBuffAtt();
		break;
	case TransitionType::CD_BUFF_DEF:
		return selfEntity->getCdBuffDef();
		break;
	case TransitionType::CD_HEAL:
		return selfEntity->getCdHeal();
		break;
	}
}