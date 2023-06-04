#include <vector>
#include <unordered_map>

namespace p_curated_array_1_twosum
{
    class Solution
    {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, int> value_idx;
            for (int i = 0; i < nums.size(); ++i)
            {
                auto it = value_idx.find(target - nums[i]);
                if (it == value_idx.end())
                {
                    value_idx.emplace(nums[i], i);
                }
                else
                {
                    return { it->second, i };
                }
            }
            return { -1, -1 };
        }
    };
} // namespace p_curated_array_1_twosum

/*
# Problem:
https://leetcode.com/problems/two-sum/

## HINT:
HashMap

## Algorithm:

```python
value_idx = {}
for i in range(i, nums.size()):
    idx = value_idx.get(target - nums[i])
    if (idx):
        return [idx, i]
    else:
        value_idx[nums[i]] = i

return [-1, -1]
```

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/