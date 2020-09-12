#include "NodeParser.h"

NodeParser::NodeParser() {
	cost = 0;
	action = nullptr;
}

NodeParser::NodeParser(Action* _action, int _cost): action(_action), cost(_cost) {

}

NodeParser::~NodeParser() {
	int nodeParseSize = prevNodeParse.size();

	for (int i = 0; i < nodeParseSize; ++i) {
		delete prevNodeParse[i];
	}
}

int NodeParser::getCost() const {
	return cost;
}

Action* NodeParser::getAction() const {
	return action;
}

vector<NodeParser*> NodeParser::getPrevNodeParser() const {
	return prevNodeParse;
}

void NodeParser::setCost(int nCost) {
	cost = nCost;
}

void NodeParser::setAction(Action* nAction) {
	action = nAction;
}

void NodeParser::addNodeParser(NodeParser* newNode) {
	prevNodeParse.push_back(newNode);
}

vector<Action*> NodeParser::createWay() {
	vector<Action*> way;
	vector<Action*> tempWay;

	int prevNodeSize = prevNodeParse.size();

	for (int i = 0; i < prevNodeSize; ++i) {
		tempWay = prevNodeParse[i]->createWay();

		for (int j = 0; j < tempWay.size(); ++j) {
			way.push_back(tempWay[j]);
		}
	}

	way.push_back(action);

	return way;
}