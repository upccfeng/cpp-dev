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

namespace p_344
{
    class Solution {
    public:
        void reverseString(std::vector<char>& s)
        {
            int l = 0;
            int r = s.size() - 1;

            while (l < r)
            {
                std::swap(s[l], s[r]);
                l++;
                r--;
            }
        }
    };
} // namespace p_344

/*
# Problem:
https://leetcode.com/problems/reverse-string/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/