#include <string>

namespace p_2222_biweekly_75
{
    class Solution
    {
    public:
        long long numberOfWays(std::string s)
        {
            long long one_sum = 0;
            long long zero_sum = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '0')
                {
                    zero_sum++;
                }
                else
                {
                    one_sum++;
                }
            }

            //std::vector<int> L0(s.size());
            //std::vector<int> L1(s.size());
            //std::vector<int> R0(s.size());
            //std::vector<int> R1(s.size());

            long long one_cnt = 0;
            long long zero_cnt = 0;

            long long cnt = 0;

            for (int i = 0; i < s.size(); i++)
            {
                //L0[i] = zero_cnt;
                //L1[i] = one_cnt;

                if (s[i] == '0')
                {
                    cnt += one_cnt * (one_sum - one_cnt);
                    zero_cnt++;
                }
                else
                {
                    cnt += zero_cnt * (zero_sum - zero_cnt);
                    one_cnt++;
                }

                //R0[i] = zero_sum - zero_cnt;
                //R1[i] = one_sum - one_cnt;
            }
            //long long cnt = 0;

            //for (int mid = 0; mid < s.size(); mid++)
            //{
            //    if (s[mid] == '0')
            //    {
            //        cnt += (long long)L1[mid] * (long long)R1[mid];
            //    }
            //    else
            //    {
            //        cnt += (long long)L0[mid] * (long long)R0[mid];
            //    }
            //}

            return cnt;
        }
    };
} // namespace p_2222_biweekly_75

/*
# Problem:
https://leetcode.com/problems/number-of-ways-to-select-buildings/

## HINT:
* Count the numbers of left-0, right-0, left-1 and right-1.
* Use each char as middle.
* For each char as middle, add the product of left-0(or left-1) and right-0(or right-1).

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/