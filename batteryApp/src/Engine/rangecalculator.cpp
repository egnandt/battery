#include "rangecalculator.h"
#include "model.h"

RangeCalculator::RangeCalculator(AbstractModel &aModel)
    :   m_model{aModel}
{

}

void RangeCalculator::runState()
{
    startCalculating();
    m_stateCallback->stateFinished();
}

//dummy implementation - TODO
void RangeCalculator::startCalculating()
{
    while(m_model.getDataPointList().length() != m_model.getStatesOfCharge().length())
        m_model.setStateOfCharge(1);
}
