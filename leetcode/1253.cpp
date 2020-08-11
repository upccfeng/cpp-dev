#include <iostream>
#include <vector>
using namespace std;
/*
#include "problem_solution/1253.cpp"

int main()
{
    Solution s;
    int upper = 9;
    int lower = 2;
    vector<int> colsum = {0, 1, 2, 0, 0, 0, 0, 0, 2, 1, 2, 1, 2};
    vector<vector<int>> ans = s.reconstructMatrix(upper, lower, colsum);
    return 0;
}
*/
class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        int total = 0;

        int size = colsum.size();
        vector<vector<int>> ans(2, vector<int>(size, 0));
        vector<int> &row1 = ans[0];
        vector<int> &row2 = ans[1];
        int curr1 = 0;
        int curr2 = 0;

        vector<int> onepos;

        for (int i = 0; i < colsum.size(); i++)
        {
            total += colsum[i];
            if (colsum[i] == 2)
            {
                row1[i] = 1;
                row2[i] = 1;
                curr1++;
                curr2++;
                if (curr1 > upper || curr2 > lower)
                {
                    return {};
                }
            }
            else if (colsum[i] == 1)
            {
                onepos.emplace_back(i);
            }
        }
        if (upper + lower != total)
        {
            return {};
        }

        for (int pos : onepos)
        {
            if (curr1 < upper)
            {
                row1[pos] = 1;
                curr1++;
            }
            else if (curr2 < lower)
            {
                row2[pos] = 1;
                curr2++;
            }
            else
            {
                return {};
            }
        }
        return ans;
    }
};