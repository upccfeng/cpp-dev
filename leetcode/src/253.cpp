#include "assert.h"
#include <vector>
#include <set>
#include <algorithm>

namespace p_253
{
    class Solution
    {
    public:
        int minMeetingRooms(std::vector<std::vector<int>>& intervals)
        {
            std::vector<std::pair<int, int>> events;

            for (int i = 0; i < intervals.size(); i++)
            {
                auto& inter = intervals[i];

                events.push_back({ i, inter[0] });
                events.push_back({ i, -inter[1] });
            }

            std::sort(events.begin(), events.end(), [](auto& lhs, auto& rhs) {
                if (std::abs(lhs.second) == std::abs(rhs.second))
                {
                    if (lhs.second < 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                return std::abs(lhs.second) < std::abs(rhs.second);
                });


            std::set<int> used;

            int ret = 0;
            for (auto& e : events)
            {
                if (e.second >= 0)
                {
                    used.insert(e.first);
                }
                else
                {
                    used.erase(e.first);
                }

                if (used.size() > ret)
                {
                    ret = used.size();
                }
            }

            return ret;
        }
    };
} // namespace p_253

/*
# Problem:
https://leetcode.com/problems/meeting-rooms-ii/

## HINT:
* For each entering and exiting, increase the number of rooms.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
*/