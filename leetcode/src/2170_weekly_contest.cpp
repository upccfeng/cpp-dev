#include <vector>
#include <map>

namespace p_2170_weekly_contest
{
    class Solution {

    public:
        int minimumOperations(std::vector<int>& nums)
        {
            if (nums.size() == 1)
            {
                return 0;
            }

            std::map<int, std::pair<int, int>> dict;

            int odd, even;
            odd = 0;
            even = 0;

            for (int i = 0; i < nums.size(); ++i)
            {
                if (dict.find(nums[i]) == dict.end())
                {
                    dict[nums[i]] = { 0, 0 };
                }

                if (i % 2 == 0)
                {
                    ++dict[nums[i]].first;
                    ++even;
                }
                else
                {
                    ++dict[nums[i]].second;
                    ++odd;
                }
            }

            int ans;

            {
                int even_tmp = even;
                int odd_tmp = odd;

                int even_max = 0;
                int first;
                for (auto& kv : dict)
                {
                    if (kv.second.first > even_max)
                    {
                        even_max = kv.second.first;
                        first = kv.first;
                    }
                }
                even_tmp -= even_max;

                int odd_max = 0;
                for (auto& kv : dict)
                {
                    if (kv.first != first && kv.second.second > odd_max)
                    {
                        odd_max = kv.second.second;
                    }
                }
                odd_tmp -= odd_max;

                ans = odd_tmp + even_tmp;
            }

            {
                int even_tmp = even;
                int odd_tmp = odd;

                int odd_max = 0;
                int second;
                for (auto& kv : dict)
                {
                    if (kv.second.second > odd_max)
                    {
                        odd_max = kv.second.second;
                        second = kv.first;
                    }
                }
                odd_tmp -= odd_max;


                int even_max = 0;
                for (auto& kv : dict)
                {
                    if (kv.first != second && kv.second.first > even_max)
                    {
                        even_max = kv.second.first;
                    }
                }
                even_tmp -= even_max;

                if (odd_tmp + even_tmp < ans)
                {
                    ans = odd_tmp + even_tmp;
                }
            }

            return ans;
        }
    };
} // namespace p_2170_weekly_contest

/*
# Problem:
https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

## HINT:
* Find the max count values in even and odd positions.
* These two value can not be the same.
* Compare between "find even then odd" and "find odd and even", choose the small one.

## Algorithm:

## Time Complexity:
O(n)

## Space Complexity:
O(n)
*/
