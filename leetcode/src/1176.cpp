#include <vector>
using namespace std;
class Solution
{
public:
    int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper)
    {
        int interval_cal = 0;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            interval_cal += calories[i];
        }
        if (interval_cal < lower)
            ans--;
        if (interval_cal > upper)
            ans++;
        for (int i = k; i < calories.size(); i++)
        {
            interval_cal = interval_cal + calories[i] - calories[i - k];
            if (interval_cal < lower)
                ans--;
            if (interval_cal > upper)
                ans++;
        }

        return ans;
    }
};