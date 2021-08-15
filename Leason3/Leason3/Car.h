#pragma once
#include "DynamicObject.h"
class Car :public DynamicObject
{
public:
	Car();
	Car(int id, string name, Position pos);
	~Car();
	void move() override;
};

