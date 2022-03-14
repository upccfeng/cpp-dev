#include "assert.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

namespace p_179
{
    class Solution
    {
    public:
        std::string largestNumber(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
                std::string lstr = std::to_string(lhs);
                std::string rstr = std::to_string(rhs);

                // Method-2: compare str(lhs + rhs) and str(rhs + lhs) directly

                int l_pos = 0;
                int r_pos = 0;

                while (l_pos != lstr.size() && r_pos != rstr.size())
                {
                    if (lstr[l_pos] > rstr[r_pos])
                    {
                        return true;
                    }
                    else if (lstr[l_pos] < rstr[r_pos])
                    {
                        return false;
                    }
                    else
                    {
                        l_pos++;
                        r_pos++;
                    }

                    if (l_pos == lstr.size() || r_pos == rstr.size())
                    {
                        if (l_pos == lstr.size() && r_pos == rstr.size())
                        {
                            break;
                        }
                        else if (r_pos != rstr.size())
                        {
                            l_pos = 0;
                        }
                        else
                        {
                            r_pos = 0;
                        }
                    }
                }

                return false;
                });

            std::stringstream ss;

            for (auto n : nums)
            {
                if (ss.str() == "0" && n == 0)
                {
                    ;
                }
                else
                {
                    ss << n;
                }
            }

            return ss.str();
        }
    };
} // namespace p_179

/*
# Problem:
https://leetcode.com/problems/largest-number/

## HINT:
* Sort nums with customized comparison, determine which is bigger.
* The result of cmp(a, a) should be false to avoid invalid cmp in sort, which will cause a < b is true and b < a is true too.

## Time Complexity:
BigO(n * log(n) * len(nums[i]))

## Space Complexity:
BigO(len(nums[i]))
*/