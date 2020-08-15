#include <iostream>
#include "gtest/gtest.h"

TEST(test_tool, HelloWorld)
{
    int a = 10;
    ASSERT_EQ(a, 10);
}