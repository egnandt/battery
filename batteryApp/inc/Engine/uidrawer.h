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

    float maxValueFromList(const QList<float> &list);

    float minValueFromList(const QList<float> &list);

    float minValueFromAllLists(float nr1, float nr2, float nr3);

    float maxValueFromAllLists(float nr1, float nr2, float nr3);

protected:
    AbstractModel& m_model;
    AbstractPlotViewModel& m_plotViewModel;
};

#endif // UIDRAWER_H
