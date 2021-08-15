#include "BaseObjects.h"
BaseObjects::BaseObjects()
{
}

BaseObjects::BaseObjects(int id, string name, Position pos)
{
	this->id = id;
	this->name = name;
	this->position = pos;
}

BaseObjects::~BaseObjects()
{
}
int BaseObjects::getid()
{
	return this->id;
}

string BaseObjects::getName()
{
	return this->name;
}

void BaseObjects::printPosition()
{
	cout<<"Position:"<<this->getName()<<" (x, y) = ("<< this->position.x <<","<< this->position.y<<")";
}


