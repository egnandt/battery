#ifndef BASESTATE_H
#define BASESTATE_H
#include "istate.h"
#include "istatecallback.h"

class BaseState : public IState
{
public:
    void setCallback(IStateCallback *state) override;

protected:
    IStateCallback *m_stateCallback;
};

#endif // BASESTATE_H
