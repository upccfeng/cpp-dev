#include <vector>
#include <string>
using namespace std;

namespace p3662_daily
{
    class Solution
    {
    public:
        int minimumLengthEncoding(vector<string>& words)
        {
            vector<string> ret_str;

            for (const auto& e : words)
            {
                if (ret_str.empty())
                {
                    ret_str.emplace_back(e);
                }
                else
                {
                    bool is_match = true;
                    for (auto& t : ret_str)
                    {
                        is_match = true;
                        if (e.size() <= t.size())
                        {
                            // may match
                            int i = t.size()-1;
                            int j = e.size()-1;
                            for (j; j >= 0; --j)
                            {
                                if (e[j] != t[i])
                                {
                                    is_match = false;
                                    break;
                                }
                                --i;
                            }

                            if (is_match)
                                break;
                            else
                                continue;
                        }
                        else
                        {
                            // may append
                            int i = t.size()-1;
                            int j = e.size()-1;
                            for (i; i >= 0; --i)
                            {
                                if (t[i] != e[j])
                                {
                                    is_match = false;
                                    break;
                                }
                                --j;
                            }

                            if (is_match)
                            {
                                t = e.substr(0, j + 1)+ t;
                                break;
                            }
                            else
                                continue;
                        }
                    }

                    if (!is_match)
                    {
                        ret_str.emplace_back(e);
                    }
                }
            }

            int ret = 0;
            for (const auto& e : ret_str)
            {
                ret += e.size() + 1;
            }

            return ret;
        }
    };
} // namespace p3662_daily

/*
# Problem:

## HINT:

## Algorithm:

## Time Complexity:

## Space Complexity:
*/