#include "assert.h"
#include <vector>

namespace p_315
{
    class Solution {

        void mergeWithCount(std::vector<std::pair<int, int>>& nums_pos, int left_l, int left_r, int right_l, int right_r, std::vector<int>& counts)
        {
            assert(left_r + 1 == right_l);

            std::vector<std::pair<int, int>> temp(right_r - left_l + 1);

            int left_iter = left_l;
            int right_iter = right_l;
            int temp_iter = 0;

            int count = 0;
            while (left_iter <= left_r && right_iter <= right_r)
            {
                const auto& l = nums_pos[left_iter];
                const auto& r = nums_pos[right_iter];

                if (r.first < l.first)
                {
                    count++;                            // Putting a value in the second part to the front means the number of smaller value increase by 1.

                    temp[temp_iter] = r;
                    temp_iter++;
                    right_iter++;
                }
                else
                {
                    counts[l.second] += count;          // While putting the value in the first part to the front, the count of smaller values for the value's position should increase by count.
                    temp[temp_iter] = l;
                    temp_iter++;
                    left_iter++;
                }
            }

            while (right_iter <= right_r)
            {
                const auto& r = nums_pos[right_iter];

                count++;

                temp[temp_iter] = r;
                temp_iter++;
                right_iter++;
            }

            while (left_iter <= left_r)
            {
                const auto& l = nums_pos[left_iter];

                counts[l.second] += count;
                temp[temp_iter] = l;
                temp_iter++;
                left_iter++;
            }

            temp_iter = 0;
            for (int i = left_l; i <= right_r; i++)
            {
                nums_pos[i] = std::move(temp[temp_iter]);
                temp_iter++;
            }
        }

        void mergeSortWithCount(std::vector<std::pair<int, int>>& nums_pos, int left, int right, std::vector<int>& counts)
        {
            if (left == right)
            {
                return;
            }
            int mid = (left + right) / 2;

            mergeSortWithCount(nums_pos, left, mid, counts);
            mergeSortWithCount(nums_pos, mid + 1, right, counts);
            mergeWithCount(nums_pos, left, mid, mid + 1, right, counts);
        }

    public:
        std::vector<int> countSmaller(std::vector<int>& nums)
        {
            std::vector<std::pair<int, int>> nums_pos(nums.size());

            for (int i = 0; i < nums.size(); i++)
            {
                nums_pos[i] = { nums[i], i };
            }

            std::vector<int> counts(nums.size(), 0);

            mergeSortWithCount(nums_pos, 0, nums_pos.size() - 1, counts); // While the position is changed during merge sort, the counts of smaller value of each position should be updated.

            return counts;
        }
    };
} // namespace p_315

/*
# Problem:
https://leetcode.com/problems/count-of-smaller-numbers-after-self/

## HINT:
* Use mergeSort, and udpate the counts of each position.
* While merging two array, putting a value from second array means the count of smaller values for first array increase by 1.
*                          putting a value from first array needs to increase the count of smaller values for the position by previous accumulated value.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
*/