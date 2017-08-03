#include "batteryapplicationfactory.h"
#include "instrumentsmodel.h"
#include "model.h"
#include "temperatureloader.h"
#include "batteryapplication.h"
#include "csvloader.h"
#include "engine.h"
#include "batteryapplication.h"
#include "rangecalculator.h"
#include "gradientcalculator.h"
#include "uidrawer.h"
#include "plotviewmodel.h"

BatteryApplicationFactory::BatteryApplicationFactory()
{

}

BatteryApplicationFactory::~BatteryApplicationFactory()
{

}

std::unique_ptr<BatteryApplication> BatteryApplicationFactory::createApp(const QString& installRoot)
{
    std::unique_ptr<AbstractModel> model = std::make_unique<Model>(" ");
    std::unique_ptr<CSVLoader> csvLoader = std::make_unique<CSVLoader>(*model.get());
    std::unique_ptr<TemperatureLoader> temperatureLoader = std::make_unique<TemperatureLoader>(*model.get());
    std::unique_ptr<GradientCalculator> gradientCalculator = std::make_unique<GradientCalculator>(*model.get());
    std::unique_ptr<RangeCalculator> rangeCalculator = std::make_unique<RangeCalculator>(*model.get());
    std::unique_ptr<InstrumentsModel> instrumentsModel = std::make_unique<InstrumentsModel>();
    std::unique_ptr<PlotViewModel> plotViewModel = std::make_unique<PlotViewModel>();
    std::unique_ptr<UIDrawer> uiDrawer = std::make_unique<UIDrawer>(*model.get(), *plotViewModel.get());
    std::unique_ptr<Engine> engine = std::make_unique<Engine>(std::move(model), *plotViewModel.get(), *csvLoader.get(), *temperatureLoader.get(),
                                                              *gradientCalculator.get(), *rangeCalculator.get(), *uiDrawer.get());
    csvLoader->setCallback(engine.get());
    temperatureLoader->setCallback(engine.get());
    gradientCalculator->setCallback(engine.get());
    rangeCalculator->setCallback(engine.get());
    uiDrawer->setCallback(engine.get());
    return std::make_unique<BatteryApplication>(installRoot , std::move(engine), std::move(csvLoader),
                                                std::move(temperatureLoader), std::move(gradientCalculator),
                                                std::move(rangeCalculator), std::move(uiDrawer),
                                                std::move(instrumentsModel), std::move(plotViewModel));
}
