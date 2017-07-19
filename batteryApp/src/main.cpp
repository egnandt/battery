#include <QApplication>
#include <QDir>
#include <memory>

#include "batteryapplication.h"
#include "batteryapplicationfactory.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    BatteryApplication battApp(std::make_unique<BatteryApplicationFactory>(), QDir::cleanPath(QCoreApplication::applicationDirPath()));
    battApp.initialize();
    return app.exec();
}
