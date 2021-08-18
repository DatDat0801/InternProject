#pragma once
#include"BaseState.h"
#include <iostream>
class BaseState;
using namespace std;
class StateContext
{
private:
	BaseState * m_state;
public:
	
	StateContext();
	void SetState(BaseState* state);
	void WriteState(string nameState);
};

