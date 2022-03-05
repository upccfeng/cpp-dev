#include <string>
#include <sstream>

namespace p_38
{
    class Solution
    {
        int countTheSame(std::string& s, int pos, char target)
        {
            int count = 1;
            for (int i = pos; i < s.size(); i++)
            {
                if (s[i] == target)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            return count;
        }

    public:
        std::string countAndSay(int n)
        {
            std::stringstream ss;
            ss << "1";

            for (int i = 2; i <= n; i++)
            {
                std::string pre_str = ss.str();
                ss.str("");

                for (int pos = 0; pos < pre_str.size(); pos)
                {
                    char c = pre_str[pos];

                    int count = countTheSame(pre_str, pos + 1, c);

                    ss << count << c;
                    pos += count;
                }
            }

            return ss.str();
        }
    };
} // namespace p_38

/*
# Problem:
https://leetcode.com/problems/count-and-say/

## HINT:
* String operation

## Time Complexity:
BigO(n * pre_len)

## Space Complexity:
BigO(pre_len)
*/