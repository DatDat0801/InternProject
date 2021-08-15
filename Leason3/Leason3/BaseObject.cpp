#include <iostream>
using namespace std;

struct Position
{
public:
	int x;
	int y;
};
class BaseObject
{
public:
	int id;
	string name;
	Position position;

	BaseObject();
	~BaseObject();
	virtual string getName()=0;
	virtual int getid() =0;
	virtual void move()=0;
	virtual void printPosition()=0;
};

BaseObject::BaseObject()
{
}

BaseObject::~BaseObject()
{
}