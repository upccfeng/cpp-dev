#include <string>
#include <vector>

namespace p_2182_weekly_contest_281
{
    class Solution
    {
    public:
        std::string repeatLimitedString(std::string s, int repeatLimit)
        {
            std::vector<int> apear_cnt(26, 0);

            //a = 97, store in 0
            for (auto& c : s)
            {
                ++apear_cnt[c - 97];
            }

            std::string ans("");

            int taking = 25;
            int pre = -1;

            while (taking != -1)
            {
                if (pre == -1)
                {
                    // pick as more as possible
                    if (apear_cnt[taking] <= repeatLimit)
                    {
                        for (int i = 0; i < apear_cnt[taking]; ++i)
                        {
                            ans.push_back(taking + 97);
                        }

                        apear_cnt[taking] = 0;

                        pre = -1;
                        bool updated = false;
                        for (int i = taking; i >= 0; --i)
                        {
                            if (apear_cnt[i] != 0)
                            {
                                taking = i;
                                updated = true;
                                break;
                            }
                        }

                        if (!updated)
                        {
                            taking = -1;
                        }

                    }
                    else
                    {
                        for (int i = 0; i < repeatLimit; ++i)
                        {
                            ans.push_back(taking + 97);
                        }

                        apear_cnt[taking] -= repeatLimit;

                        pre = taking;
                        bool updated = false;
                        for (int i = taking - 1; i >= 0; --i)
                        {
                            if (apear_cnt[i] != 0)
                            {
                                updated = true;
                                taking = i;
                                break;
                            }
                        }

                        if (!updated)
                        {
                            taking = -1;
                        }
                    }
                }
                else
                {
                    // pick just one and rollback
                    ans.push_back(taking + 97);
                    --apear_cnt[taking];

                    taking = pre;
                    pre = -1;
                }

                int a = 10;
            }

            return ans;
        }
    };
} // namespace p_2182_weekly_contest_281

/*
# Problem:
https://leetcode.com/problems/construct-string-with-repeat-limit/

## HINT:
* Use a data structure(array, map, ...) to store the count of each char(from a-z).
* The bigger charater(z > x > y > ... > a) has bigger priority. Pick the high priorities first.
* Once exceed the limitation, pick one from the next priority and back to the previous character.

## Time Complexity:
BigO(26 * limit)

## Space Complexity:
BigO(26)
*/