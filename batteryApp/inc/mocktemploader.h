#ifndef MOCKTEMPLOADER_H
#define MOCKTEMPLOADER_H
#include "itemploader.h"
#include <memory>

class MockTempLoader : public ITempLoader
{
public:
    boolean startLoad();
};

#endif // MOCKTEMPLOADER_H
