#include <vector>
#include <stack>

namespace p_84
{
    class Solution
    {
    public:
        int largestRectangleAreaFindBoundary(std::vector<int>& heights)
        {
            std::vector<int> right_pos(heights.size());
            for (int i = 0; i < heights.size(); i++)
            {
                int pos = i + 1;
                for (pos; pos < heights.size(); pos++)
                {
                    if (heights[pos] < heights[i])
                    {
                        break;
                    }
                }

                pos--;
                right_pos[i] = pos;
            }

            std::vector<int> left_pos(heights.size());
            for (int i = heights.size() - 1; i >= 0; i--)
            {
                int pos = i - 1;
                for (pos; pos >= 0; pos--)
                {
                    if (heights[pos] < heights[i])
                    {
                        break;
                    }
                }

                pos++;
                left_pos[i] = pos;
            }

            int max = 0;

            for (int i = 0; i < heights.size(); i++)
            {
                int val = heights[i] * (right_pos[i] - left_pos[i] + 1);

                max = std::max(max, val);
            }

            return max;
        }

        int largestRectangleAreaStack(std::vector<int>& heights)
        {
            std::stack<std::pair<int, int>> s_pos_value;

            int max = 0;

            for (int i = 0; i < heights.size(); i++)
            {
                if (s_pos_value.empty())
                {
                    s_pos_value.push({ i, heights[i] });
                }
                else
                {
                    int last_pos = i;
                    while (!s_pos_value.empty() && s_pos_value.top().second > heights[i])
                    {
                        int height = s_pos_value.top().second;
                        last_pos = s_pos_value.top().first;
                        int width = i - last_pos;

                        max = std::max(max, height * width);

                        s_pos_value.pop();
                    }

                    s_pos_value.push({ last_pos, heights[i] });
                }
            }

            while (!s_pos_value.empty())
            {
                auto& top = s_pos_value.top();
                int height = top.second;
                int width = heights.size() - top.first;

                max = std::max(max, height * width);

                s_pos_value.pop();
            }

            return max;
        }

        int largestRectangleArea(std::vector<int>& heights)
        {
            return largestRectangleAreaStack(heights);
        }
    };
} // namespace p_84

/*
# Problem:
https://leetcode.com/problems/largest-rectangle-in-histogram/

## HINT:
* Solution-1: Find the left-first-less and right-first-less in BigO(n*n), and calculate the area in BigO(n)
* Solution-2: Use stack, calculate the area once the pushing element is less than top of stack. (Because it will become a barrier)
*             The pushing position should extend to the farest popped out element's position.

## Time Complexity:
Solution-1: BigO(n*n)
Solution-2: BigO(n)

## Space Complexity:
BigO(n)
*/