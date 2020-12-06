#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "processing/solution.cpp"

using namespace testing;

namespace p5
{
    TEST(test_5, Case_1)
    {
        Solution s;
        string result = s.longestPalindrome("babad");
        string expect = "bab";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_2)
    {
        Solution s;
        string result = s.longestPalindrome("cbbd");
        string expect = "bb";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_3)
    {
        Solution s;
        string result = s.longestPalindrome("a");
        string expect = "a";
        ASSERT_EQ(result, expect);
    }

    TEST(test_5, Case_4)
    {
        Solution s;
        string result = s.longestPalindrome("ac");
        string expect = "a";
        ASSERT_EQ(result, expect);
    }
} // namespace p5
