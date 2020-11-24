#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "processing/solution.hpp"

using namespace testing;

TEST(test_processing, Case_1)
{
    Solution s;
    string input = "ababcbacadefegdehijhklij";
    auto result = s.partitionLabels(input);
    vector<int> expect = {9, 7, 8};
    ASSERT_EQ(result, expect);
}