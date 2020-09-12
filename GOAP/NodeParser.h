#pragma once

#include "Action.h"

class NodeParser {
public:
	NodeParser(const Action* action, int cost);
	~NodeParser();

	int getCost() const;
	const Action* getAction() const;
	vector<NodeParser*> getPrevNodeParser() const;

	void setCost(int cost);
	void setAction(Action* action);
	void addNodeParser(NodeParser* node);

	vector<const Action*> createWay();
private:
	int cost;
	const Action* action;
	vector<NodeParser*> prevNodeParse;
};