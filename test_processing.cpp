#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "processing/solution.cpp"

using namespace testing;

namespace p11
{
    using Solution = Solution;
    TEST(test_11, Case_1)
    {
        Solution s;
        std::vector<int> height = {1, 8, 6, 2, 5, 4, 8 ,3 ,7};
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_2)
    {
        Solution s;
        std::vector<int> height = {1, 1};
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_3)
    {
        Solution s;
        std::vector<int> height = {4, 3, 2, 1, 4};
        int result = s.maxArea(height);
        int expect = 16;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_4)
    {
        Solution s;
        std::vector<int> height = {1, 2, 1};
        int result = s.maxArea(height);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_customize_1)
    {
        Solution s;
        std::vector<int> height = {5, 4, 3, 2, 1, 1};
        int result = s.maxArea(height);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_1)
    {
        Solution s;
        std::vector<int> height = {2, 3, 10, 5, 7, 8, 9};
        int result = s.maxArea(height);
        int expect = 36;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_2)
    {
        Solution s;
        std::vector<int> height = {0, 2};
        int result = s.maxArea(height);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_3)
    {
        Solution s;
        std::vector<int> height = {1, 2};
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_4)
    {
        Solution s;
        std::vector<int> height = {1, 2, 4, 3};
        int result = s.maxArea(height);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_5)
    {
        Solution s;
        std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 25, 7};
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }
} // namespace p11
