#include <QQuickView>
#include <QDir>
#include <iostream>

#include "batteryapplication.h"

BatteryApplication::BatteryApplication(const QString &installRoot) :
    m_installRoot(installRoot),
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

    // Component initializations
    ret = ret && initializeQmlViewer();

    // Register root context properties
    registerRootContextProperties();

    // Open application window
    if(m_qmlViewer)
    {
        m_qmlViewer->show();
    }

    return ret;
}

void BatteryApplication::registerCustomQMLTypes()
{
}

void BatteryApplication::registerRootContextProperties()
{
}

void BatteryApplication::cleanup()
{
    m_qmlViewer.reset(nullptr); // Always must be the first destroyed object!!!
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
