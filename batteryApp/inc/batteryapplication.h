#ifndef BATTERYAPPLICATION_H
#define BATTERYAPPLICATION_H

#include <QString>
#include <memory>

class QQuickView;
class AbstractInstrumentsModel;
class AbstractBatteryApplicationFactory;

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
    explicit BatteryApplication(std::unique_ptr<AbstractBatteryApplicationFactory> aFactory, const QString& installRoot);

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

    /**
     * @brief an AbstractBatteryApplicationFactory member, the application factory
     */
    std::unique_ptr<AbstractBatteryApplicationFactory> m_factory;

    /**
     * @brief a QQuickView member, the QML viewer
     */
    std::unique_ptr<QQuickView> m_qmlViewer;

    /**
     * @brief an AbstractInstrumentsModel member, the instruments viewmodel
     */
    std::unique_ptr<AbstractInstrumentsModel> m_instrumentsModel;
};

#endif // BATTERYAPPLICATION_H
