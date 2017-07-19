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

/**
 * @brief The concrete factory CSVLoaderFactory class
 */
class CSVLoaderFactory
{
public:
    CSVLoaderFactory();
    CSVLoader CreateCSVLoader();
};

/**
 * @brief The concrete MockCSVLoaderFactory class used for gmock/gtest
 */
class MockCSVLoaderFactory : public ICSVLoaderFactory
{
public:
    MockCSVLoaderFactory();
    MockTempLoader CreateMockCSVLoader();
};

#endif // ICSVLOADERFACTORY_H
