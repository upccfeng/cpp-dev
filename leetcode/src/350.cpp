#include "assert.h"
#include <vector>
#include <unordered_map>

namespace p_350
{
    class Solution
    {
    public:
        std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {

            std::unordered_map<int, int> value_cnt;

            for (int i = 0; i < nums1.size(); i++)
            {
                value_cnt[nums1[i]]++;
            }

            std::vector<int> ret;
            for (int i = 0; i < nums2.size(); i++)
            {
                if (value_cnt.find(nums2[i]) != value_cnt.end() && value_cnt[nums2[i]] > 0)
                {
                    ret.push_back(nums2[i]);
                    value_cnt[nums2[i]]--;
                }
            }

            return ret;
        }
    };
} // namespace p_350

/*
# Problem:
https://leetcode.com/problems/intersection-of-two-arrays-ii/

## HINT:
* Use hash map

## Time Complexity:
BigO(m + n)

## Space Complexity:
BigO(m or n)
*/