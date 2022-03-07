#include <vector>
#include <algorithm>

namespace p_75
{
    class Solution
    {
    public:
        void sortColors(std::vector<int>& nums)
        {
            int zero_pos = 0;
            int two_pos = nums.size() - 1;

            int taking = 0;

            while (taking <= two_pos)
            {
                if (nums[taking] == 0)
                {
                    std::swap(nums[zero_pos], nums[taking]);
                    zero_pos++;
                    taking++;
                }
                else if (nums[taking] == 1)
                {
                    taking++;
                }
                else
                {
                    std::swap(nums[two_pos], nums[taking]);
                    two_pos--;
                }
            }
        }

        void sortColorsTwoPath(std::vector<int>& nums)
        {
            int r = 0, w = 0, b = 0;

            for (auto n : nums)
            {
                if (n == 0)
                {
                    r++;
                }
                else if (n == 1)
                {
                    w++;
                }
                else
                {
                    b++;
                }
            }

            for (auto& n : nums)
            {
                if (r > 0)
                {
                    n = 0;
                    r--;
                }
                else if (w > 0)
                {
                    n = 1;
                    w--;
                }
                else
                {
                    n = 2;
                    b--;
                }
            }
        }
    };
} // namespace p_75

/*
# Problem:
https://leetcode.com/problems/sort-colors/

## HINT:
* Solution-1: Use three variable to count the apearing counts in first path, and replace the value of nums in second path.
* Solution-2: Use left and right boundary. Put 0 to the left and move left. Put 2 to the right and move right.
*             The reason we move TTT in the 0 case but not in the 1 is we start from pos-0, so there is no 2 case.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/