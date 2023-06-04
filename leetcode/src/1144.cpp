#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        vector<int> bkup(nums);
        int ans, omove, emove;
        omove = odd(nums);
        nums.assign(bkup.begin(), bkup.end());
        emove = even(bkup);
        ans = min(omove, emove);
        return ans;
    }
    int odd(vector<int> &nums)
    {
        int moves = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            int leftindex = i - 1;
            int rightindex = i + 1;
            if (leftindex >= 0)
            {
                int movecount = 0;
                if (nums[leftindex] >= nums[i])
                {
                    movecount = nums[leftindex] - nums[i] + 1;
                }
                nums[leftindex] -= movecount;
                moves += movecount;
            }
            if (rightindex < nums.size())
            {
                int movecount = 0;
                if (nums[rightindex] >= nums[i])
                {
                    movecount = nums[rightindex] - nums[i] + 1;
                }
                nums[rightindex] -= movecount;
                moves += movecount;
            }
        }
        return moves;
    }
    int even(vector<int> &nums)
    {
        int moves = 0;
        for (int i = 1; i < nums.size(); i += 2)
        {
            int leftindex = i - 1;
            int rightindex = i + 1;
            if (leftindex >= 0)
            {
                int movecount = 0;
                if (nums[leftindex] >= nums[i])
                {
                    movecount = nums[leftindex] - nums[i] + 1;
                }
                nums[leftindex] -= movecount;
                moves += movecount;
            }
            if (rightindex < nums.size())
            {
                int movecount = 0;
                if (nums[rightindex] >= nums[i])
                {
                    movecount = nums[rightindex] - nums[i] + 1;
                }
                nums[rightindex] -= movecount;
                moves += movecount;
            }
        }
        return moves;
    }
};