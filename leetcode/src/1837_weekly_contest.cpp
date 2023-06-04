#include <cmath>
using namespace std;

namespace p1837_weekly_contest
{
    class Solution
    {
    public:
        int sumBase(int n, int k)
        {
            int k_base = 0;
            int remain = n;

            int cnt = 0;
            while (remain >= k)
            {
                k_base = k_base + (remain % k * pow(10, cnt++));
                remain = remain / k;
            }

            k_base = k_base + (remain % k * pow(10, cnt++));

            int res = 0;

            while(k_base != 0)
            {
                res += k_base % 10;
                k_base /= 10;
            }

            return res;
        }
    };
} // namespace p1837_weekly_contest

/*
# Problem:

https://leetcode.com/problems/sum-of-digits-in-base-k/

## HINT:

## Algorithm:

```
def sumBase(n, k):
    k_base = 0
    remain = n

    cnt = 0
    while (remain >= k):
        k_base = k_base + (remain % k * pow(10, cnt++))
        remain = remain / k

    k_base = k_base + (remain % k * pow(10, cnt++))

    res = 0

    while (k_base != 0):
        res += k_base % 10
        k_base /= 10

    return res
}
```

## Time Complexity:
O(n)

## Space Complexity:
O(1)
*/