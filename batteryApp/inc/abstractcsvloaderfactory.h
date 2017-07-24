#ifndef ABSTRACTCSVLOADERFACTORY_H
#define ABSTRACTCSVLOADERFACTORY_H

#include <memory>

class AbstractCSVLoader;

class AbstractCSVLoaderFactory
{
public:

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractCSVLoaderFactory() {}

    /**
     * @brief Creates CSV loader
     * @return  AbstractCSVLoader*
     */
    virtual std::unique_ptr<AbstractCSVLoader> createCSVLoader() = 0;
};

#endif // ABSTRACTCSVLOADERFACTORY_H
