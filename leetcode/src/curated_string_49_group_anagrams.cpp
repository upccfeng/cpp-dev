#include <vector>
#include <map>
#include <string>
#include <set>

////////////////////////////////////////////////////////

namespace p_curated_string_49_group_anagrams
{
    class Solution
    {
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
        {
            std::map<std::vector<int>, std::set<int>> char_cnt_map;

            for (int pos = 0; pos < strs.size(); ++pos)
            {
                std::vector<int> tmp(26, 0);

                const std::string& s = strs[pos];
                for (const auto& c : s)
                {
                    tmp[c - 97] += 1;
                }

                char_cnt_map[std::move(tmp)].emplace(pos);
            }

            std::vector<std::vector<std::string>> ret;
            for (const auto& kv : char_cnt_map)
            {
                std::vector<std::string> tmp;
                for (int pos : kv.second)
                {
                    tmp.emplace_back(std::move(strs[pos]));
                }

                ret.emplace_back(std::move(tmp));
            }

            return ret;
        }
    };
} // namespace p_curated_string_49_group_anagrams

/*
# Problem:
https://leetcode.com/problems/group-anagrams/

## HINT:
* Use a vector(or map) to store the count of each char in each string in strs.
* Use a set to store the position which has the same vector value.
* Use a map with the vector as key and the set as value.
* Anagrams have the same vector value.

## Time Complexity:
BigO(n * str.size)

## Space Complexity:
BigO(n * 26)
*/