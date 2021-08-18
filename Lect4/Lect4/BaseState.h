#pragma once
#include<iostream>
#include "StateContext.h"
class StateContext;
using namespace std;
class BaseState
{
public:
	virtual void WriteState(StateContext* stateContex, string name) = 0;
};

