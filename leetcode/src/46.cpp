#include <vector>
#include <algorithm>

using namespace std;

namespace p46
{
    class Solution
    {
        void _permute(vector<vector<int>>& result, int s_pos, vector<int>& nums)
        {
            if (s_pos == nums.size())
            {
                result.emplace_back(nums);
            }
            else
            {
                for (int i = s_pos; i < nums.size(); ++i)
                {
                    swap(nums[i], nums[s_pos]);
                    _permute(result, s_pos + 1, nums);
                    swap(nums[i], nums[s_pos]);
                }
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> res;

            _permute(res, 0, nums);

            return res;
        }
    };
} // namespace p46

/*
# Problem:

https://leetcode.com/problems/permutations/submissions/

## HINT:

There are nums.size() positions that you can place a data from nums.
Switch the data that you choose to start_position. Then, now you have nums.size()-1 positions to place the rest of data(start from start_position + 1).

## Algorithm:

```
def _permute(result,s_pos , nums):
    if s_pos == nums.size()
        result.emplace_back(nums)
    else
        for i in range(0, nums.size()):
            swap(nums[i], nums[s_pos])
            _permute(result, s_pos + 1, nums)
            swap(nums[i], nums[s_pos])

def permute(nums):
    res = [[]]
    _permute(res, 0, nums)
    return res
```

## Time Complexity:
O(n!)

## Space Complexity:
O(n!)
*/