#pragma once
#include "DynamicObject.h"
class Motorbike:public DynamicObject
{
public:
	Motorbike();
	Motorbike(int id, string name, Position pos);
	~Motorbike();
	void move() override;
};

