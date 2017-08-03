#ifndef ISTATE_H
#define ISTATE_H
#include "istatecallback.h"

class IState
{
public:
    virtual void setCallback(IStateCallback *state) = 0;
    virtual void runState() = 0;
};

#endif // ISTATE_H
