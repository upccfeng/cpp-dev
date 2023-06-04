#include <vector>

namespace p_curated_array_33_search_in_rotated_sorted_array
{
    class Solution
    {
        int find_min_index(std::vector<int>& nums)
        {
            int left = 0;
            int right = nums.size() - 1;

            if (nums.size() == 1 || nums[left] < nums[right])
            {
                return left;
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

            return left + 1;
        }
    public:
        int search(std::vector<int>& nums, int target)
        {
            int shift = find_min_index(nums);

            int left = 0;
            int right = nums.size() - 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;

                int shift_mid = mid + shift;
                if (shift_mid >= nums.size())
                {
                    shift_mid = shift_mid - nums.size();
                }

                if (nums[shift_mid] == target)
                {
                    return shift_mid;
                }
                else if (nums[shift_mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return -1;
        }
    };
} // namespace p_curated_array_33_search_in_rotated_sorted_array

/*
# Problem:
https://leetcode.com/problems/search-in-rotated-sorted-array/

## HINT:
* Find the times of rotation as shift in BigO(log(n)).
* Use Binary Search with shift.
* The 1 in "right = mid - 1" and "left = mid + 1" is neccessary to avoid infinite loop. Because the mid is already checked.

## Algorithm:

shift = find_min_index(nums)
left = 0
right = nums.size() - 1

while (left < right):
    mid = (left + right) / 2

    mid_shift = mid + shift

    if (mid_shift >= nums.size())
        mid_shift -= nums.size()

    if (nums[mid_shift] == target):
        return mid_shift
    else if (nums[mid_shift] > target):
        right = mid - 1
    else:
        left = mid + 1

return -1

## Time Complexity:
BigO(2 * log(n)) -> BigO(log(n))

## Space Complexity:
BigO(1)
*/