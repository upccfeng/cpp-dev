#include <vector>

namespace p_88
{
    class Solution
    {
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
        {
            int p1 = m - 1;
            int p2 = n - 1;
            for (int i = nums1.size() - 1; i >= 0; i--)
            {
                if (p1 < 0)
                {
                    nums1[i] = nums2[p2];
                    p2--;
                }
                else if (p2 < 0)
                {
                    break;
                }
                else
                {
                    if (nums1[p1] > nums2[p2])
                    {
                        nums1[i] = nums1[p1];
                        p1--;
                    }
                    else
                    {
                        nums1[i] = nums2[p2];
                        p2--;
                    }
                }
            }
        }
    };
} // namespace p_88

/*
# Problem:
https://leetcode.com/problems/merge-sorted-array/

## HINT:
* Process from the end to avoid overwrite.

## Time Complexity:
BigO(m + n)

## Space Complexity:
BigO(1)
*/