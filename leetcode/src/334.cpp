#include "assert.h"
#include <vector>
#include <map>

namespace p_334
{
    class Solution
    {

        //struct MyKey
        //{
        //    int pos;
        //    int previous;
        //    int left_count;

        //    MyKey(int pos, int pre, int cnt) : pos(pos), previous(pre), left_count(cnt) {}

        //    bool operator<(const MyKey& rhs) const
        //    {
        //        if (this->pos != rhs.pos) return this->pos < rhs.pos;
        //        if (this->previous != rhs.previous) return this->previous < rhs.previous;
        //        if (this->left_count != rhs.left_count) return this->left_count < rhs.left_count;

        //        return false;
        //    }
        //};

        //std::map<MyKey, bool> cache;
        std::map<std::tuple<int, int, int>, bool> cache;

        bool isIncreasingExist(std::vector<int>& nums, int pos, int previous, int left_count)
        {
            //if (cache.find(MyKey(pos, previous, left_count)) != cache.end())
            if (cache.find({ pos, previous, left_count }) != cache.end())
            {
                // return cache[MyKey(pos, previous, left_count)];
                return cache[{pos, previous, left_count}];
            }

            if (left_count == 0)
            {
                return true;
            }

            if (pos < 0)
            {
                return false;
            }

            int ret = false;

            if (nums[pos] < previous || (previous == INT_MAX && left_count == 3))
            {
                ret |= isIncreasingExist(nums, pos - 1, nums[pos], left_count - 1);
                if (!ret)
                {
                    ret |= isIncreasingExist(nums, pos - 1, previous, left_count);
                }
            }
            else
            {
                ret |= isIncreasingExist(nums, pos - 1, previous, left_count);
            }


            // cache[MyKey(pos, previous, left_count)] = ret;
            cache[{pos, previous, left_count}] = ret;
            return ret;
        }

    public:
        bool increasingTripletRecursive(std::vector<int>& nums)
        {
            if (nums.size() < 3)
            {
                return false;
            }

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                bool ret = isIncreasingExist(nums, i, INT_MAX, 3);
                if (ret)
                {
                    return true;
                }
            }

            return false;
        }

        bool increasingTriplet(std::vector<int>& nums)
        {
            int first_small = INT_MAX;
            int second_small = INT_MAX;

            for (int n : nums)
            {
                if (n <= first_small)           // equal is necessary, because the third value can not equal to second_small and first_small
                {
                    first_small = n;
                }
                else if (n <= second_small)     // equal is necessary, because the third value can not equal to second_small and first_small
                {
                    second_small = n;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
    };
} // namespace p_334

/*
# Problem:
https://leetcode.com/problems/increasing-triplet-subsequence/

## HINT:
* Do not need to use recursive
* Maintain the first_small and second_small value, and make sure second_small > first_small.
* Once there is a value > second_small, return true.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/