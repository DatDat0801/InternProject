// Leason3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "House.h"
#include "Motorbike.h"
#include "Car.h"
#include <list>
using namespace std;
int main()
{
    list<BaseObjects*> listObj;
    Position* p1 = new Position(1, 1);
    BaseObjects* tree = new Tree(001, "PineTree ", *p1);
    listObj.push_back(tree);

    Position* p2 = new Position(1, 0);
    BaseObjects* house = new House(002, "HouseX", *p2);
    listObj.push_back(house);

    Position* p3 = new Position(0, 1);
    BaseObjects* mor = new Motorbike(003, "Mor1", *p3);
    listObj.push_back(mor);

    Position* p4 = new Position(2, 1);
    BaseObjects* car = new Car(004, "Mescerdes", *p4);
    listObj.push_back(car);

    cout << "\nObject's Name:\n";
    for (auto obj : listObj) {
        cout<< obj->getName();
        cout << endl;
    }

    cout << "\nMove Object:\n";
    for (auto obj : listObj) {
        obj->move();
    }

    cout << "\nPrint Position:\n";
    for (auto obj : listObj) {
        obj->printPosition();
        cout << endl;
    }
    listObj.clear();

    cout << "End and Free Momory\n";
    delete tree;
    delete house;
    delete mor;
    delete car;
    delete p1, p2, p3, p4;
    _CrtDumpMemoryLeaks();   
    return 0;
}
