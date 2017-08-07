#include "uidrawer.h"
#include "model.h"
#include <QDebug>
#include <algorithm>

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
    QVariantList temperaturePlotValuesList;
    QVariantList gradientPlotValuesList;
    QVariantList stateOfChargePlotValuesList;
    QPointF gradientPoint;
    QPointF temperaturePoint;
    QPointF stateOfChargePoint;
    int Xcoordinate = 0; //value from x axis
    while(Xcoordinate < m_model.getDataPointList().count())
    {
        gradientPoint.setX(Xcoordinate);
        gradientPoint.setY(m_model.getGradientPoints().at(Xcoordinate));
        temperaturePoint.setX(Xcoordinate);
        temperaturePoint.setY(m_model.getTemperatureValuesList().at(Xcoordinate));
        stateOfChargePoint.setX(Xcoordinate);
        stateOfChargePoint.setY(m_model.getStatesOfCharge().at(Xcoordinate));
        gradientPlotValuesList.append(QVariant::fromValue(gradientPoint));
        temperaturePlotValuesList.append(QVariant::fromValue(temperaturePoint));
        stateOfChargePlotValuesList.append(QVariant::fromValue(stateOfChargePoint));
        ++Xcoordinate;
    }
    m_plotViewModel.setGradientPoints(gradientPlotValuesList);
    m_plotViewModel.setTemperaturePoints(temperaturePlotValuesList);
    m_plotViewModel.setBatteryStateOfChargePoints(stateOfChargePlotValuesList);
    //-5 in order to see interpolated plots
    m_plotViewModel.setMinValueY(minValueFromAllLists(minValueFromList(m_model.getStatesOfCharge()), minValueFromList(m_model.getTemperatureValuesList()), minValueFromList(m_model.getGradientPoints())) - 5);

    //m_plotViewModel.setEndOfCharge(); - after calculating range
    //m_plotViewModel.setMaxValueX();
    //m_plotViewModel.setMinValueX();
}

float UIDrawer::maxValueFromList(const QList<float> &list)
{
    return *std::max_element(list.begin(), list.end());
}

float UIDrawer::minValueFromList(const QList<float> &list)
{
    return *std::min_element(list.begin(), list.end());
}

float UIDrawer::maxValueFromAllLists(float nr1, float nr2, float nr3)
{
    return (nr1 > nr2? (nr1 > nr3? nr1: nr3): (nr2 > nr3? nr2: nr3));
}

float UIDrawer::minValueFromAllLists(float nr1, float nr2, float nr3)
{
    return (nr1 < nr2? (nr1 < nr3? nr1: nr3): (nr2 < nr3? nr2: nr3));
}

