#ifndef MOCKCSVLOADERFACTORY_H
#define MOCKCSVLOADERFACTORY_H
#include "abstractcsvloaderfactory.h"

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
