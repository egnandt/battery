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

void GradientCalculator::startCalculating()
{
    m_model.setGradientPoint(0);
    for(int index = 0; index < m_model.getDataPointList().length() - 1; index++)
        m_model.setGradientPoint((m_model.getDataPointList().at(index + 1).m_elevation-m_model.getDataPointList().at(index).m_elevation)/10);
}
