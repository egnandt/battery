#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

#include <QCoreApplication>

/**
 * @class TestApplication
 * @brief Test application class.
 *        Required for starting a Qt event loop
 */
class TestApplication: public QCoreApplication
{
   Q_OBJECT

public:
   /**
    * @brief Constructor
    * @param argc a int& argument, the number of arguments.
    * @param argv a char** argument. The arguments array.
    */
   TestApplication(int& argc, char** argv);

   /**
    * @brief Virtual destructor
    */
   virtual ~TestApplication();

protected: // From QCoreApplication
   bool	event(QEvent* pEvent);

public:
   /**
    * @brief Event type for triggering test startup
    */
   static const QEvent::Type RUN_TESTS_EVENT;
};

#endif // TESTAPPLICATION_H

