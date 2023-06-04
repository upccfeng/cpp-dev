#include <vector>
using namespace std;

namespace p307
{
    class NumArray {
        vector<int> _nums;
        int _sum;

    public:
        NumArray(vector<int>& nums) : _nums(nums), _sum(0) {
            for (const auto& e : nums)
                _sum += e;
        }

        void update(int index, int val) {
            _sum += val - _nums[index];
            _nums[index] = val;
        }

        int sumRange(int left, int right) {

            int ret = _sum;

            for (int index = 0; index < left; ++index)
            {
                ret -= _nums[index];
            }

            for (int index = right + 1; index < _nums.size(); ++index)
            {
                ret -= _nums[index];
            }

            return ret;
        }
    };

} // namespace p307

/*
# Problem:

https://leetcode.com/problems/range-sum-query-mutable/

## HINT:

Need to cache the sum of nums. And update the cache while updating an element.

## Algorithm:

Update the sum cache for each update.
While calling sumRange, deduct the non-included part.

## Time Complexity:

## Space Complexity:
*/