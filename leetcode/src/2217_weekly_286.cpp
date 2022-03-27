#include "assert.h"
#include <vector>

namespace p_2217_weekly_286
{
    class Solution {
        long long getValByCharVector(std::vector<char>& chars)
        {
            long long ret = 0;

            for (int i = 0; i < chars.size(); i++)
            {
                ret = ret * 10 + (chars[i] - '0');
            }

            return ret;
        }

    public:
        std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength)
        {
            std::vector<long long> ret(queries.size(), -1);

            for (int i = 0; i < queries.size(); i++)
            {
                std::vector<char> value_in_char(intLength, '0');

                int mid = (intLength - 1) / 2;
                int left, right;
                if (intLength % 2 == 1)
                {
                    left = mid;
                    right = mid;
                }
                else
                {
                    left = mid;
                    right = mid + 1;
                }

                int remaind = queries[i];

                while (left >= 0 && right < intLength)
                {
                    if (left != 0)
                    {
                        int cnt = remaind % 10;
                        remaind /= 10;

                        if (cnt == 0)
                        {
                            value_in_char[left] = '9';
                            value_in_char[right] = '9';
                        }
                        else
                        {
                            remaind++;
                            value_in_char[left] = (cnt - 1) + '0';
                            value_in_char[right] = (cnt - 1) + '0';
                        }
                    }
                    else
                    {
                        assert(right == intLength - 1);

                        if (remaind >= 10)
                        {
                            break;
                        }

                        int cnt = remaind % 10;
                        remaind /= 10;

                        value_in_char[left] = cnt + '0';
                        value_in_char[right] = cnt + '0';;
                    }

                    left--;
                    right++;
                }

                if (remaind != 0)
                {
                    ret[i] = -1;
                }
                else
                {
                    assert(left == -1 && right == intLength);
                    ret[i] = getValByCharVector(value_in_char);
                }
            }

            return ret;
        }
    };
} // namespace p_2217_weekly_286

/*
# Problem:
https://leetcode.com/problems/find-palindrome-with-fixed-length/

## HINT:
* From the middle to edge.

## Time Complexity:
BigO(n * k)

## Space Complexity:
BigO(k)
*/