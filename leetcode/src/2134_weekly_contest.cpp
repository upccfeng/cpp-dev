#include <vector>

namespace p_2134_weekly_contest
{
    class Solution
    {
    public:
        int minSwaps(std::vector<int>& nums)
        {
            int count = 0;

            for (int e : nums)
            {
                if (e == 1)
                    ++count;
            }

            if (count == 0)
            {
                return 0;
            }

            int len = nums.size() + count - 1;
            int min = INT_MAX;
            int start = 0;
            int end = 0;
            int zeros = 0;
            while (end < len)
            {
                int new_end = end;
                if (new_end >= nums.size())
                {
                    new_end -= nums.size();
                }

                if (nums[new_end] == 0)
                {
                    zeros++;
                }

                if (end - start + 1 > count) {
                    if (nums[start] == 0)
                    {
                        zeros--;
                    }

                    start++;
                }

                if (end - start + 1 == count)
                {
                    min = zeros < min ? zeros : min;
                }
                end++;
            }

            return min;
        }
    };
} // namespace p_2134_weekly_contest

/*
# Problem:
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

## HINT:
* Caculate the number of one.
* Use sliding windows to find the minimum times.
* Don't forget the cycle case.

## Algorithm:

## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(n^2)
*/
