#ifndef ABSTRACTUIDRAWER_H
#define ABSTRACTUIDRAWER_H

class AbstractUIDrawer
{
public:

    virtual ~AbstractUIDrawer() = 0;

    virtual void startDraw() = 0;
};

#endif // ABSTRACTUIDRAWER_H
