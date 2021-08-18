#include "LockedState.h"
#include "UnlockState.h"
void LockedState::WriteState(StateContext* stateContex, string name)
{
	cout << "Lock: " << name << endl;
	stateContex->SetState(new UnlockState);
}