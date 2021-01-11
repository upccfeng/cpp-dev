#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "processing/solution.cpp"

using namespace testing;

namespace pXX
{
    using Solution = Solution;
    TEST(test_XX, Case_1)
    {
        Solution s;
        std::vector<int> input = {};
        int result = s.XX(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace pXX
