#include <vector>
#include <unordered_map>

////////////////////////////////////////////////////////

namespace p_curated_array_217_containduplicate
{
    class Solution
    {
    public:
        bool containsDuplicate(std::vector<int>& nums)
        {
            std::unordered_map<int, int> m;
            for (auto e : nums)
            {
                m[e] += 1;
                if (m[e] > 1) return true;
            }

            return false;
        }
    };
} // namespace p_curated_array_217_containduplicate

/*
# Problem:
https://leetcode.com/problems/contains-duplicate/

## HINT:
Use the unordered_map to speed up.

## Algorithm:

map = {}
for e in nums:
    if(map.get(e)):
        return true
    else:
        map[e] = 1

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/