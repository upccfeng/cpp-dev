#include <vector>
#include <map>

namespace p416
{
    class Solution
    {
    private:
        std::vector<std::vector<int>> cache;
        bool _canPartition(std::vector<int>& nums, int pos, int remained)
        {
            if (remained == 0)
                return true;
            if (pos < 0)
                return false;

            if (cache[pos][remained] != -1)
                return cache[pos][remained];

            if (nums[pos] <= remained)
            {
                cache[pos][remained] = _canPartition(nums, pos - 1, remained - nums[pos]) || _canPartition(nums, pos - 1, remained);
                return cache[pos][remained];
            }
            else
            {
                cache[pos][remained] = _canPartition(nums, pos - 1, remained);
                return cache[pos][remained];
            }
        }
    public:
        bool canPartition(std::vector<int>& nums)
        {
            int sum = 0;
            for (auto e : nums)
                sum += e;

            if (sum & 1)
                return false;

            cache.resize(nums.size(), std::vector<int>(sum / 2 + 1, -1));

            return _canPartition(nums, nums.size() - 1, sum / 2);
        }
    };
} // namespace p416

/*
# Problem:
https://leetcode.com/problems/partition-equal-subset-sum/

## HINT:
Odd sum must be false.
Select the items which are sum as ALL/2, which ALL is even.
Cache the possibility of position and the remaining target.

## Algorithm:

```pseudo code

def isPartionable(nums, pos, remained, cache):
    if remained == 0:
        return true
    if pos < 0:
        return false

    if cache[pos][remained] != -1:
        return cache[pos][remained]

    if (nums[pos] <= remained):
        cache[pos][remained] = isPartionable(nums, pos - 1, remained - nums[pos]) || isPartionable(nums, pos - 1, remained);
        return cache[pos][remained]
    else:
        cache[pos][remained] = isPartionable(nums, pos - 1, remained);
        return cache[pos][remained];


if sum of nums are odd:
    return false;

create cache[sum.size][sum/2] and each element is -1

return isPartionable(nums, nums.size()-1, sum/2, cache)
```

## Time Complexity:
BigO(n^2) ??

## Space Complexity:
BigO(n * sum/2)
*/