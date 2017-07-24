#ifndef ABSTRACTTEMPERATURELOADERFACTORY_H
#define ABSTRACTTEMPERATURELOADERFACTORY_H

#include <memory>

class AbstractTemperatureLoader;

class AbstractTemperatureLoaderFactory
{
public:

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractTemperatureLoaderFactory() {}

    /**
     * @brief Creates temperature loader
     * @return AbstractTemperatureLoader*
     */
    virtual std::unique_ptr<AbstractTemperatureLoader> createTemperatureLoader() = 0;
};

#endif // ABSTRACTTEMPERATURELOADERFACTORY_H
