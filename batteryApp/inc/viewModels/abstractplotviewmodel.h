#ifndef PLOTVIEWMODEL_H
#define PLOTVIEWMODEL_H
#include <QObject>
#include <QList>
#include <QPoint>
#include <QString>

class AbstractPlotViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QVariantList  temperaturePoints READ getTemperaturePoints NOTIFY temperaturePointsChanged)
    Q_PROPERTY( QVariantList  batteryStateOfChargePoints READ getBatteryStateOfChargePoints NOTIFY batteryStateOfChargePointsChanged)
    Q_PROPERTY( QVariantList  gradientPoints READ getGradientPoints NOTIFY gradientPointsChanged)
    Q_PROPERTY(float minValueY READ getMinValueY NOTIFY minValueYChanged)
    Q_PROPERTY(float maxValueY READ getMaxValueY NOTIFY maxValueYChanged)
    Q_PROPERTY(float minValueX READ getMinValueX NOTIFY minValueXChanged)
    Q_PROPERTY(float maxValueX READ getMaxValueX NOTIFY maxValueXChanged)
    Q_PROPERTY(QPointF  endOfCharge READ getEndOfCharge NOTIFY endOfChargeChanged)
    Q_PROPERTY(bool loading READ getLoading NOTIFY loadingChanged)
    Q_PROPERTY(QString errorMessage READ getErrorMessage NOTIFY errorMessageChanged)

public:
    explicit AbstractPlotViewModel(QObject* aParent=0);
    virtual ~AbstractPlotViewModel();

    virtual QString getErrorMessage() const= 0;
    virtual void setErrorMessage (const QString& message) = 0;

    virtual QVariantList getTemperaturePoints() const= 0;
    virtual void setTemperaturePoints(const  QVariantList & list) = 0;

    virtual QVariantList getBatteryStateOfChargePoints () const=0;
    virtual void setBatteryStateOfChargePoints (const  QVariantList & list) =0;

    virtual QVariantList getGradientPoints() const = 0;
    virtual void setGradientPoints(const QVariantList & list)=0;

    virtual float getMinValueY()const=0;
    virtual void setMinValueY(const float& minValueY)=0;

    virtual float getMaxValueY()const=0;
    virtual void setMaxValueY(const float& maxValueY)=0;

    virtual float getMinValueX()const=0;
    virtual void setMinValueX(const float& minValueX)=0;

    virtual float getMaxValueX()const=0;
    virtual void setMaxValueX(const float& maxValueX)=0;

    virtual QPointF getEndOfCharge()const=0;
    virtual void setEndOfCharge(const QPointF& point)=0;

    virtual bool getLoading()const=0;
    virtual void setLoading(const bool& loading)=0;

signals:
    void batteryStateOfChargePointsChanged();
    void temperaturePointsChanged();
    void gradientPointsChanged();
    void minValueXChanged();
    void minValueYChanged();
    void maxValueXChanged();
    void maxValueYChanged();
    void endOfChargeChanged();
    void loadingChanged();
    void errorMessageChanged();
};
#endif // PLOTVIEWMODEL_H

