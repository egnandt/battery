#ifndef BATTERYAPPLICATIONFACTORY_H
#define BATTERYAPPLICATIONFACTORY_H

#include "abstractbatteryapplicationfactory.h"

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
    std::unique_ptr<AbstractInstrumentsModel> createInstrumentsModel();
};

#endif // BATTERYAPPLICATIONFACTORY_H
