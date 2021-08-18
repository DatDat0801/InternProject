#pragma once
#include"BaseState.h"
class CloseState : public BaseState
{
public:
	void WriteState(StateContext* stateContex, string name) override;
};