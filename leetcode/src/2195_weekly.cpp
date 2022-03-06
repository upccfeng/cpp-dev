#include <vector>
#include <queue>

namespace p_2195_weekly
{
    class Solution
    {
    public:
        long long minimalKSum(std::vector<int>& nums, int k)
        {
            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

            for (auto n : nums)
            {
                pq.push(n);
            }

            long long ret = 0;
            int min = 1;
            while (k != 0)
            {
                if (!pq.empty())
                {
                    int pop = pq.top();

                    if (pop > min)
                    {
                        long long down_plus_top = (long long)min + pop - 1;
                        long long heigh = (long long)pop - 1 - min + 1;

                        if (k >= heigh)
                        {
                            ret += down_plus_top * heigh / 2;

                            min = pop + 1;
                            k -= heigh;
                            pq.pop();
                        }
                        else
                        {
                            down_plus_top = min + min + k - 1;

                            ret += down_plus_top * k / 2;

                            min = min + k;
                            k -= k;
                        }

                    }
                    else if (pop == min)
                    {
                        pq.pop();
                        min++;
                    }
                    else
                    {
                        pq.pop();
                    }
                }
                else
                {
                    break;
                }
            }

            if (k != 0)
            {
                long long down_plus_top = min + min + k - 1;
                ret += (long long)k * down_plus_top / 2;
            }

            return ret;
        }
    };
} // namespace p_2195_weekly

/*
# Problem:
https://leetcode.com/problems/append-k-integers-with-minimal-sum/

## HINT:
* Sort it or use heap to get min from nums
* Maintain the min and left count of k to sum the result.
* Use math sum to reduce the times.

## Time Complexity:
BigO(n * log(n) + k)

## Space Complexity:
BigO(n)
*/