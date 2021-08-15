#include "House.h"
House::House() {}
House::~House() {}
House::House(int id, string name, Position pos) :StaticObject(id, name, pos)
{
}
void House::move()
{
	printf("House can not move!\n");
}

