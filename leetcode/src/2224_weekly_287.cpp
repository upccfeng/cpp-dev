#include <string>

namespace p_2224_weekly_287
{
    class Solution {

        std::pair<int, int> getTime(std::string& s)
        {
            int hours = 0;
            int mins = 0;

            hours = (s[0] - '0') * 10 + s[1] - '0';

            mins = (s[3] - '0') * 10 + s[4] - '0';

            return { hours, mins };
        }

    public:
        int convertTime(std::string current, std::string correct)
        {
            std::pair<int, int> now_time = getTime(current);
            std::pair<int, int> target = getTime(correct);

            int cnt = 0;

            int hours = target.first - now_time.first;
            int mins = target.second - now_time.second;

            if (mins < 0)
            {
                hours--;
                mins += 60;
            }

            cnt += hours;

            cnt += mins / 15;
            mins = mins % 15;

            cnt += mins / 5;
            mins = mins % 5;

            cnt += mins;

            return cnt;
        }
    };
} // namespace p_2224_weekly_287

/*
# Problem:
https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/

## HINT:
* Calcuate the diff of hours and mins.
* Be aware of negative mins case.

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(1)
*/