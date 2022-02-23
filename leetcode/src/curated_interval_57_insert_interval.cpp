#include <vector>

namespace p_curated_interval_57_insert_interval
{
    class Solution
    {
        int get_interval(std::vector<std::vector<int>>& intervals, int target)
        {
            for (int i = 0; i < intervals.size(); ++i)
            {
                if (target >= intervals[i][0] && target <= intervals[i][1])
                {
                    return i;
                }

                // TODO: Skip the impossible case.
            }

            return -1;
        }

        int get_interval_after_terget(std::vector<std::vector<int>>& intervals, int target)
        {
            for (int i = 0; i < intervals.size(); ++i)
            {
                if (target < intervals[i][0])
                {
                    return i;
                }
            }

            return intervals.size();
        }

    public:
        std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
        {
            std::vector<std::vector<int>> ans;

            int s_interval = get_interval(intervals, newInterval[0]);
            int e_interval = get_interval(intervals, newInterval[1]);

            if (s_interval != -1)
            {
                if (e_interval != -1)
                {
                    // append the intervals before s_interval
                    for (int i = 0; i < s_interval; ++i)
                    {
                        ans.emplace_back(intervals[i]);
                    }

                    // append new interval
                    ans.emplace_back(std::vector<int>({ intervals[s_interval][0], intervals[e_interval][1] }));

                    // append rest of intevals
                    for (int i = e_interval + 1; i < intervals.size(); i++)
                    {
                        ans.emplace_back(intervals[i]);
                    }
                }
                else
                {
                    int e_interval = get_interval_after_terget(intervals, newInterval[1]);

                    // append the intervals before s_interval
                    for (int i = 0; i < s_interval; ++i)
                    {
                        ans.emplace_back(intervals[i]);
                    }

                    // append new interval
                    ans.emplace_back(std::vector<int>({ intervals[s_interval][0], newInterval[1] }));

                    // append rest of intevals
                    for (int i = e_interval; i < intervals.size(); i++)
                    {
                        ans.emplace_back(intervals[i]);
                    }
                }
            }
            else
            {
                if (e_interval != -1)
                {
                    int s_interval = get_interval_after_terget(intervals, newInterval[0]);

                    // append the intervals before s_interval
                    for (int i = 0; i < s_interval; ++i)
                    {
                        ans.emplace_back(intervals[i]);
                    }

                    // append new interval
                    ans.emplace_back(std::vector<int>({ newInterval[0], intervals[e_interval][1] }));

                    // append rest of intevals
                    for (int i = e_interval + 1; i < intervals.size(); i++)
                    {
                        ans.emplace_back(intervals[i]);
                    }
                }
                else
                {
                    int s_interval = get_interval_after_terget(intervals, newInterval[0]);
                    int e_interval = get_interval_after_terget(intervals, newInterval[1]);

                    // append the intervals before s_interval
                    for (int i = 0; i < s_interval; ++i)
                    {
                        ans.emplace_back(intervals[i]);
                    }

                    // append new interval
                    ans.emplace_back(std::vector<int>({ newInterval[0],  newInterval[1] }));

                    // append rest of intevals
                    for (int i = e_interval; i < intervals.size(); i++)
                    {
                        ans.emplace_back(intervals[i]);
                    }
                }
            }

            return ans;
        }
    };
} // namespace p_curated_interval_57_insert_interval

/*
# Problem:
https://leetcode.com/problems/insert-interval/

## HINT:
* Total 4 cases: (if newInterval[0] in any range(call s_range)?) * (if newInterval[1] in any range(call e_range)?)
* YY: ans = for each range in (0 -> s_range) + [s_range[0], e_range[1]] + for each range in (e_range + 1 -> end of intervals)
* YN: e_range = get_interval_before_target(newInterval[1]), ans = for each range in (0 -> s_range) + [s_range[0], newInterval[1]] + for each range in (e_range + 1 -> end of intervals)
* NY: s_range = get_interval_before_target(newInterval[0]), ans = for each range in (0 -> s_range) + [newInterval[0], e_range[1]] + for each range in (e_range + 1 -> end of intervals)
* NN:
*     e_range = get_interval_before_target(newInterval[1])
*     s_range = get_interval_before_target(newInterval[0])
*     ans = for each range in (0 -> s_range) + [newInterval[0], newInterval[1]] + for each range in (e_range + 1 -> end of intervals)

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/