#pragma once

#include "Action.h"

class NodeParser {
public:
	NodeParser();
	NodeParser(Action* action, int cost);
	~NodeParser();

	int getCost() const;
	Action* getAction() const;
	vector<NodeParser*> getPrevNodeParser() const;

	void setCost(int cost);
	void setAction(Action* action);
	void addNodeParser(NodeParser* node);

	vector<Action*> createWay();
private:
	int cost;
	Action* action;
	vector<NodeParser*> prevNodeParse;
};