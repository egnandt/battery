#include "model.h"
#include <QSettings>
#include <QString>

Model::Model(const QString& path)
{
   initSettings(path);
}

Model::~Model()
{

}

void Model::initSettings(const QString& path)
{
    m_settings = std::make_unique<QSettings>(path, QSettings::IniFormat);
}

double Model::getVehicleWeight()
{
    return m_settings->value("vehicle/max_regen_rate").toDouble();
}

int Model::getVehicleBatteryCapacity()
{
    return m_settings->value("vehicle/battery_capacity").toInt();
}

double Model::getVehiclePowertrainEfficiency()
{
    return m_settings->value("vehicle/powertrain_efficiency").toDouble();
}

double Model::getVehicleTemperatureImpact()
{
    return m_settings->value("vehicle/temperature_impact").toDouble();
}

double Model::getVehicleMaximumRegenerationRate()
{
    return m_settings->value("vehicle/max_regen_rate").toDouble();
}

double Model::getVehicleGradientChargeThreshold()
{
    return m_settings->value("vehicle/gradient_charge_threshold").toDouble();
}

int Model::getSimulationInitialCharge()
{
    return m_settings->value("simulation/initial_charge").toInt();
}

int Model::getSimulationEcoModeSpeed()
{
    return m_settings->value("simulation/eco_speed").toInt();
}

int Model::getSimulationNormalSpeed()
{
    return m_settings->value("simulation/normal_speed").toInt();
}

int Model::getSimulationSportSpeed()
{
    return m_settings->value("simulation/sport_speed").toInt();
}

QString Model::getRoutePath()
{
    return m_settings->value("route/inputfile").toString();
}

QList<DataPoint>& Model::getDataPointList()
{
    return m_dataPointList;
}

void Model::setDataPointList(const QList<DataPoint>& list)
{
     m_dataPointList = list;
}

QList<float>& Model::getStatesOfCharge()
{
    return m_statesOfCharge;
}

void Model::setStateOfCharge(const float value)
{
    m_statesOfCharge.append(value);
}


QList<float>& Model::getGradientPoints()
{
    return m_gradientPoints;
}

void Model::setGradientPoint(const float value)
{
    m_gradientPoints.append(value);
}

QList<float>& Model::getTemperatureValuesFromWeb()
{
    return m_temperatureValuesFromWeb;
}

void Model::setTemperatureValuesFromWeb(const QList<float>& list)
{
    m_temperatureValuesFromWeb = list;
}
