#include <QApplication>
#include <QDir>

#include "batteryapplication.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    BatteryApplication battApp(QDir::cleanPath(QCoreApplication::applicationDirPath()));
    battApp.initialize();
    return app.exec();
}
