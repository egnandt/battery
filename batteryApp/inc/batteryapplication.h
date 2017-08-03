#ifndef BATTERYAPPLICATION_H
#define BATTERYAPPLICATION_H

#include <QString>
#include <memory>

/* Forward declaration */
class QQuickView;
class AbstractBatteryApplicationFactory;
class AbstractCSVLoader;
class AbstractTemperatureLoader;
class IStateCallback;
class AbstractRangeCalculator;
class Engine;
class AbstractGradientCalculator;
class AbstractUIDrawer;
class AbstractInstrumentsModel;
class AbstractPlotViewModel;

/**
 * @brief The BatteryApplication class
 */
class BatteryApplication
{
public:

    /**
     * @brief Constructor
     * @param installRoot - a const QString& argument, the path to the application binary folder
     */
    explicit BatteryApplication(const QString& installRoot, std::unique_ptr<Engine> engine,
                                std::unique_ptr<AbstractCSVLoader> csvLoader,
                                std::unique_ptr<AbstractTemperatureLoader> temperatureLoader,
                                std::unique_ptr<AbstractGradientCalculator> gradientCalculator,
                                std::unique_ptr<AbstractRangeCalculator> rangeCalculator,
                                std::unique_ptr<AbstractUIDrawer> uiDrawer,
                                std::unique_ptr<AbstractInstrumentsModel> instrumentsModel,
                                std::unique_ptr<AbstractPlotViewModel> plotViewModel);

    /**
     * @brief Destructor
     */
    ~BatteryApplication();

    /**
     * @brief Initialize Battery Graph Application
     * @return bool, whether the initialization process succeded
     */
    bool initialize();

private:

    /**
     * @brief Register custom QML types
     */
    void registerCustomQMLTypes();

    /**
     * @brief Register objects to QML root context
     */
    void registerRootContextProperties();

    /**
     * @brief Clean up application
     */
    void cleanup();

    /**
     * @brief Initialize qml viewer, setting qml entry path
     * @return bool, whether the initialization process succeded
     */
    bool initializeQmlViewer();

private:

    /**
     * @brief the path to the application binary folder
     */
    QString m_installRoot;

    std::unique_ptr<Engine> m_engine;

    std::unique_ptr<AbstractCSVLoader> m_CSVLoader;

    std::unique_ptr<AbstractTemperatureLoader> m_temperatureLoader;

    std::unique_ptr<AbstractGradientCalculator> m_gradientCalculator;

    std::unique_ptr<AbstractRangeCalculator> m_rangeCalculator;

    std::unique_ptr<AbstractUIDrawer> m_uiDrawer;
    /**
     * @brief an AbstractInstrumentsModel member, the instruments viewmodel
     */
    std::unique_ptr<AbstractInstrumentsModel> m_instrumentsModel;

    std::unique_ptr<AbstractPlotViewModel> m_plotViewModel;

    /**
     * @brief a QQuickView member, the QML viewer
     */
    std::unique_ptr<QQuickView> m_qmlViewer;
};

#endif // BATTERYAPPLICATION_H
