#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include <stdint.h>

////////// include the needed std container ////////////

// using namespace std;
// #include <vector>
// #include <map>
// #include <string>
// #include <algorithm>
// #include <set>
// #include <unordered_map>
// ...

////////////////////////////////////////////////////////

namespace pXX
{
    class Solution
    {
    public:
        int xx(std::vector<int> &xx)
        {
            return 0;
        }
    };
} // namespace pXX

namespace pXX
{
    using Solution = Solution;

    TEST(test_XX, Case_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 0 };
        RetsultType result = s.xx(input);
        RetsultType expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace pXX

/*
# Problem:

## HINT:

## Time Complexity:

## Space Complexity:
*/