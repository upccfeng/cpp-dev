#include "assert.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

namespace p_166
{
    class Solution
    {
    public:
        std::string fractionToDecimal(int numerator, int denominator)
        {
            int sign = 1;

            long long llnumerator = numerator;
            long long lldenominator = denominator;

            if (llnumerator < 0)
            {
                sign *= -1;
                llnumerator = -llnumerator;
            }

            if (lldenominator < 0)
            {
                sign *= -1;
                lldenominator = -lldenominator;
            }

            long long before_dot = llnumerator / lldenominator;
            long long remained = llnumerator - lldenominator * before_dot;

            std::vector<char> after_dot;
            std::unordered_map<int, int> remained_map;
            bool is_repeat = false;
            int repeat_pos = -1;
            while (remained != 0)
            {
                if (remained_map.find(remained) != remained_map.end())
                {
                    is_repeat = true;
                    repeat_pos = remained_map[remained];
                    break;
                }
                remained_map[remained] = after_dot.size();

                remained *= 10;
                int val = remained / lldenominator;
                after_dot.emplace_back(val + '0');

                remained -= val * lldenominator;
            }

            std::stringstream ss;

            if (sign == -1)
            {
                if (before_dot != 0 || after_dot.size() != 0)
                {
                    ss << '-';
                }
            }

            ss << before_dot;

            if (!after_dot.empty())
            {
                ss << ".";
            }

            for (int i = 0; i < after_dot.size(); i++)
            {
                if (is_repeat && i == repeat_pos)
                {
                    ss << '(';
                }

                ss << after_dot[i];

                if (is_repeat && i == after_dot.size() - 1)
                {
                    ss << ')';
                }
            }

            return ss.str();
        }
    };
} // namespace p_166

/*
# Problem:
https://leetcode.com/problems/fraction-to-recurring-decimal/

## HINT:
* Deal with before_point and after_point separately.
* Be care of belows cases:
* - partial repeat, like 0.1(6)
* - negitival result
* - zero with negitive sign, line 0 / -5, could be -0.
* - overflow when transfer INT_MAX to negitive.
* - overflow when int * 10 or INT_MAx / -1

## Time Complexity:
BigO(bit count)

## Space Complexity:
BigO(bit count)
*/