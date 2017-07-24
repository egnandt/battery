#include "temperatureloaderfactory.h"
#include "Engine/temperatureloader.h"

TemperatureLoaderFactory::TemperatureLoaderFactory()
{

}

TemperatureLoaderFactory::~TemperatureLoaderFactory()
{

}

std::unique_ptr<AbstractTemperatureLoader> TemperatureLoaderFactory::createTemperatureLoader()
{
   return std::make_unique<TemperatureLoader>();
}
