#ifndef ICSVLOADER_H
#define ICSVLOADER_H

#include <memory>
#include <QString>

class ICSVLoader
{
public:
    virtual boolean startLoad() = 0;
};

class CSVLoader : public ICSVLoader
{
public:
    boolean startLoad(Model m, QFile file);
};

#endif // ICSVLOADER_H
