#include <vector>
#include <algorithm>

namespace p_2187_weekly_contest_282
{
    class Solution
    {
    public:
        long long minimumTime(std::vector<int>& time, int totalTrips)
        {
            std::sort(time.begin(), time.end());

            long long max = (long long)totalTrips * (long long)time[0];
            long long left = 0;
            long long right = max;
            while (left < right)
            {
                long long current = (left + right) / 2;
                long long trips = 0;
                for (auto t : time)
                {
                    trips += current / (long long)t;
                }

                if (trips >= totalTrips)
                {
                    right = current;
                }
                else
                {
                    left = current + 1;
                }
            }

            return left;
        }
    };
} // namespace p_2187_weekly_contest_282

/*
# Problem:
https://leetcode.com/problems/minimum-time-to-complete-trips/

## HINT:
* Sort the times to get the min and max.
* For each time, calculate the trips for all numbers until the MAX(totalTrips * MinTrip).
* Use binaray search to approach the answer.
* P.S. If the trips is greater than totalTrips, need to find is there smaller case.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(1)
*/