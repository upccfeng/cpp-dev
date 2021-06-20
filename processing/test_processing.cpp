#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

////////// include the needed std container ////////////

// using namespace std;
// #include <vector>
// #include <map>
// #include <string>
// ...

////////////////////////////////////////////////////////

namespace pXX
{
    class Solution
    {
    public:
        int xx(int xx)
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
        int input = 0;
        int result = s.xx(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace pXX

/*
# Problem:

## HINT:

## Algorithm:

## Time Complexity:

## Space Complexity:
*/