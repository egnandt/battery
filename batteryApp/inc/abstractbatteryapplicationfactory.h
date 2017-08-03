#ifndef ABSTRACTBATTERYAPPLICATIONFACTORY_H
#define ABSTRACTBATTERYAPPLICATIONFACTORY_H

#include <memory>
#include <batteryapplication.h>

class AbstractBatteryApplicationFactory
{
public:

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractBatteryApplicationFactory() {}

    virtual std::unique_ptr<BatteryApplication> createApp(const QString& installRoot) = 0;
};
#endif // ABSTRACTBATTERYAPPLICATIONFACTORY_H
