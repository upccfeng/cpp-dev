#include <iostream>
#include "gtest/gtest.h"

TEST(hello, test)
{
    int a = 10;
    ASSERT_EQ(a, 10);
}