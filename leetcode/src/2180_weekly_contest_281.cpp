namespace p_2180_weekly_contest_281
{
    class Solution
    {
    public:
        int countEven(int num)
        {
            int ans = 0;
            for (int taking = 1; taking <= num; ++taking)
            {
                int tmp = taking;
                int sum = 0;
                while (tmp != 0)
                {
                    sum += tmp % 10;
                    tmp /= 10;
                }

                if (sum % 2 == 0)
                {
                    ++ans;
                }
            }

            return ans;
        }
    };
} // namespace p_2180_weekly_contest_281

/*
# Problem:
https://leetcode.com/problems/count-integers-with-even-digit-sum/

## HINT:

## Time Complexity:
BigO(n * 4)

## Space Complexity:
BigO(1)
*/