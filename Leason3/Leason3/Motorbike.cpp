#include "Motorbike.h"
#include "DynamicObject.h"
Motorbike::Motorbike() {}
Motorbike::~Motorbike() {}
Motorbike::Motorbike(int id, string name, Position pos) :DynamicObject(id, name, pos)
{
}
void Motorbike::move()
{
	printf("Motorbike can move.\n");
}

