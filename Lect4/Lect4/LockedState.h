#pragma once
#include"BaseState.h"
#include "StateContext.h"
class LockedState : public BaseState
{
public:
	void WriteState(StateContext* stateContex, string name) override;
};

