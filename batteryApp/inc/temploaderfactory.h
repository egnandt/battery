#ifndef TEMPLOADERFACTORY_H
#define TEMPLOADERFACTORY_H

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
