#ifndef ICSVLOADERFACTORY_H
#define ICSVLOADERFACTORY_H

#include <memory>

/**
 * @brief The abstract factory (interface) ICSVLoaderFactory class
 */
class ICSVLoaderFactory
{
public:
    virtual CreateCSVLoader() = 0;
    virtual CreateMockCSVLoader() = 0;
};
#endif // ICSVLOADERFACTORY_H
