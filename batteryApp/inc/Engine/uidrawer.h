#ifndef UIDRAWER_H
#define UIDRAWER_H

#include "basestate.h"
#include "abstractmodel.h"
#include "abstractplotviewmodel.h"
#include "abstractuidrawer.h"

class UIDrawer: public AbstractUIDrawer, public BaseState
{
public:

    UIDrawer(AbstractModel &aModel, AbstractPlotViewModel &aPlotViewModel);

    void runState();

    void startDraw();

protected:
    AbstractModel& m_model;
    AbstractPlotViewModel& m_plotViewModel;
};

#endif // UIDRAWER_H
