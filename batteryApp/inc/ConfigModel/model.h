#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QString>
#include <memory>
#include <QSettings>
#include "abstractmodel.h"

class Model: public AbstractModel
{
public:

    Model(const QString& path);
    ~Model();

public:

    QString getRoutePath();
    double getVehicleWeight();
    int getVehicleBatteryCapacity();
    double getVehiclePowertrainEfficiency();
    double getVehicleTemperatureImpact();
    double getVehicleMaximumRegenerationRate();
    double getVehicleGradientChargeThreshold();
    int getSimulationInitialCharge();
    int getSimulationEcoModeSpeed();
    int getSimulationNormalSpeed();
    int getSimulationSportSpeed();
    QList<DataPoint> &getDataPointList();
    void setDataPointList(const QList<DataPoint>&);
    QList<float> &getStatesOfCharge();
    void setStateOfCharge(const float);
    QList<float> &getGradientPoints();
    void setGradientPoint(const float);
    QList<float> &getTemperatureValuesFromWeb();
    void setTemperatureValuesFromWeb(const QList<float>&);

private:

    void initSettings(const QString& path);

protected:
    std::unique_ptr<QSettings> m_settings;
    QList<DataPoint> m_dataPointList;
    QList<float> m_statesOfCharge;
    QList<float> m_gradientPoints;
    QList<float> m_temperatureValuesFromWeb;

};
#endif // CONFIGLOADER_H


