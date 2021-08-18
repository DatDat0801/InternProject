#include "StateContext.h"
#include "UnlockState.h"
StateContext::StateContext() : m_state{ new UnlockState() }
{
}

void StateContext::SetState(BaseState* state)
{
	m_state = state;
}

void StateContext::WriteState(string nameState)
{
	m_state->WriteState(this, nameState);
}