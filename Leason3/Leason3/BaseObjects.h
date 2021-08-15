#pragma once
#include <iostream>
using namespace std;

struct Position
{
public:
	Position(){}
	Position(float x, float y) {
		this->x = x;
		this->y = y;
	}
	float x;
	float y;
};
class BaseObjects
{
public:
	int id;
	string name;
	Position position;

	BaseObjects();
	BaseObjects(int id, string name, Position pos);
	~BaseObjects();
	string getName();
	int getid();
	virtual void move() = 0;
	void printPosition();
};

