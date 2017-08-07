#ifndef ISTATECALLBACK_H
#define ISTATECALLBACK_H
#include "errors.h"

class IStateCallback
{
public:
    virtual void stateFinished() = 0;
    virtual void errorOccured(Errors currentError) = 0;
};

#endif // ISTATECALLBACK_H
