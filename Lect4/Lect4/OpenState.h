#pragma once
#include"BaseState.h"
class OpenState : public BaseState
{
public:
	void WriteState(StateContext* stateContex, string name) override;
};
