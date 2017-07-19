#ifndef ABSTRACTBATTERYAPPLICATIONFACTORY_H
#define ABSTRACTBATTERYAPPLICATIONFACTORY_H

#include <memory>

class AbstractInstrumentsModel;

class AbstractBatteryApplicationFactory
{
public:

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractBatteryApplicationFactory() {}

    /**
     * @brief Creates instruments model
     * @return AbstractInstrumentsModel*
     */
    virtual std::unique_ptr<AbstractInstrumentsModel> createInstrumentsModel() = 0;
};

#endif // ABSTRACTBATTERYAPPLICATIONFACTORY_H
