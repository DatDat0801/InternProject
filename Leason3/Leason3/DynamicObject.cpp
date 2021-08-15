#include "DynamicObject.h"
#include "BaseObjects.h"

DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(int id, string name, Position pos) :BaseObjects(id, name, pos)
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::move()
{
	printf("Dynamic Object Can Move!\n");
}