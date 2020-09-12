#pragma once

#include <iostream>
#include <vector>

using namespace std;
class Potion
{
private:
	vector<int> pos;
public:
	Potion(int posX, int posY);
	vector<int> getPos() const;
	void setPos(int posX, int posY);
};

