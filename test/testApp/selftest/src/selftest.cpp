#include <gmock/gmock.h>
#include "selftestobjectmock.h"

using namespace testing;

class SelfTest : public Test
{
};

TEST_F(SelfTest, test_delete)
{
   SelfTestObjectMock* mockObject = new NiceMock<SelfTestObjectMock>;
   EXPECT_CALL(*mockObject, destruction()).Times(1);
   delete mockObject;
}

TEST_F(SelfTest, test_delete_later)
{
   SelfTestObjectMock* mockObject = new NiceMock<SelfTestObjectMock>;
   EXPECT_CALL(*mockObject, destruction()).Times(1);
   mockObject->deleteLater();
}
