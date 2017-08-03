#ifndef BATTERYAPPLICATIONFACTORY_H
#define BATTERYAPPLICATIONFACTORY_H

#include "abstractbatteryapplicationfactory.h"
#include "batteryapplication.h"

class BatteryApplicationFactory: public AbstractBatteryApplicationFactory
{
public:

    /**
     * @brief Constructor
     */
    BatteryApplicationFactory();

    /**
     * @brief Destructor
     */
    ~BatteryApplicationFactory();

public: // From AbstractBatteryApplicationFactory
    std::unique_ptr<BatteryApplication> createApp(const QString& installRoot);
};

#endif // BATTERYAPPLICATIONFACTORY_H
