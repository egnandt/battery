#ifndef ABSTRACTTEMPERATURELOADER_H
#define ABSTRACTTEMPERATURELOADER_H

#include <QObject>

class AbstractTemperatureLoader : public QObject
{
    Q_OBJECT
public:

    virtual ~AbstractTemperatureLoader() = 0;
    /**
     * @brief startLoad
     * @return
     */
    virtual void startLoad() = 0;

public slots:
    //virtual void taskFinished() = 0;
};

#endif // ABSTRACTTEMPERATURELOADER_H
