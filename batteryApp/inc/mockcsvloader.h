#ifndef MOCKCSVLOADER_H
#define MOCKCSVLOADER_H
#include "icsvloader.h"
#include <memory>

class MockCSVLoader : public ICSVLoader
{
public:
    boolean startLoad();
};
#endif // MOCKCSVLOADER_H

