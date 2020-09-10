#include "Entity.h"
#include "Transition.h"

Entity::Entity(int _id, int _hp, int _def, int _att, Element _element) : id(_id), hp(_hp), def(_def),	att(_att), element(_element) {
	cdBuffAtt = 0;
	cdBuffDef = 0;
	cdHeal = 0;
}

const int Entity::getId() const {
	return id;
}

int Entity::getHp() const {
	return hp;
}

int Entity::getDef() const {
	return def;
}

int Entity::getAtt() const {
	return att;
}

int Entity::getCdHeal() const {
	return cdHeal;
}

int Entity::getCdBuffDef() const {
	return cdBuffDef;
}

int Entity::getCdBuffAtt() const {
	return cdBuffAtt;
}

const Element Entity::getElement() const {
	return element;
}

void Entity::setHp(int newHp) {
	hp = newHp;
}

void Entity::setDef(int newDef) {
	def = newDef;
}

void Entity::setAtt(int newAtt) {
	att = newAtt;
}

void Entity::setElement(Element newElement) {
	element = newElement;
}

void Entity::updateEntity() {
	if (cdBuffAtt > 0) {
		--cdBuffAtt;
	}
	if (cdBuffDef > 0) {
		--cdBuffDef;
	}
	if (cdHeal > 0) {
		--cdHeal;
	}

	if (cdBuffAtt == 9) {
		cout << "\t\tJoueur " << id << " perd son buff att..." << endl;
		att -= 4;
	}
	if (cdBuffDef == 6) {
		cout << "\t\tJoueur " << id << " perd son buff def..." << endl;
		def -= 5;
	}
}

void Entity::applyState(Entity* otherEntity, GameState currentState) {
	switch (currentState) {
	case GameState::ATT:
		cout << "\t\tJoueur " << id << " attaque Joueur " << otherEntity->getId() << " pour " << att - otherEntity->getDef() << " degats" << endl;

		otherEntity->setHp(otherEntity->getHp() - (att - otherEntity->getDef()));
		break;
	case GameState::BUFF_DEF:
		def += 5;
		cdBuffDef = 10;
		cout << "\t\tJoueur " << id << " buff sa defense ! Valeur de defense : " << def << endl;
		break;
	case GameState::BUFF_ATT:
		att += 4;
		cdBuffAtt = 12;
		cout << "\t\tJoueur " << id << " buff son attaque ! Valeur d'attaque : " << att << endl;
		break;
	case GameState::HEAL:
		cout << "\t\tJoueur " << id << " se heal !" << endl;
		hp += 10;
		cdHeal = 10;
		break;
	}
}