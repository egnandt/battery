#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <QPointF>

struct DataPoint
{
    QPointF m_coordinates;
    float m_temperature;
    float m_elevation;
};

#endif // DATAPOINT_H
