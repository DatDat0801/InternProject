#include "StaticObject.h"
#include "BaseObjects.h"

StaticObject::StaticObject()
{
}

StaticObject::StaticObject(int id, string name, Position pos):BaseObjects(id,name,pos)
{
}

StaticObject::~StaticObject()
{
}

void StaticObject::move()
{
	printf("Static Object Canot Move!\n");
}