#include "uidrawer.h"
#include "model.h"

UIDrawer::UIDrawer(AbstractModel &aModel, AbstractPlotViewModel &aPlotViewModel) :
    m_model{aModel},
    m_plotViewModel{aPlotViewModel}
{

}

void UIDrawer::runState()
{
    startDraw();
    m_stateCallback->stateFinished();
}

//pass Model to viewModel
void UIDrawer::startDraw()
{
//TODO verify in temp loader that we have as many temp values from web as there are
//QPointFs in DataPoint list, otherwise use float values from DataPoint as temp values
//    if(m_model.getTemperatureValuesFromWeb().isEmpty())
//        if(m_model.getDataPointList().)
//        m_plotViewModel.setTemperaturePoints(m_model.getDataPointList().);
//    else
//        m_plotViewModel.setTemperaturePoints();
//    m_plotViewModel.setBatteryStateOfChargePoints(m_model.getStatesOfCharge());
//    m_plotViewModel.setGradientPoints();
//    m_plotViewModel.setEndOfCharge();
//    m_plotViewModel.setMaxValueX();
//    m_plotViewModel.setMinValueX();
//    m_plotViewModel.setMaxValueY();
//    m_plotViewModel.setMinValueY();
}
