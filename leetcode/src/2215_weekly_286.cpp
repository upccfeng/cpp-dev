#include <vector>
#include <unordered_set>

namespace p_2215_weekly_286
{
    class Solution
    {
    public:
        std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
        {
            std::unordered_set<int> nums1_set;
            std::unordered_set<int> nums2_set;

            for (int i = 0; i < nums1.size(); i++)
            {
                nums1_set.insert(nums1[i]);
            }

            for (int i = 0; i < nums2.size(); i++)
            {
                nums2_set.insert(nums2[i]);
            }

            std::vector<int> v1;
            std::vector<int> v2;

            for (int i = 0; i < nums1.size(); i++)
            {
                if (nums1_set.find(nums1[i]) != nums1_set.end() && nums2_set.find(nums1[i]) == nums2_set.end())
                {
                    v1.push_back(nums1[i]);
                    nums1_set.erase(nums1[i]);
                }
            }

            for (int i = 0; i < nums2.size(); i++)
            {
                if (nums2_set.find(nums2[i]) != nums2_set.end() && nums1_set.find(nums2[i]) == nums1_set.end())
                {
                    v2.push_back(nums2[i]);
                    nums2_set.erase(nums2[i]);
                }
            }

            return { v1, v2 };

        }
    };
} // namespace p_2215_weekly_286

/*
# Problem:
https://leetcode.com/problems/find-the-difference-of-two-arrays/

## HINT:
* Use Hash set.
* Delete the added value from set.

## Time Complexity:
BigO(n + m)

## Space Complexity:
BigO(n + m)
*/