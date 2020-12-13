#include <gtest/gtest.h>
#include "mockcpp/mockcpp.h"
#include "mockcpp/mokc.h"
#include "example_test.h"
#include "../../source/include/example.h"

using namespace std;

class GtestUt : public testing::Test
{
protected:
    void SetUp() override
    {
        cout << "--Gtest_Ut SetUP--" << endl;
    }

    void TearDown() override
    {
        cout << "--Gtest_Ut TearDown--" << endl;
    }
};

TEST_F(GtestUt, ut_add_01)
{
    MOCKER(Add)
    .expects(atMost(20))
    .will(returnValue(100));
    EXPECT_EQ(Add(2, 3), 100);
}

TEST(testCase, test0)
{
    EXPECT_EQ(Add(2, 3), 5);
}

TEST(testCase, test1)
{
    EXPECT_EQ(Add(3, 3), 6);
}

TEST(testCase, test3)
{
    EXPECT_EQ(Add(3, 3), 6);
}