#pragma once
#include "StaticObject.h"
class Tree:public StaticObject
{
public:
	Tree();
	Tree(int id, string name, Position pos);
	~Tree();
	void move() override;
};

