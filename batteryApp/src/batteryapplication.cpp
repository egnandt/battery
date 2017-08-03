#include <QQuickView>
#include <QQmlContext>
#include <QDir>
#include <iostream>

#include "batteryapplication.h"
#include "abstractbatteryapplicationfactory.h"
#include "abstractinstrumentsmodel.h"
#include "abstractcsvloader.h"
#include "abstracttemperatureloader.h"
#include "abstractrangecalculator.h"
#include "abstractgradientcalculator.h"
#include "abstractuidrawer.h"
#include "abstractplotviewmodel.h"
#include "engine.h"
#include <memory>

BatteryApplication::BatteryApplication(const QString& installRoot,
                                       std::unique_ptr<Engine> engine,
                                       std::unique_ptr<AbstractCSVLoader> csvLoader,
                                       std::unique_ptr<AbstractTemperatureLoader> temperatureLoader,
                                       std::unique_ptr<AbstractGradientCalculator> gradientCalculator,
                                       std::unique_ptr<AbstractRangeCalculator> rangeCalculator,
                                       std::unique_ptr<AbstractUIDrawer> uiDrawer,
                                       std::unique_ptr<AbstractInstrumentsModel> instrumentsModel,
                                       std::unique_ptr<AbstractPlotViewModel> plotViewModel) :
    m_installRoot(installRoot),
    m_engine(std::move(engine)),
    m_CSVLoader(std::move(csvLoader)),
    m_temperatureLoader(std::move(temperatureLoader)),
    m_gradientCalculator(std::move(gradientCalculator)),
    m_rangeCalculator(std::move(rangeCalculator)),
    m_uiDrawer(std::move(uiDrawer)),
    m_instrumentsModel(std::move(instrumentsModel)),
    m_plotViewModel(std::move(plotViewModel)),
    m_qmlViewer(nullptr)
{

}

BatteryApplication::~BatteryApplication()
{
    cleanup();
}

bool BatteryApplication::initialize()
{
    cleanup();

    bool ret = true;

    // Register custom QML types (creatable and uncreatable)
    registerCustomQMLTypes();

    // Creating application lifetime objects
    m_qmlViewer = std::make_unique<QQuickView>();


    // Register root context properties
    registerRootContextProperties();

    // Component initializations
    ret = ret && initializeQmlViewer();

    // Open application window
    if(m_qmlViewer)
    {
        m_qmlViewer->show();
    }
    m_engine->run();
    return ret;
}

void BatteryApplication::registerCustomQMLTypes()
{
    qmlRegisterUncreatableType<AbstractInstrumentsModel>("BatteryApp", 1, 0, "AbstractInstrumentsModel", "Cannot be created in QML!");
    qmlRegisterUncreatableType<AbstractPlotViewModel>("BatteryApp", 1, 0, "AbstractPlotViewModel", "Cannot be created in QML!");
}

void BatteryApplication::registerRootContextProperties()
{
    m_qmlViewer->rootContext()->setContextProperty("instrumentsModel", m_instrumentsModel.get());
    m_qmlViewer->rootContext()->setContextProperty("plotViewModel", m_plotViewModel.get());
}

void BatteryApplication::cleanup()
{
    m_qmlViewer.reset(nullptr); // Always must be the first destroyed object!!!
    m_instrumentsModel.reset(nullptr);
    m_plotViewModel.reset(nullptr);
}

bool BatteryApplication::initializeQmlViewer()
{
    if(m_qmlViewer)
    {
        m_qmlViewer->setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
        return true;
    }

    std::cout << "Failed to initialize QML viewer!" << std::endl;
    return false;
}
