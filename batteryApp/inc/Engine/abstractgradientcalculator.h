#ifndef ABSTRACTGRADIENTCALCULATOR_H
#define ABSTRACTGRADIENTCALCULATOR_H

class AbstractGradientCalculator
{
public:
    virtual ~AbstractGradientCalculator() = 0;

    virtual void startCalculating() = 0;
};

#endif // ABSTRACTGRADIENTCALCULATOR_H
