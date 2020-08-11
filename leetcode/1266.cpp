#include <iostream>
#include <vector>

using namespace std;

/*
#include "problem_solution/1266.cpp"

int main()
{
    Solution s;
    vector<vector<int>> input = {{3, 2}, {-2, 2}};
    int ans = s.minTimeToVisitAllPoints(input);
    cout << ans << endl;
    return 0;
}
*/

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        const vector<int> *now = nullptr;
        for (const auto &p : points)
        {
            if (now == nullptr)
            {
                now = &p;
                continue;
            }
            int dis_x = abs((*now)[0] - p[0]);
            int dis_y = abs((*now)[1] - p[1]);
            ans += min(dis_x, dis_y) + abs(dis_x - dis_y);
            now = &p;
        }
        return ans;
    }
};