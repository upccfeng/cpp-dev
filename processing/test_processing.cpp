#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include <stdint.h>

////////// include the needed std container ////////////

// using namespace std;
#include "assert.h"
// #include <vector>
// #include <map>
// #include <string>
// #include <sstream>
// #include <algorithm>
// #include <set>
// #include <unordered_map>
// #include <queue>
// #include <stack>
// #include <cmath>
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
        using RetsultType = int;

        std::vector<int> input = { 0 };
        RetsultType result = s.xx(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace pXX

/*
# Problem:

## HINT:

## Time Complexity:

## Space Complexity:
*/