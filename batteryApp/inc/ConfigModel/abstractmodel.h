#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#include <QString>
#include <QVariant>
#include "datapoint.h"

class AbstractModel
{
public:
    explicit AbstractModel();
    virtual ~AbstractModel();
    virtual QString getRoutePath() = 0;
    virtual double getVehicleWeight() = 0;
    virtual int getVehicleBatteryCapacity() = 0;
    virtual double getVehiclePowertrainEfficiency() = 0;
    virtual double getVehicleTemperatureImpact() = 0;
    virtual double getVehicleMaximumRegenerationRate() = 0;
    virtual double getVehicleGradientChargeThreshold() = 0;
    virtual int getSimulationInitialCharge() = 0;
    virtual int getSimulationEcoModeSpeed() = 0;
    virtual int getSimulationNormalSpeed() = 0;
    virtual int getSimulationSportSpeed() = 0;
    virtual QList<DataPoint> &getDataPointList()= 0;
    virtual void setDataPointList(const QList<DataPoint>&) = 0;
    virtual QList<float> &getStatesOfCharge() = 0;
    virtual void setStateOfCharge(const float) = 0;
    virtual QList<float> &getGradientPoints() = 0;
    virtual void setGradientPoint(const float) = 0;
    virtual QList<float> &getTemperatureValuesList() = 0;
    virtual void setTemperatureValue(const float) = 0;
};
#endif // ABSTRACTMODEL_H
