#ifndef MOCKTEMPLOADERFACTORY_H
#define MOCKTEMPLOADERFACTORY_H
#include "abstracttemperatureloaderfactory.h"
/**
 * @brief The concrete MockTempLoaderFactory class used for gmock/gtest
 */
class MockTempLoaderFactory : public ITempLoaderFactory
{
public:
    MockTempLoaderFactory();
    MockTempLoader CreateMockTempLoader();
};

#endif // MOCKTEMPLOADERFACTORY_H
