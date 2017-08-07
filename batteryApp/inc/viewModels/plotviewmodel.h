#ifndef PLOTVIEW_H
#define PLOTVIEW_H
#include "abstractplotviewmodel.h"

class PlotViewModel : public AbstractPlotViewModel
{
    Q_OBJECT

public:
    explicit PlotViewModel(QObject* aParent = 0);
    ~PlotViewModel();

public:

    QString getErrorMessage() const;
    void setErrorMessage(const QString & message);

    QVariantList getTemperaturePoints() const;
    void setTemperaturePoints(const  QVariantList & list);

    QVariantList getBatteryStateOfChargePoints () const;
    void setBatteryStateOfChargePoints (const  QVariantList & list);

    QVariantList getGradientPoints() const;
    void setGradientPoints(const QVariantList & list);

    float getMinValueY() const;
    void setMinValueY(const float& minValueY);

    float getMaxValueY() const;
    void setMaxValueY(const float& maxValueY);

    float getMinValueX() const;
    void setMinValueX(const float& minValueX);

    float getMaxValueX() const;
    void setMaxValueX(const float& maxValueX);

    QPointF getEndOfCharge() const;
    void setEndOfCharge(const QPointF& point);

    bool getLoading() const;
    void setLoading(const bool& loading);

private:
    QVariantList m_temperaturePoints;
    QVariantList m_batteryStateOfChargePoints;
    QVariantList m_gradientPoints;
    QPointF m_endOfCharge;
    float m_minValueY;
    float m_maxValueY;
    float m_minValueX;
    float m_maxValueX;
    bool m_loading;
    QString m_message;
};
#endif // PLOTVIEW_H
