#include <vector>

namespace p_118
{
    class Solution
    {
    public:
        std::vector<std::vector<int>> generate(int numRows) {

            std::vector<std::vector<int>> ret(numRows);

            ret[0].emplace_back(1);

            for (int i = 1; i < numRows; i++)
            {
                auto& pre = ret[i - 1];
                for (int j = 0; j < pre.size() + 1; j++)
                {
                    int left = j - 1;
                    int right = j;

                    int val = 0;
                    if (j - 1 >= 0 & j - 1 < pre.size())
                    {
                        val += pre[j - 1];
                    }

                    if (j >= 0 & j < pre.size())
                    {
                        val += pre[j];
                    }

                    ret[i].emplace_back(val);
                }
            }

            return ret;
        }
    };
} // namespace p_118

/*
# Problem:
https://leetcode.com/problems/pascals-triangle/

## HINT:
* Level-0: {1}
* For each element i in level-n: the value will be sum of level-(n-1)[i-1] and level-(n-1)[i]
* If i or i-1 is out of boundary, treat it as zero.

## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(1)
*/