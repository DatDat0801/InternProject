#pragma once
#include "StaticObject.h"
class House :public StaticObject
{
public:
	House();
	House(int id, string name, Position pos);
	~House();
	void move() override;
};

