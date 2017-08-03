#include "basestate.h"
#include "istatecallback.h"

void BaseState::setCallback(IStateCallback *state)
{
    m_stateCallback = state;
}
