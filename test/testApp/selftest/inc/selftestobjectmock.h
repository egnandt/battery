#ifndef SELFTESTOBJECTMOCK_H
#define SELFTESTOBJECTMOCK_H

#include <gmock/gmock.h>
#include <QObject>

class SelfTestObjectMock : public QObject
{
   Q_OBJECT
public:
   ~SelfTestObjectMock()
   {
      destruction();
   }

public: // MOCK methods
   MOCK_METHOD0(destruction, void());
};


#endif // SELFTESTOBJECTMOCK_H

