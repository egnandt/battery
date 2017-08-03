#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "abstractcsvloader.h"
#include "istate.h"
#include "basestate.h"
#include <memory>
#include <model.h>

class CSVLoader: public AbstractCSVLoader, public BaseState
{

public:// From AbstractCSVLoader

    CSVLoader(AbstractModel &aModel);

    void runState();

    void startLoad();

    void setPath(const QString& path);

protected:
    AbstractModel &m_model;

private:
    QString m_path;
};
#endif // CSVLOADER_H
