#include <vector>
#include <string>

namespace p_2194_weekly
{
    class Solution
    {
    public:
        std::vector<std::string> cellsInRange(std::string s)
        {
            char start_char = s[0];
            int start_int = s[1] - '0';
            char end_char = s[3];
            int end_int = s[4] - '0';

            int max = std::max(start_int, end_int);

            std::vector<std::string> ret;
            for (char c = start_char; c <= end_char; c++)
            {
                int start;
                int end;

                if (c == start_char)
                {
                    start = start_int;
                    end = max;
                }
                else if (c == end_char)
                {
                    start = start_int;
                    end = end_int;
                }
                else
                {
                    start = start_int;
                    end = max;
                }

                for (int i = start; i <= end; i++)
                {
                    ret.push_back(c + std::to_string(i));
                }
            }

            return ret;
        }
    };
} // namespace p_2194_weekly

/*
# Problem:
https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

## HINT:

## Time Complexity:
BigO(Char distens * number distens)

## Space Complexity:
BigO(1)
*/