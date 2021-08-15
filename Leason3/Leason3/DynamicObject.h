#pragma once
#include "BaseObjects.h";
class DynamicObject :public BaseObjects
{
public:
	DynamicObject();
	DynamicObject(int id, string name, Position pos);
	~DynamicObject();
	void move() override;
};

