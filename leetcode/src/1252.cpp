#include <iostream>
#include <vector>
using namespace std;
/*
#include "problem_solution/1252.cpp"

int main()
{
    Solution s;
    int n = 48, m = 37;
    vector<vector<int>> input;
    input.push_back({40, 5});
    int ans = s.oddCells(n, m, input);
    cout << ans << endl;
    return 0;
}
*/
class Solution
{
public:
    int oddCells(int n, int m, vector<vector<int>> &indices)
    {
        int oddans = 0;
        vector<vector<int>> initarray(n, vector<int>(m, 0));
        /*
        int initarray[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                initarray[i][j] = 0;
            }
        }
        */

        for (const auto &indice : indices)
        {
            int ri = indice[0];
            int rc = indice[1];

            for (int i = 0; i < m; i++)
            {
                initarray[ri][i]++;
                if (initarray[ri][i] % 2 == 1)
                {
                    oddans++;
                }
                else
                {
                    oddans--;
                }
            }
            for (int i = 0; i < n; i++)
            {
                initarray[i][rc]++;
                if (initarray[i][rc] % 2 == 1)
                {
                    oddans++;
                }
                else
                {
                    oddans--;
                }
            }
        }
        return oddans;
    }
};