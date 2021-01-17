#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "processing/solution.cpp"

using namespace testing;

namespace p8
{
    using Solution = Solution;

    TEST(test_8, Case_1)
    {
        Solution s;
        std::string input = "42";
        int result = s.myAtoi(input);
        int expect = 42;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_2)
    {
        Solution s;
        std::string input = "   -42";
        int result = s.myAtoi(input);
        int expect = -42;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_3)
    {
        Solution s;
        std::string input = "4193 with words";
        int result = s.myAtoi(input);
        int expect = 4193;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_4)
    {
        Solution s;
        std::string input = "words and 987";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_5)
    {
        Solution s;
        std::string input = "-91283472332";
        int result = s.myAtoi(input);
        int expect = -pow(2, 31);
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_1)
    {
        Solution s;
        std::string input = "91283472332";
        int result = s.myAtoi(input);
        int expect = pow(2, 31) - 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_2)
    {
        Solution s;
        std::string input = "-+--+-+-999";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_3)
    {
        Solution s;
        std::string input = "-+009";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_4)
    {
        Solution s;
        std::string input = "+-xx99";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_1)
    {
        Solution s;
        std::string input = "  +0 123";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_2)
    {
        Solution s;
        std::string input = "-2147483648";
        int result = s.myAtoi(input);
        int expect = -2147483648;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_3)
    {
        Solution s;
        std::string input = "-5-";
        int result = s.myAtoi(input);
        int expect = -5;
        ASSERT_EQ(result, expect);
    }
} // namespace p8