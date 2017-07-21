#ifndef CSVLOADER_H
#define CSVLOADER_H
#include "icsvloader.h"
#include <memory>
class CSVLoader : public ICSVLoader
{
public:
    boolean startLoad(Model m, QFile file);
};
#endif // CSVLOADER_H
