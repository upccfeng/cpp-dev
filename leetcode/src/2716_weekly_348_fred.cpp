#include <vector>
#include <set>
#include <string>
#include <limits.h>

namespace p_2716_weekly_348_fred
{
    class Solution {
    public:
        int minimizedStringLength(std::string s) {
            std::set<char> result;
            
            for (auto c : s)
            {
                result.insert(c);
            }
            
            return result.size();
        }
    };
} // namespace p_2716_weekly_348_fred

/*
# Problem:
https://leetcode.com/problems/minimize-string-length/

## HINT:

## Time Complexity:

## Space Complexity:
*/