#include <vector>
#include <algorithm>

namespace p_curated_interval_435_non_overlapping_intervals
{
    class Solution
    {
        bool isOverlap(const std::vector<int>& pre, const std::vector<int>& cur)
        {
            return cur[0] < pre[1];
        }

        void update_if_smaller(std::vector<int>& pre, const std::vector<int>& cur)
        {
            // If overlap, choose the one which's seocnd is smaller to reduce the count of removing
            if (cur[1] < pre[1])
            {
                pre[0] = cur[0];
                pre[1] = cur[1];
            }
        }

    public:
        int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
        {
            if (intervals.size() == 0)
            {
                return 0;
            }

            std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
                return lhs[0] < rhs[0];
                });

            int cnt = 0;

            std::vector<int>& previous = intervals[0];

            for (int taking = 1; taking < intervals.size(); ++taking)
            {
                if (isOverlap(previous, intervals[taking]))
                {
                    update_if_smaller(previous, intervals[taking]);
                    ++cnt;
                }
                else
                {
                    previous = intervals[taking];
                }
            }

            return cnt;
        }
    };
} // namespace p_curated_interval_435_non_overlapping_intervals

/*
# Problem:
https://leetcode.com/problems/non-overlapping-intervals/

## HINT:
* Sort intervals by first
* Use the previous variable to store the most possible interval which could overlap.
* For each interval from 0+1 to end, if overlap, remove the one whose second value is bigger. -> If keep the bigger one, there will be more overlapping cases.

## Algorithm

if intevals is empty:
    return 0

sort intervals by first

cnt = 0
pre = interval[0]
for taking in intervals:
    if taking == 0:
        do nothing

    if overlap(ans, taking):
        update_if_smaller(ans, taking) // update ans wiht the smaller second one.
        ++cnt
    else:
        ans = taking

return cnt

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(1)
*/