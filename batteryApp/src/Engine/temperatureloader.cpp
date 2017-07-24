#include "Engine/temperatureloader.h"

TemperatureLoader::TemperatureLoader()
{

}

float TemperatureLoader::startLoad(t_Coordinates /*coord*/)
{
    m_ThreadPtr = std::make_unique<WeatherServiceThread>();
    connect(m_ThreadPtr.get(), SIGNAL(taskComplete()), this, SLOT(taskFinished()));
    m_ThreadPtr->start();
    return(3.5);
}

void TemperatureLoader::taskFinished()
{
    m_ThreadPtr.reset();
    std::cout<<"Task finished";
}

