#pragma once
#include"BaseState.h"

class UnlockState : public BaseState
{
public:
	void WriteState(StateContext* stateContex, string name) override;
};

