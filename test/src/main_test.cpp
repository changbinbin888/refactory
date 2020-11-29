#include <iostream>
#include <gtest/gtest.h>
#include "main_test.h"

using namespace std;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    cout << "test begin" << endl;
    return RUN_ALL_TESTS();
}