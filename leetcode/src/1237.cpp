#include <iostream>
#include <vector>
class CustomFunction
{
public:
    int f(int x, int y)
    {
        return x + y;
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        std::vector<std::vector<int>> ans;
        int ylimit = 1000;
        for (int x = 1; x <= 1000 && ylimit > 0; x++)
        {
            for (int y = ylimit; y > 0; y--)
            {
                int res = customfunction.f(x, y);
                if (res <= z)
                {
                    ylimit = y;
                    if (res == z)
                        ans.push_back({x, y});
                    break;
                }
            }
        }
        return ans;
    }
};