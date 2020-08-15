#include <iostream>
#include "gtest/gtest.h"

TEST(test_processing, HelloWorld)
{
    int a = 10;
    ASSERT_EQ(a, 10);
}