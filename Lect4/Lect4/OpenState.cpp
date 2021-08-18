#include "OpenState.h"
#include "CloseState.h"
void OpenState::WriteState(StateContext* stateContex, string name)
{
	cout << "Open: " << name << endl;
	stateContex->SetState(new CloseState);
}