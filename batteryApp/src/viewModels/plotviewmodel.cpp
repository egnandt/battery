#include "plotviewmodel.h"

PlotViewModel::PlotViewModel(QObject* aParent)
    :AbstractPlotViewModel(aParent),
      m_temperaturePoints{},
      m_batteryStateOfChargePoints{},
      m_gradientPoints{},
      m_endOfCharge{},
      m_minValueY {0},
      m_maxValueY {0},
      m_minValueX {0},
      m_maxValueX {0},
      m_loading {true}
{

}

PlotViewModel::~PlotViewModel()
{

}

QVariantList PlotViewModel::getTemperaturePoints() const
{
    return m_temperaturePoints;
}

void PlotViewModel::setTemperaturePoints(const QVariantList &list)
{
    m_temperaturePoints = list;
    emit temperaturePointsChanged();
}

QVariantList PlotViewModel::getBatteryStateOfChargePoints() const
{
    return m_batteryStateOfChargePoints;
}

void PlotViewModel::setBatteryStateOfChargePoints(const QVariantList &list)
{
    m_batteryStateOfChargePoints = list;
    emit batteryStateOfChargePointsChanged();
}

QVariantList PlotViewModel::getGradientPoints() const
{
    return m_gradientPoints;
}

void PlotViewModel::setGradientPoints(const QVariantList &list)
{
    m_gradientPoints = list;
    emit gradientPointsChanged();
}

float PlotViewModel::getMinValueX() const
{
    return m_minValueX;
}
void PlotViewModel::setMinValueX(const float &minValueX)
{
    m_minValueX=minValueX;
    emit minValueXChanged();
}

float PlotViewModel::getMinValueY() const
{
    return m_minValueY;
}

void PlotViewModel::setMinValueY(const float &minValueY)
{
    m_minValueY= minValueY;
    emit minValueYChanged();
}

float PlotViewModel::getMaxValueX() const
{
    return m_maxValueX;
}

void PlotViewModel::setMaxValueX(const float &maxValueX)
{
    m_maxValueX=maxValueX;
    emit maxValueXChanged();
}

float PlotViewModel::getMaxValueY() const
{
    return m_maxValueY;
}

void PlotViewModel::setMaxValueY(const float &maxValueY)
{
    m_maxValueY =maxValueY;
    emit maxValueYChanged();
}

bool PlotViewModel::getLoading() const
{
    return m_loading;
}

void PlotViewModel::setLoading(const bool& loading)
{
    m_loading = loading;
    emit loadingChanged();
}

QPointF PlotViewModel::getEndOfCharge() const
{
    return m_endOfCharge;
}

void PlotViewModel::setEndOfCharge(const QPointF &point)
{
    m_endOfCharge = point;
    emit endOfChargeChanged();
}
