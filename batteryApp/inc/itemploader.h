#ifndef ITEMPLOADER_H
#define ITEMPLOADER_H

#include <memory>
#include <QString>

/**
 * @brief The abstract product (interface) ITempLoader class
 */
class ITempLoader
{
public:
    virtual boolean startLoad() = 0;
};

#endif // ITEMPLOADER_H
