#include "assert.h"
#include <vector>
#include <string>
#include <sstream>

namespace p_68
{
    class Solution {
        std::string generateOneLine(std::vector<std::string>& words, int start, int end, int space_cnt, bool is_end)
        {
            std::stringstream ss;
            if (!is_end)
            {
                int str_cnt = end - start + 1;

                if (str_cnt == 1)
                {
                    ss << words[start];

                    for (int i = 0; i < space_cnt; i++)
                    {
                        ss << " ";
                    }

                    return ss.str();
                }

                int interval = space_cnt / (str_cnt - 1);
                int remainder = space_cnt % (str_cnt - 1);

                for (int i = 0; i < str_cnt; i++)
                {
                    ss << words[start + i];

                    if (i != str_cnt - 1)
                    {
                        for (int j = 0; j < interval; j++)
                        {
                            ss << " ";
                        }

                        if (i < remainder)
                        {
                            ss << " ";
                        }
                    }
                }
            }
            else
            {
                for (int i = start; i <= end; i++)
                {
                    ss << words[i];

                    if (i != end)
                    {
                        space_cnt--;
                        ss << " ";
                    }
                }

                for (int i = 0; i < space_cnt; i++)
                {
                    ss << " ";
                }
            }

            return ss.str();
        }

    public:
        std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
        {
            int taking = 0;

            std::vector<std::string> ret;

            int start = 0;

            int str_size = 0;
            int space_cnt = 0;
            while (taking < words.size())
            {
                if (str_size == 0)
                {
                    str_size += words[taking].size();
                    taking++;
                }
                else
                {
                    if (str_size + space_cnt + 1 + words[taking].size() <= maxWidth)
                    {
                        str_size += words[taking].size();
                        space_cnt++;
                        taking++;
                    }
                    else
                    {
                        space_cnt = maxWidth - str_size;
                    }
                }

                if (str_size + space_cnt == maxWidth)
                {
                    ret.push_back(generateOneLine(words, start, taking - 1, space_cnt, false));

                    str_size = 0;
                    space_cnt = 0;
                    start = taking;
                }
            }

            if (str_size != 0)
            {
                ret.push_back(generateOneLine(words, start, taking - 1, maxWidth - str_size, true));
            }

            return ret;
        }
    };
} // namespace p_68

/*
# Problem:
https://leetcode.com/problems/text-justification/

## HINT:
* Count the word and space until exceed the maxWidth
* Separate the space equally between words.

## Time Complexity:
BigO(words * width)

## Space Complexity:
BigO(width)
*/