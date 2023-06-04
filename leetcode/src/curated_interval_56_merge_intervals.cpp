#include <vector>
#include <algorithm>

namespace p_curated_interval_56_merge_intervals
{
    class Solution
    {
        void merge(std::vector<std::vector<int>>& ans, const std::vector<int>& taking)
        {
            auto& previous = ans.back();
            if (taking[0] > previous[1])
            {
                ans.emplace_back(taking);
            }
            else
            {
                if (taking[1] < previous[1])
                {
                    previous[1] = previous[1];
                }
                else
                {
                    previous[1] = taking[1];
                }

            }
        }

    public:
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
        {
            std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, auto const& rhs) {
                return lhs[0] < rhs[0];
                });

            std::vector<std::vector<int>> ans;

            for (int taking = 0; taking < intervals.size(); ++taking)
            {
                if (taking == 0)
                {
                    ans.emplace_back(intervals[taking]);
                }

                merge(ans, intervals[taking]);
            }

            return ans;
        }
    };
} // namespace p_curated_interval_56_merge_intervals

/*
# Problem:
https://leetcode.com/problems/merge-intervals/

## HINT:

* Sort the intervals by interval[0]
* Add the first interval into ans
* For each inteval from sencond to end, there are three cases while adding interval into ans.
*           First: The range of new interval is all in the range of ans.back. (means new_interval[1] <= ans.back[1])
*           Second: The range of new interval is overlap with the range of ans.back. (means new_interval[1] > ans.back[1])
*           Third: The range of new interval is out of the range of ans.back. (means new_interval[0] > ans.back[1])

## Algorithm

sort intervals by interval[0]

ans = []
for taking in intervals:
    if (taking == 0):
        ans.append(taking)

    merge(ans, taking, taking - 1)
        - overlap -> update ans.top
        - no overlap -> ans.append(taking)

return ans

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
*/