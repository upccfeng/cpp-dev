
class Solution
{
public:
    int dic[38] = {};
    int tribonacci(int n)
    {
        dic[0] = 0;
        dic[1] = 1;
        dic[2] = 1;
        int ans = 0;
        ans = Tribonacci_Number(n);
        return ans;
    }
    int Tribonacci_Number(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (dic[n] != 0)
            return dic[n];
        else
        {
            dic[n] = Tribonacci_Number(n - 1) + Tribonacci_Number(n - 2) + Tribonacci_Number(n - 3);
            return dic[n];
        }
    }
};