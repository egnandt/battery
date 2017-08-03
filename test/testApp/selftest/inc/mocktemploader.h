#ifndef MOCKTEMPLOADER_H
#define MOCKTEMPLOADER_H
#include "abstracttemperatureloader.h"
#include <memory>

class MockTempLoader : public ITempLoader
{
public:
    bool startLoad();
};

#endif // MOCKTEMPLOADER_H
