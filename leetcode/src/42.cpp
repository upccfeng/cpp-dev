#include <vector>

namespace p_42
{
    class Solution
    {
    public:
        int trapNSpace(std::vector<int>& height)
        {
            int max = 0;

            std::vector<int> max_left(height.size());
            for (int i = 0; i < height.size(); i++)
            {
                max_left[i] = max;
                max = std::max(max, height[i]);
            }

            max = 0;
            std::vector<int> max_right(height.size());
            for (int i = height.size() - 1; i >= 0; i--)
            {
                max_right[i] = max;
                max = std::max(max, height[i]);
            }

            int ret = 0;
            for (int i = 0; i < height.size(); i++)
            {
                int val = std::min(max_left[i], max_right[i]) - height[i];

                if (val > 0)
                {
                    ret += val;
                }
            }

            return ret;
        }
        int trap1Space(std::vector<int>& height)
        {
            int left_pos = 0;
            int right_pos = height.size() - 1;

            int left_max = 0;
            int right_max = 0;

            int ret = 0;

            while (left_pos <= right_pos)
            {
                if (left_max <= right_max)
                {
                    int val = std::min(left_max, right_max) - height[left_pos];

                    if (val > 0)
                    {
                        ret += val;
                    }


                    left_max = std::max(left_max, height[left_pos]);
                    left_pos++;
                }
                else
                {
                    int val = std::min(left_max, right_max) - height[right_pos];

                    if (val > 0)
                    {
                        ret += val;
                    }


                    right_max = std::max(right_max, height[right_pos]);
                    right_pos--;
                }
            }

            return ret;
        }
        int trap(std::vector<int>& height)
        {
            return trap1Space(height);
        }
    };
} // namespace p_42

/*
# Problem:
https://leetcode.com/problems/trapping-rain-water/

## HINT:
* For each height, the trapped water will depend on the min of max-left and max-right
* Use BigO(n) space and BigO(n) time to find the max-left, max-right, and min of max-left, and max-right.
* For BigO(1) space solution, use left and right ptr, caculate the side which's max-value is smaller, and update the max and move the ptr.
* The meaning of calculate smaller side is the value of trapped water is limited by the max value of its side.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
BigO(1)
*/