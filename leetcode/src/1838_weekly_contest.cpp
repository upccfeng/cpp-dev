#include <vector>
#include <algorithm>
using namespace std;

namespace p1838_weekly_contest
{
    class Solution
    {
    public:
        int maxFrequency(vector<int>& nums, int k)
        {
            sort(nums.begin(), nums.end());

            long res = 0;
            long left = 0;
            long right = 0;
            long sum = 0;

            while (right < nums.size())
            {
                if (right > 0)
                    sum += (right - left)*(nums[right] - nums[right - 1]);

                if (sum <= k)
                {
                    res = max(right - left + 1, res);
                }
                else
                {
                    sum -= nums[right] - nums[left];
                    ++left;
                }
                ++right;
            }

            return res;
        }
    };
} // namespace p1838_weekly_contest

/*
# Problem:

https://leetcode.com/problems/frequency-of-the-most-frequent-element/

## HINT:

Using windows-slide concept instead.
Need to check overflow case

## Algorithm:

```
def maxFrequency(nums, k):
{
    sort(nums.begin(), nums.end())

    res = 0
    left = 0
    right = 0
    sum = 0

    while right < nums.size():
        if right > 0:
            sum += (right - left)*(nums[right] - nums[right - 1])

        if sum <= k:
            res = max(right - left + 1, res)
        else
            sum -= nums[right] - nums[left]
            left += 1

        right += 1
    }

    return res
}
```

## Time Complexity:
O(n * log(n)) -> sort
if sorted array, O(n)

## Space Complexity:
O(1)
*/