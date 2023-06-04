#include <vector>
#include <string>
#include <stack>

namespace p_curated_string_125_valid_palindrome
{
    class Solution
    {
        bool isValid(char c)
        {
            if (c >= '0' && c <= '9' ||
                c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z')
            {
                return true;
            }

            return false;
        }

        bool isTheSame(char lhs, char rhs)
        {
            if (lhs >= 'A' && lhs <= 'Z')
            {
                lhs += 32;
            }

            if (rhs >= 'A' && rhs <= 'Z')
            {
                rhs += 32;
            }

            return lhs == rhs;
        }
    public:
        bool isPalindrome(std::string s)
        {
            int left = 0;
            int right = s.size() - 1;

            while (left < right)
            {
                if (!isValid(s[left]))
                {
                    ++left;
                }
                else if ((!isValid(s[right])))
                {
                    --right;
                }
                else
                {
                    if (isTheSame(s[left], s[right]))
                    {
                        ++left;
                        --right;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            return true;
        }


        bool isPalindromeStack(std::string s)
        {
            std::vector<char> valid_char_only;
            for (const auto& c : s)
            {
                if (c >= 48 && c <= 57)
                {
                    // valid_char_only.push_back(c);
                    valid_char_only.emplace_back(c);
                }
                else if (c >= 65 && c <= 90)
                {
                    // valid_char_only.push_back(c + 32);
                    valid_char_only.emplace_back(c + 32);
                }
                else if (c >= 97 && c <= 122)
                {
                    // valid_char_only.push_back(c);
                    valid_char_only.emplace_back(c);
                }
                else
                {
                    ;
                }
            }

            if (valid_char_only.size() == 1)
            {
                return true;
            }

            int half = valid_char_only.size() / 2;
            bool is_odd = valid_char_only.size() % 2;
            half = is_odd ? half + 1 : half;
            std::stack<char> stack;

            for (int pos = 0; pos < valid_char_only.size(); ++pos)
            {
                if (is_odd && pos == half)
                {
                    stack.pop();
                }

                const char& c = valid_char_only[pos];
                if (pos < half)
                {
                    // stack.push(c);
                    stack.emplace(c);
                }
                else
                {
                    char pop = stack.top();
                    stack.pop();

                    if (pop != c)
                    {
                        return false;
                    }
                }
            }

            return stack.size() == 0;
        }
    };
} // namespace p_curated_string_125_valid_palindrome

/*
# Problem:
https://leetcode.com/problems/valid-palindrome/

## HINT:
* Use left and right boundary, and move them to check each pair.
* Method-2: Use stack.

## Time Complexity:
BigO(n)

## Space Complexity:
Method-1: BigO(1)
Method-2: BigO(n)
*/