#ifndef TEMPLOADERFACTORY_H
#define TEMPLOADERFACTORY_H
#include "itemploaderfactory.h"
/**
 * @brief The concrete factory TempLoaderFactory class
 */
class TempLoaderFactory : public ITempLoaderFactory
{
public:
    TempLoaderFactory();
    ITempLoader CreateTempLoader();
};

#endif // TEMPLOADERFACTORY_H
