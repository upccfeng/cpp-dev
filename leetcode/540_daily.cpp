#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include <vector>

namespace p540
{
    class Solution
    {
        //int findFromOdd(std::vector<int>& nums, size_t left, size_t right)
        //{
        //    size_t size = right - left + 1;
        //    if (size == 1)
        //    {
        //        return nums[left];
        //    }

        //    int middle = left + size / 2;
        //    if (nums[middle] != nums[middle - 1] && nums[middle] != nums[middle + 1])
        //    {
        //        return nums[middle];
        //    }
        //    else if (nums[middle] == nums[middle + 1])
        //    {
        //        if ((size / 2) % 2 == 0)
        //        {
        //            return findFromOdd(nums, middle + 2, right);
        //        }
        //        else
        //        {
        //            return findFromOdd(nums, left, middle - 1);
        //        }
        //    }
        //    else // (nums[middle] == nums[middle - 1])
        //    {
        //        if ((size / 2) % 2 == 0)
        //        {
        //            return findFromOdd(nums, left, middle - 2);
        //        }
        //        else
        //        {
        //            return findFromOdd(nums, middle + 1, right);
        //        }
        //    }
        //}

    public:
        int singleNonDuplicate(std::vector<int>& nums)
        {
            // (Original Recursive)return findFromOdd(nums, 0, nums.size() - 1);

            if (nums.size() == 1)
                return nums[0];

            size_t start = 0, end = nums.size() - 1;
            size_t m_distance, middle_pos;

            while (start != end)
            {
                m_distance = (end - start) / 2;
                middle_pos = start + m_distance;

                if (nums[middle_pos] != nums[middle_pos + 1] && nums[middle_pos] != nums[middle_pos - 1])
                {
                    return nums[middle_pos];
                }
                else if (nums[middle_pos] == nums[middle_pos + 1])
                {
                    if (m_distance % 2 != 0)
                    {
                        end = middle_pos - 1;
                    }
                    else
                    {
                        start = middle_pos + 2;
                    }
                }
                else // (nums[middle_pos] == nums[middle_pos - 1])
                {
                    if (m_distance % 2 != 0)
                    {
                        start = middle_pos + 1;
                    }
                    else
                    {
                        end = middle_pos - 2;
                    }
                }
            }

            return nums[start];
        }
    };
} // namespace p540

/*
# Problem:
https://leetcode.com/problems/single-element-in-a-sorted-array/

## HINT:
Divide and conquer, and find the ODD numbers side.
Function recursive will be slow.

## Algorithm:

```
if size == 1: -> return

Check the middle one:
    if (not equal to both of right and left) -> this is the answer, return
    else -> find the ODD side.
```

## Time Complexity:
BigO(log(n))

## Space Complexity:
BigO(1)
*/