#include "CloseState.h"
#include "LockedState.h"
void CloseState::WriteState(StateContext* stateContex, string name)
{
	cout << "Close: " << name << endl;
	stateContex->SetState(new LockedState);
}