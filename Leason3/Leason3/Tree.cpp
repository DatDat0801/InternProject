#include "Tree.h"

Tree::Tree(){}
Tree::~Tree(){}
Tree::Tree(int id, string name, Position pos) :StaticObject(id, name, pos)
{
}
void Tree::move()
{
	printf("Tree can not move!\n");
}

