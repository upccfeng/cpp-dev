#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include <stdint.h>

////////// include the needed std container ////////////

// using namespace std;
#include "assert.h"
// #include <vector>
// #include <map>
#include <string>
// #include <sstream>
// #include <algorithm>
// #include <set>
#include <unordered_map>
#include <queue>
// #include <stack>
// #include <cmath>
// ...

////////////////////////////////////////////////////////

namespace p_2207_biweekly_74
{
    class Solution {
    public:
        long long maximumSubsequenceCount(std::string text, std::string pattern)
        {
            char c1 = pattern[0];
            char c2 = pattern[1];

            if (c1 == c2)
            {
                long long cnt = 0;
                for (int i = 0; i < text.size(); i++)
                {
                    if (text[i] == c1)
                    {
                        cnt++;
                    }
                }

                return (1 + cnt) * cnt / 2;
            }

            std::string new_text = c1 + text + c2;
            long long pre_cnt = 0;
            long long total_cnt = 0;

            long long front_cnt = 0;
            for (int i = 0; i < new_text.size() - 1; i++)
            {
                if (new_text[i] == c1)
                {
                    pre_cnt++;
                }
                else if (new_text[i] == c2)
                {
                    front_cnt += pre_cnt + total_cnt;
                    total_cnt += pre_cnt;
                    pre_cnt = 0;
                }
            }

            pre_cnt = 0;
            total_cnt = 0;

            long long back_cnt = 0;
            for (int i = 1; i < new_text.size(); i++)
            {
                if (new_text[i] == c1)
                {
                    pre_cnt++;
                }
                else if (new_text[i] == c2)
                {
                    back_cnt += pre_cnt + total_cnt;
                    total_cnt += pre_cnt;
                    pre_cnt = 0;
                }
            }

            return front_cnt > back_cnt ? front_cnt : back_cnt;
        }
    };
} // namespace p_2207_biweekly_74

/*
# Problem:
https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

## HINT:
* Calculate the numbers of pattern[0] is front of pattern[1].
* Deal with the case which pattern[0] is the same as pattern[1].

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/