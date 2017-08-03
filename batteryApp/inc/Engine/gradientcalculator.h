#ifndef GRADIENTCALCULATOR_H
#define GRADIENTCALCULATOR_H

#include "basestate.h"
#include "abstractmodel.h"
#include "abstractgradientcalculator.h"

class GradientCalculator: public AbstractGradientCalculator, public BaseState
{
public:

    GradientCalculator(AbstractModel& aModel);

    void runState();

    void startCalculating();

protected:
    AbstractModel& m_model;
};

#endif // GRADIENTCALCULATOR_H
