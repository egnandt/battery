#ifndef TEMPERATURELOADER_H
#define TEMPERATURELOADER_H

#include "abstracttemperatureloader.h"
#include <QObject>
#include <weatherservicethread.h>
#include <iostream>
#include <memory>

class TemperatureLoader: public AbstractTemperatureLoader
{

public: //From AbstractTemperatureLoader

    /**
     * @brief Constructor
     */
    TemperatureLoader();

    /**
     * @brief startLoad
     * @return
     */
    float startLoad(t_Coordinates) override;

public slots:
    void taskFinished();

private:
    QList<t_Coordinates> m_QList;
    std::unique_ptr<WeatherServiceThread> m_ThreadPtr;
};

#endif // TEMPERATURELOADER_H
