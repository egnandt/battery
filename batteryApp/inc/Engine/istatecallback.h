#ifndef ISTATECALLBACK_H
#define ISTATECALLBACK_H

class IStateCallback
{
public:
    virtual void stateFinished() = 0;
    virtual void errorOccured() = 0;
};
#endif // ISTATECALLBACK_H
