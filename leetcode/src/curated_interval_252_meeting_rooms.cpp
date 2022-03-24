#include "assert.h"
#include <vector>
#include <map>

namespace p_curated_interval_252_meeting_rooms
{
    class Solution
    {
    public:
        bool canAttendMeetings(std::vector<std::vector<int>>& intervals)
        {
            std::map<int, std::vector<bool>> time_oper;

            for (auto& inter : intervals)
            {
                time_oper[inter[0]].push_back(true);
                time_oper[inter[1]].push_back(false);
            }


            int cnt = 0;
            for (auto& kv : time_oper)
            {
                for (bool op : kv.second)
                {
                    if (op)
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt--;
                    }
                }

                if (cnt > 1)
                {
                    return false;
                }
            }

            return true;
        }
    };
} // namespace p_curated_interval_252_meeting_rooms

/*
# Problem:
https://leetcode.com/problems/meeting-rooms/

## HINT:
* Record the entering and exiting event.
* For each event, count the current number of meetings.
* Solution-2: Just sort by start time and check that is "i-1"'s end is greater than "i"'s start.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(n)
Solution-2: BigO(Sort)
*/