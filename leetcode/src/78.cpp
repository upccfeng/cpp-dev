#include <vector>

namespace p_78
{
    class Solution
    {
        void dfs(std::vector<int>& nums, std::vector<int>& taking, int pos, std::vector<std::vector<int>>& ret)
        {
            if (pos == nums.size())
            {
                ret.push_back(taking);
                return;
            }

            taking.push_back(nums[pos]);
            dfs(nums, taking, pos + 1, ret);


            taking.pop_back();
            dfs(nums, taking, pos + 1, ret);
        }

    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums)
        {

            std::vector<std::vector<int>> ret;

            std::vector<int> taking;
            dfs(nums, taking, 0, ret);

            return ret;
        }
    };
} // namespace p_78

/*
# Problem:
https://leetcode.com/problems/subsets/

## HINT:
* For each element, we can pick or not.
* Use backtrack with dfs

## Time Complexity:
BigO(2^n)

## Space Complexity:
BigO(n)
*/