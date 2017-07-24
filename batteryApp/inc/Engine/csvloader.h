#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "abstractcsvloader.h"
#include <memory>

class CSVLoader: public AbstractCSVLoader
{
public: // From AbstractCSVLoader

    /**
     * @brief startLoad
     * @param m
     * @param file
     * @return
     */
    bool startLoad(Model m, QFile file);
};
#endif // CSVLOADER_H
