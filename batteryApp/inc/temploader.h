#ifndef TEMPLOADER_H
#define TEMPLOADER_H

#include <memory>

/**
 * @brief The product TempLoader class
 */
class TempLoader : public ITempLoader
{
public:
    boolean startLoad();
};

#endif // TEMPLOADER_H