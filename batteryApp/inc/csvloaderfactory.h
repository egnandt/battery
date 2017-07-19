#ifndef CSVLOADERFACTORY_H
#define CSVLOADERFACTORY_H
#include "icsvloaderfactory.h"
/**
 * @brief The concrete factory CSVLoaderFactory class
 */
class CSVLoaderFactory : public ICSVLoaderFactory
{
public:
    CSVLoaderFactory();
    CSVLoader CreateCSVLoader();
};
#endif // CSVLOADERFACTORY_H
