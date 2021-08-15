#include "Car.h"
#include "DynamicObject.h"
Car::Car() {}
Car::~Car() {}
Car::Car(int id, string name, Position pos) :DynamicObject(id, name, pos)
{
}
void Car::move()
{
	printf("Car can move.\n");
}

