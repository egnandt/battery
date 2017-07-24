#ifndef CSVLOADERFACTORY_H
#define CSVLOADERFACTORY_H

#include "abstractcsvloaderfactory.h"

class CSVLoaderFactory: public AbstractCSVLoaderFactory
{
public:

    /**
     * @brief Constructor
     */
    CSVLoaderFactory();

    /**
     * @brief Destructor
     */
    ~CSVLoaderFactory();

public: // From AbstractCSVLoaderFactory
    std::unique_ptr<AbstractCSVLoader> createCSVLoader();
};

#endif // CSVLOADERFACTORY_H
