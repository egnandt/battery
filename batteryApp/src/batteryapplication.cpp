#include <QQuickView>
#include <QQmlContext>
#include <QDir>
#include <iostream>

#include "batteryapplication.h"
#include "abstractbatteryapplicationfactory.h"
#include "abstractinstrumentsmodel.h"

BatteryApplication::BatteryApplication(std::unique_ptr<AbstractBatteryApplicationFactory> aFactory, const QString &installRoot) :
    m_installRoot(installRoot),
    m_factory(std::move(aFactory)),
    m_qmlViewer(nullptr),
    m_instrumentsModel(nullptr)
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
    m_instrumentsModel = m_factory->createInstrumentsModel();

    // Register root context properties
    registerRootContextProperties();

    // Component initializations
    ret = ret && initializeQmlViewer();

    // Open application window
    if(m_qmlViewer)
    {
        m_qmlViewer->show();
    }

    return ret;
}

void BatteryApplication::registerCustomQMLTypes()
{
    qmlRegisterUncreatableType<AbstractInstrumentsModel>("BatteryApp", 1, 0, "AbstractInstrumentsModel", "Cannot be created in QML!");
}

void BatteryApplication::registerRootContextProperties()
{
    m_qmlViewer->rootContext()->setContextProperty("instrumentsModel", m_instrumentsModel.get());
}

void BatteryApplication::cleanup()
{
    m_qmlViewer.reset(nullptr); // Always must be the first destroyed object!!!
    m_instrumentsModel.reset(nullptr);
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
