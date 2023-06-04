namespace p461
{
    class Solution
    {
    public:
        int hammingDistance(int x, int y)
        {
            int distance = 0;
            while (x > 0 && y > 0)
            {
                distance += (x % 2) ^ (y % 2);
                x = x >> 1;
                y = y >> 1;
            }

            while (x > 0)
            {
                distance += x % 2;
                x = x >> 1;
            }

            while (y > 0)
            {
                distance += y % 2;
                y = y >> 1;
            }

            return distance;
        }
    };
} // namespace p461

/*
# Problem:
https://leetcode.com/problems/hamming-distance/

## HINT:
bitwise operator, >> and ^ are usefull

## Algorithm:

```python
def hammingDistance(x, y):
    distance = 0;
    while x > 0 and y > 0:
        distance += (x % 2) ^ (y % 2)
        x = x >> 1
        y = y >> 1

    for the un-zero v in [x, y]:
        distance += x % 2
        v = v >> 1

    return distance
```

## Time Complexity:

BigO(n), n is the nubmer bits of the large one.

## Space Complexity:
BigO(1)
*/