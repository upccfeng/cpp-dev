#include "assert.h"
#include <vector>
#include <string>
#include <sstream>

namespace p_curated_string_271_encode_and_decode_strings
{
    class Codec
    {
    public:

        // Encodes a list of strings to a single string.
        std::string encode(std::vector<std::string>& strs)
        {
            std::stringstream ss;
            for (std::string& s : strs)
            {
                int size = s.size();

                for (int i = 2; i >= 0; i--)
                {
                    int digit = size / std::pow(10, i);
                    ss << digit;

                    size -= digit * std::pow(10, i);
                }

                assert(size == 0);

                ss << s;
            }

            return ss.str();
        }

        // Decodes a single string to a list of strings.
        std::vector<std::string> decode(std::string s)
        {
            std::vector<std::string> ret;
            std::stringstream ss;
            int pos = 0;

            while (pos < s.size())
            {
                ss.str("");
                assert(pos + 2 < s.size());

                int size = 0;
                for (int i = 0; i < 3; i++)
                {
                    size = size * 10 + (s[pos + i] - '0');
                }
                pos += 3;

                for (int i = 0; i < size; i++)
                {
                    ss << s[pos++];
                }

                ret.emplace_back(ss.str());
            }

            return ret;
        }
    };
} // namespace p_curated_string_271_encode_and_decode_strings

/*
# Problem:
https://leetcode.com/problems/encode-and-decode-strings/

## HINT:
* Use chunk to encode/decode.
* Check the limitatio of strs, use proper digits to store the len of each string.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/