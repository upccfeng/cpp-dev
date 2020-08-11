#include <iostream>
#include <vector>

class Solution
{
public:
    int numPrimeArrangements(int n)
    {
        int dic[101] = {0};
        int MOD = 1000000007;
        dic[2] = 1;
        dic[3] = 1;
        dic[5] = 1;
        dic[7] = 1;
        dic[11] = 1;
        dic[13] = 1;
        dic[17] = 1;
        dic[19] = 1;
        dic[23] = 1;
        dic[29] = 1;
        dic[31] = 1;
        dic[37] = 1;
        dic[41] = 1;
        dic[43] = 1;
        dic[47] = 1;
        dic[53] = 1;
        dic[59] = 1;
        dic[61] = 1;
        dic[67] = 1;
        dic[71] = 1;
        dic[73] = 1;
        dic[79] = 1;
        dic[83] = 1;
        dic[89] = 1;
        dic[97] = 1;
        int pri_count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dic[i] == 1)
                pri_count++;
        }

        int normal_count = n - pri_count;

        long int ans = 1;
        for (int i = normal_count; i > 0; i--)
        {
            ans = (ans * i) % MOD;
            if (ans > MOD)
                ans = ans % MOD;
        }
        for (int i = pri_count; i > 0; i--)
        {
            ans *= i;
            if (ans > MOD)
                ans = ans % MOD;
        }
        return ans;
    }
};