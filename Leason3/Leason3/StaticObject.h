#pragma once
#include "BaseObjects.h";
class StaticObject:public BaseObjects
{
public:
	StaticObject();
	StaticObject(int id, string name, Position pos);
	~StaticObject();
	void move() override;
};

