#include <vector>
#include <cmath>
using namespace std;

namespace p_rekuten210221_1
{
    class Solution
    {
    public:
        int solution(vector<int> &A) {
            int arr[10020] = {0};

            int max = -1;
            for (const auto& e : A)
            {
                if (e > max)
                    max = e;
                ++arr[e];
            }

            int ans = 0;
            for (int i = 0; i < max + 1; ++i)
            {
                int tmp = arr[i];
                if (tmp%2 == 1)
                    ++ans;

                arr[i] = tmp%2;
                arr[i+1] += tmp/2;

                if (i == max)
                {
                    int j = i + 1;
                    while(arr[j] != 0)
                    {
                        tmp = arr[j];
                        if (tmp%2 == 1)
                            ++ans;
                        arr[j] = tmp%2;
                        arr[j+1] += tmp/2;
                        j++;
                    }
                }
            }

            return ans;
        }
    };
} // namespace p_rekuten210221_1

/*
# Problem:

Rekuten test on 20210221

Input: array of int, example: [2, 0, 0] mean value = 2^2 + 2^0 + 2^0 = 6
output: the shortest array lenght which value is 6

## HINT:

Max data will be N * 2^numbers
N: 1..100000
number: 0..10000
pow2_array[10000] is not enough. pow2_array[10017] is enough.

## Algorithm:

```
arr[10020] = {0}
max = -1;
for (const auto& e : A):
    if e > max:
        max = e
    ++arr[e]

ans = 0
for i = 0; i < max + 1; ++i:
    tmp = arr[i]
    if tmp%2 == 1:
        ++ans

    arr[i] = tmp%2
    arr[i+1] += tmp/2

    if i == max:
        j = i + 1
        while arr[j] != 0:
            tmp = arr[j]
            if tmp%2 == 1:
                ++ans
            arr[j] = tmp%2
            arr[j+1] += tmp/2
            j++;

return ans
```

## Time Complexity:
log(n + 10020)

## Space Complexity:
log(10020)
*/