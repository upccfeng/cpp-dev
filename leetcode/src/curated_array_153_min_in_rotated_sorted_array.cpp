#include <vector>

namespace p_curated_array_153_min_in_rotated_sorted_array
{
    class Solution
    {
    public:
        int findMin(std::vector<int>& nums)
        {
            int left = 0;
            int right = nums.size() - 1;

            if (nums.size() == 1 || nums[left] < nums[right])
            {
                return nums[left];
            }

            while (left < right)
            {
                int mid = (left + right) / 2;

                if (nums[mid] > nums[left])
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }

            return nums[left + 1];
        }
    };
} // namespace p_curated_array_153_min_in_rotated_sorted_array

/*
# Problem:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

## HINT:
* Use binary search.
* Cases
  * nums[0] < nums[n-1]                 ----> no rotation
  * nums[mid] > nums[left]              ----> find in right hand side
  * nums[mid] < nums[left]              ----> find in left hand side
* in the loop, if left + 1 == right     ----> return nums[left + 1]

## Algorithm:

left = 0
right = nums.size() - 1

if (nums.size() == 1 || nums[left] < nums[right])
    return nums[left]

while (left < right):
    mid = (left + right) / 2

    if (nums[mid] > nums[left])
        left = mid
    else
        right = mid

return nums[left + 1]

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/