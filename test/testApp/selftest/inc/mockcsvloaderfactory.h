#ifndef MOCKCSVLOADERFACTORY_H
#define MOCKCSVLOADERFACTORY_H
#include "icsvloaderfactory.h"

/**
 * @brief The concrete MockCSVLoaderFactory class used for gmock/gtest
 */
class MockCSVLoaderFactory : public ICSVLoaderFactory
{
public:
    MockCSVLoaderFactory();
    MockCSVLoader CreateMockCSVLoader();
};
#endif // MOCKCSVLOADERFACTORY_H
