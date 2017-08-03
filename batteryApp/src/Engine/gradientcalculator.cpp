#include "gradientcalculator.h"
#include "model.h"

GradientCalculator::GradientCalculator(AbstractModel &aModel)
    :   m_model{aModel}
{

}

void GradientCalculator::runState()
{
    startCalculating();
    m_stateCallback->stateFinished();
}

//dummy implementation for the moment
void GradientCalculator::startCalculating()
{

}
