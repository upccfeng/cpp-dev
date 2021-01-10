#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

namespace p11
{
    class Solution
    {
        using list_t = std::list<int>;
        list_t height_list[30001];
    public:
        int maxArea(vector<int>& height)
        {
            auto it = height.begin();
            int max_height = 0;
            for (it; it != height.end(); ++it)
            {
                if (*it > max_height)
                {
                    max_height = *it;
                }
                int pos = std::distance(height.begin(), it);
                for (int h = 1; h <= *it; h++)
                {
                    height_list[h].emplace_back(pos);
                }
            }

            int max_water = 0;
            for (int taking_height = max_height; taking_height > 0 ; --taking_height)
            {
                int temp_water, left, right;
                left = height_list[taking_height].front();
                right = height_list[taking_height].back();
                temp_water = taking_height * (right - left);
                if (temp_water > max_water)
                {
                    max_water = temp_water;
                }
            }
            return max_water;
        }
    };
} // namespace p11

/*
Problem: https://leetcode.com/problems/container-with-most-water/

HINT:

Algorithm:

```
```

Time Complexity:

Space Complexity:
*/