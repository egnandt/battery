#ifndef Q_MOC_RUN
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#endif
#include <QEvent>

#include "testapplication.h"

const QEvent::Type TestApplication::RUN_TESTS_EVENT = static_cast<QEvent::Type>(QEvent::registerEventType());


TestApplication::TestApplication(int& argc, char** argv):
    QCoreApplication(argc, argv)
{
    ::testing::InitGoogleMock(&argc, argv);
}

TestApplication::~TestApplication()
{
}

bool TestApplication::event(QEvent* pEvent)
{
    if(pEvent && RUN_TESTS_EVENT ==  pEvent->type())
    {
        int ret = RUN_ALL_TESTS();
        QCoreApplication::exit(ret);
    }
    return QCoreApplication::event(pEvent);
}
