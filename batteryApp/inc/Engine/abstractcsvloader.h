#ifndef ABSTRACTCSVLOADER_H
#define ABSTRACTCSVLOADER_H
#include <QString>

class AbstractCSVLoader
{
public:

    virtual ~AbstractCSVLoader() = 0;
    /**
     * @brief startLoad
     * @return
     */
    virtual void setPath(const QString& path)= 0;

    virtual void startLoad() = 0;
};

#endif // ABSTRACTCSVLOADER_H
