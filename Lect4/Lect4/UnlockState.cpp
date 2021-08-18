#include "UnlockState.h"
#include "OpenState.h"
void UnlockState::WriteState(StateContext* stateContex, string name)
{
	cout << "Unlock: " << name << endl;
	stateContex->SetState(new OpenState);
}