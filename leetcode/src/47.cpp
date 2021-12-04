#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace p47
{
    class Solution
    {
        void _permuteUnique(vector<vector<int>>& ret, vector<int> current, map<int, int>& nums_map, int nums_len)
        {
            if (current.size() == nums_len)
            {
                ret.emplace_back(current);
            }
            else
            {
                for (auto& e : nums_map)
                {
                    if (e.second > 0)
                    {
                        vector<int> t = current;
                        t.emplace_back(e.first);

                        e.second--;
                        _permuteUnique(ret, t, nums_map, nums_len);
                        e.second++;
                    }
                }
            }
        }

    public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            map<int, int> nums_map;

            for (const auto& e : nums)
            {
                if (nums_map.find(e) != nums_map.end())
                {
                    nums_map[e]++;
                }
                else
                {
                    nums_map[e] = 1;
                }
            }

            vector<vector<int>> result;

            _permuteUnique(result, {}, nums_map, nums.size());

            return result;
        }
    };
} // namespace p47

/*
# Problem:

https://leetcode.com/problems/permutations-ii/

## HINT:

Method 1: use "set" concept. -> depends on implementation of set.

Method 2:  count the numbers of echo elements. -> more copy, but faster.

## Algorithm:

```
def _permuteUnique(ret, current, nums_map, nums_len):
    if current.size() == nums_len:
        ret.append(current)
    else:
        for k, v in nums_map:
            if v > 0:
                t = current
                t.append(k)

                nums_map[k]--
                _permuteUnique(ret, t, nums_map, nums_len)
                nums_map[k]++

def permuteUnique(nums):
    nums_map = {};

    for e in nums:
        if e not in nums_map:
            nums_map[e] += 1
        else:
            nums_map[e] = 1

    result = [];

    _permuteUnique(result, [], nums_map, nums.size())

    return result

```

## Time Complexity:
O(n!)
best case: O(n)

## Space Complexity:
O(n!)
*/