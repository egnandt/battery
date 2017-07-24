#ifndef ABSTRACTTEMPERATURELOADER_H
#define ABSTRACTTEMPERATURELOADER_H

#include <QObject>
#include "coordinates.h"

class AbstractTemperatureLoader : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief startLoad
     * @return
     */
    virtual float startLoad(t_Coordinates) = 0;
};

#endif // ABSTRACTTEMPERATURELOADER_H
