#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include "763.cpp"

namespace p763
{
    TEST(test_processing, Case_1)
    {
        Solution s;
        string input = "ababcbacadefegdehijhklij";
        auto result = s.partitionLabels(input);
        vector<int> expect = {9, 7, 8};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_sigle)
    {
        Solution s;
        string input = "a";
        auto result = s.partitionLabels(input);
        vector<int> expect = {1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_the_same)
    {
        Solution s;
        string input = "aaaaa";
        auto result = s.partitionLabels(input);
        vector<int> expect = {5};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_usecase_1)
    {
        Solution s;
        string input = "aaabbbccc";
        auto result = s.partitionLabels(input);
        vector<int> expect = {3, 3, 3};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_usecase_2)
    {
        Solution s;
        string input = "aaabbbccca";
        auto result = s.partitionLabels(input);
        vector<int> expect = {10};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_usecase_3)
    {
        Solution s;
        string input = "aaabbbcccabgkgge";
        auto result = s.partitionLabels(input);
        vector<int> expect = {11, 4, 1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_processing, Case_wrong_1)
    {
        Solution s;
        string input = "caedbdedda";
        auto result = s.partitionLabels(input);
        vector<int> expect = {1, 9};
        ASSERT_EQ(result, expect);
    }
} // namespace p763