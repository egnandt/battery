#ifndef MOCKTEMPLOADER_H
#define MOCKTEMPLOADER_H
#include "abstracttemploader.h"
#include <memory>

class MockTempLoader : public ITempLoader
{
public:
    bool startLoad();
};

#endif // MOCKTEMPLOADER_H
