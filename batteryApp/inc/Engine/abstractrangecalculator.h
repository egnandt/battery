#ifndef ABSTRACTRANGECALCULATOR_H
#define ABSTRACTRANGECALCULATOR_H

class AbstractRangeCalculator
{
public:
    virtual ~AbstractRangeCalculator() = 0;

    virtual void startCalculating() = 0;
};

#endif // ABSTRACTRANGECALCULATOR_H
