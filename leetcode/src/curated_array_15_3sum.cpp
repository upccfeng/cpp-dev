#include <vector>
#include <algorithm>
#include <map>

namespace p_curated_array_15_3sum
{
    class Solution
    {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
        {
            if (!nums.empty())
            {
                std::sort(nums.begin(), nums.end());

                if (nums[0] > 0)
                {
                    return {};
                }
            }

            std::vector<std::vector<int>> ans;
            std::map<std::vector<int>, int> ans_map;
            for (int i = 0; i < nums.size(); ++i)
            {
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[i] + nums[left] + nums[right] == 0)
                    {
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (right > left && nums[right] == nums[right - 1]) --right;

                        std::vector<int> tmp = { nums[i], nums[left], nums[right] };
                        if (ans_map.find(tmp) == ans_map.end())
                        {
                            ans_map[tmp] = 1;
                        }
                        ++left;
                        --right;
                    }
                    else if (nums[i] + nums[left] + nums[right] < 0)
                    {
                        ++left;
                    }
                    else // (nums[i] + nums[left] + nums[right] > 0)
                    {
                        --right;
                    }
                }
            }

            for (auto& e : ans_map)
            {
                ans.push_back(e.first);
            }

            return ans;
        }
    };
} // namespace p_curated_array_15_3sum

/*
# Problem:
https://leetcode.com/problems/3sum/

## HINT:
* Use a map for quickly search.
* Can not use vector in unordered_map, just use map
* In the "nums[i] + nums[left] + nums[right] == 0" case, shift the position to avoid all the same value to optimize.
* After sorting, if the first element is greater than 0, there is no any suitable triplet.

## Algorithm:

ans = []
sort nums

for i in range(0, nums.size()):
    left = i + 1
    right = nums.size()-1
    while (left < right):
        if(nums[i] + nums[left] + nums[right] == 0):
            ans.append([nums[i], nums[left], nums[right]])
        else if(nums[i] + nums[left] + nums[right] > 0):
            ++left
        else if (nums[i] + nums[left] + nums[right] < 0):
            --right

     return ans
## Time Complexity:
BigO(n^2)

## Space Complexity:
BigO(n)
*/