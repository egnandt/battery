#include "testapplication.h"

int main(int argc, char** argv)
{
   TestApplication app(argc, argv);
   app.postEvent(&app, new QEvent(TestApplication::RUN_TESTS_EVENT));
   return app.exec();
}
