#include "assert.h"
#include <vector>
#include <deque>

namespace p_239
{

    class Solution
    {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
        {
            std::deque<int> deque;

            std::vector<int> ans;

            int i = 0;
            for (i; i < k; i++)
            {
                while (!deque.empty() && nums[deque.back()] < nums[i])
                {
                    deque.pop_back();
                }

                deque.push_back(i);
            }

            ans.push_back(nums[deque.front()]);

            for (i; i < nums.size(); i++)
            {
                while (!deque.empty() && nums[deque.back()] < nums[i])
                {
                    deque.pop_back();
                }

                deque.push_back(i);

                while (!deque.empty() && deque.front() < i - k + 1)
                {
                    deque.pop_front();
                }

                ans.push_back(nums[deque.front()]);
            }

            return ans;
        }
    };
} // namespace p_239

/*
# Problem:
https://leetcode.com/problems/sliding-window-maximum/

## HINT:
* Use deque.
* Keep the left of deque always be the biggest value which is still in sliding window.
* Pop all the smaller value at back while inserting a value.
* Pop all out of range value at front after moving the sliding window.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/