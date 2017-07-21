#ifndef ITEMPLOADERFACTORY_H
#define ITEMPLOADERFACTORY_H

#include <memory>

/**
 * @brief The abstract factory (interface) ITempLoaderFactory class
 */
class ITempLoaderFactory
{
public:
    virtual CreateTempLoader() = 0;
    virtual CreateMockTempLoader() = 0;
};

#endif // ITEMPLOADERFACTORY_H
