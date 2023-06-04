#include <vector>

namespace p1306
{
    class Solution
    {
    private:
        bool isReachableToZero(std::vector<int>& arr, int pos)
        {
            if (0 > pos || arr.size() <= pos)
            {
                return false;
            }

            if (0 == arr[pos])
            {
                return true;
            }

            if (arr[pos] == -1)
            {
                return false;
            }
            int value = arr[pos];
            arr[pos] = -1;

            if (isReachableToZero(arr, pos + value))
            {
                return true;
            }
            arr[pos] = value;

            if (isReachableToZero(arr, pos - value))
            {
                return true;
            }

            return false;
        }
    public:
        bool canReach(std::vector<int>& arr, int start)
        {
            return isReachableToZero(arr, start);
        }
    };
} // namespace p1306

/*
# Problem:
https://leetcode.com/problems/jump-game-iii/

## HINT:
Find both side of the position's left and position's right until loop or out of boundary.
Can use addtional cache array to mark which index is already visisted.
Or use original array, assign -1 as visisted.

## Algorithm:


```pseudo code
def isReachableToZero(arr, pos):
    if pos out of boundary:
        return false

    if arr[pos] is zero:
        return true

    if arr[pos] == -1: # already loop
        return false

    value = arr[pos]
    arr[pos] = -1

    if (isReachableToZero(arr, pos + value)) # check right side
        return true

    arr[pos] = value

    if (isReachableToZero(arr, pos - value)) # check left side
        return true

    return false

return isReachableToZero(arr, start);
```

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/