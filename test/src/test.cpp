#include <gtest/gtest.h>
#include "test.h"


TEST(testCase, test0){
    EXPECT_EQ(Add(2,3),5);
}

TEST(testCase, test1){
    EXPECT_EQ(Add(3,3),6);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}