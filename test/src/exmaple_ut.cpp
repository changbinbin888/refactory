#include <gtest/gtest.h>
#include "exmaple_test.h"

TEST(testCase, test0){
    EXPECT_EQ(Add(2, 3), 5);
}

TEST(testCase, test1){
    EXPECT_EQ(Add(3, 3), 6);
}

TEST(testCase, test3){
    EXPECT_EQ(Add(3, 3), 6);
}