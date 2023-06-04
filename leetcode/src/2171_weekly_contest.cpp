#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>

namespace p_2171_weekly_contest
{
    class Solution {
    public:
        long long minimumRemoval(std::vector<int>& beans)
        {
            std::sort(beans.begin(), beans.end(), std::greater<int>());

            long long min = LLONG_MAX;

            long long total = 0;
            for (int i = 0; i < beans.size(); i++)
            {
                total += beans[i];
            }

            long long removed = total;
            long long saved = 0;
            for (int i = 0; i < beans.size(); ++i)
            {
                long long saved = (long long)beans[i] * (long long)(i + 1);
                long long removed = total - saved;

                min = std::min(min, removed);
            }

            return min;
        }
    };
} // namespace p_2171_weekly_contest

/*
# Problem:
https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

## HINT:
* Sort it in descending order.
* Caculate the total
* For each index in beans, the number of saved beans is beans[i] * (i + 1). p.s. The extra beans(i - 1, i - 2 , ... 0) greater than beans[i] should be removed.
* The number of removed beans is total - saved.
* Keep the minimum value of removed values.

## Algorithm:

## Time Complexity:
O(sort) + O(n)

## Space Complexity:
O(1)
*/