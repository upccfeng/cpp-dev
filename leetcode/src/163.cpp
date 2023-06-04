#include "assert.h"
#include <vector>
#include <string>
#include <sstream>

namespace p_163
{
    class Solution
    {
    public:
        std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
        {
            std::vector<std::string> ret;

            int current = lower;

            int nums_ptr = 0;
            while (nums_ptr < nums.size() && nums[nums_ptr] < lower)
            {
                nums_ptr++;
            }

            std::stringstream ss;

            while (current <= upper && nums_ptr < nums.size())
            {
                if (nums[nums_ptr] == current)
                {
                    current++;
                    nums_ptr++;
                }
                else if (nums[nums_ptr] > current)
                {
                    int bound = nums[nums_ptr] - 1;

                    ss << current;

                    if (bound - current > 0)
                    {
                        ss << "->" << bound;
                    }

                    ret.emplace_back(ss.str());

                    current = nums[nums_ptr] + 1;
                    nums_ptr++;
                    ss.str("");
                }
                else
                {
                    nums_ptr++;
                }
            }

            if (current <= upper)
            {
                int bound = upper;

                ss << current;

                if (bound - current > 0)
                {
                    ss << "->" << bound;
                }

                ret.emplace_back(ss.str());
            }

            return ret;
        }
    };
} // namespace p_163

/*
# Problem:
https://leetcode.com/problems/missing-ranges/

## HINT:

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(BIGGEST int STRING)
*/