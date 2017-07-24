#ifndef TEMPERATURELOADERFACTORY_H
#define TEMPERATURELOADERFACTORY_H

#include "abstracttemperatureloaderfactory.h"
#include <memory>

class TemperatureLoaderFactory: public AbstractTemperatureLoaderFactory
{
public:

    /**
     * @brief Constructor
     */
    TemperatureLoaderFactory();

    /**
     * @brief Destructor
     */
    ~TemperatureLoaderFactory();

public: // From AbstractTemperatureLoaderFactory
    std::unique_ptr<AbstractTemperatureLoader> createTemperatureLoader();
};

#endif // TEMPERATURELOADERFACTORY_H
