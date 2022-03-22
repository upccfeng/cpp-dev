#include "assert.h"
#include <algorithm>
#include <unordered_map>

namespace p_454
{
    class Solution
    {
    public:
        int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
        {
            std::sort(nums1.begin(), nums1.begin());
            std::sort(nums2.begin(), nums2.begin());
            std::sort(nums3.begin(), nums3.begin());
            std::sort(nums4.begin(), nums4.begin());

            std::unordered_map<int, int> hash_map_12; // sum - cnt of the sum
            std::unordered_map<int, int> hash_map_34; // sum - cnt of the sum

            for (int i = 0; i < nums1.size(); i++)
            {
                for (int j = 0; j < nums2.size(); j++)
                {
                    int sum = nums1[i] + nums2[j];
                    hash_map_12[sum]++;
                }
            }

            for (int i = 0; i < nums3.size(); i++)
            {
                for (int j = 0; j < nums4.size(); j++)
                {
                    int sum = nums3[i] + nums4[j];
                    hash_map_34[sum]++;
                }
            }

            int ret = 0;
            for (auto& kv12 : hash_map_12)
            {
                int target = -kv12.first;

                if (hash_map_34.find(target) != hash_map_34.end())
                {
                    ret += kv12.second * hash_map_34[target];
                }
            }

            return ret;
        }
    };
} // namespace p_454

/*
# Problem:
https://leetcode.com/problems/4sum-ii/

## HINT:
* Make two hash_map for 1-2 and 3-4.
* Key is the sum, value is the count of the sum
* For each kv in hash_map_12, find -kv.sum in hash_map_34. The number of tuples will be cnt12 * cnt34.

## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(n^2)
*/