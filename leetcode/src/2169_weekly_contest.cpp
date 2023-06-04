namespace p_2169_weekly_contest
{
    class Solution {
    public:
        int countOperations(int num1, int num2)
        {
            int cnt = 0;

            while (num1 != 0 && num2 != 0)
            {
                if (num1 >= num2)
                {
                    num1 = num1 - num2;
                }
                else
                {
                    num2 = num2 - num1;
                }
                ++cnt;
            }

            return cnt;
        }
    };
} // namespace p_2169_weekly_contest

/*
# Problem:
https://leetcode.com/problems/count-operations-to-obtain-zero/

## HINT:

## Algorithm:

## Time Complexity:
O(n)

## Space Complexity:
O(1)
*/