#ifndef RANGECALCULATOR_H
#define RANGECALCULATOR_H
#include "basestate.h"
#include "abstractmodel.h"
#include "abstractrangecalculator.h"

class RangeCalculator: public AbstractRangeCalculator, public BaseState
{
public: //From AbstractRangeCalculator

    RangeCalculator(AbstractModel &aModel);

    void runState();

    void startCalculating();

protected:
    AbstractModel& m_model;
};

#endif // RANGECALCULATOR_H
