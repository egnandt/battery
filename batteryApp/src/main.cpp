#include <QApplication>
#include <QDir>
#include <memory>

#include "batteryapplication.h"
#include "batteryapplicationfactory.h"
#include "temperatureloader.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //TemperatureLoader test;
    //test.startLoad({{45, 54}, {43, 54}});
    BatteryApplicationFactory battAppFact;
    std::unique_ptr<BatteryApplication> application = battAppFact.createApp(QDir::cleanPath(QCoreApplication::applicationDirPath()));
    application->initialize();
    return app.exec();
}
