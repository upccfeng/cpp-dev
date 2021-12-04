#include <iostream>
#include <vector>

using namespace std;

/*
#include "problem_solution/1267.cpp"

int main()
{
    Solution s;
    vector<vector<int>> input = {{1, 0, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}};
    int ans = s.countServers(input);
    cout << ans << endl;
    return 0;
}
*/

class Solution
{

    bool have_Neighbor(int x, int y, vector<vector<int>> &grid)
    {
        int bound_x = grid.size();
        int bound_y = grid[0].size();

        int tmp_y = 0;
        while (tmp_y < bound_y)
        {
            if (grid[x][tmp_y] == 1 && tmp_y != y)
            {
                return true;
            }
            tmp_y++;
        }

        int tmp_x = 0;
        while (tmp_x < bound_x)
        {
            if (grid[tmp_x][y] == 1 && tmp_x != x)
            {
                return true;
            }
            tmp_x++;
        }
        return false;
    }

public:
    int countServers(vector<vector<int>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                const auto &p = grid[i][j];
                if (p == 1)
                {
                    if (have_Neighbor(i, j, grid))
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};