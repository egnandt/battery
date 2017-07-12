#include <QGuiApplication>
#include <QDir>

#include "batteryapplication.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    BatteryApplication battApp(QDir::cleanPath(QCoreApplication::applicationDirPath()));
    battApp.initialize();
    return app.exec();
}
