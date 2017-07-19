#include "batteryapplicationfactory.h"
#include "instrumentsmodel.h"

BatteryApplicationFactory::BatteryApplicationFactory()
{

}

BatteryApplicationFactory::~BatteryApplicationFactory()
{

}

std::unique_ptr<AbstractInstrumentsModel> BatteryApplicationFactory::createInstrumentsModel()
{
    return std::make_unique<InstrumentsModel>();
}
