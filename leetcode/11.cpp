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
    public:
        int maxArea(vector<int>& height)
        {
            int max = 0;
            auto l_it = height.begin();
            auto r_it = height.end() - 1;
            while (true)
            {
                int distance = std::distance(l_it, r_it);
                max = std::max(max, std::min(*l_it, *r_it) * distance);

                if (*l_it > *r_it)
                {
                    --r_it;
                }
                else
                {
                    ++l_it;
                }

                if (distance == 1)
                {
                    break;
                }
            };

            return max;
        }
    };

    class Solution_self
    {
        using list_t = std::list<int>;
        using boundary_t = std::pair<int, int>;
        list_t height_list[30001];

        boundary_t get_boundary(int level, list_t* list, int max)
        {
            int rightest = height_list[level].back();
            int leftest = height_list[level].front();
            for (int i = max; i > level; --i)
            {
                if (list[i].empty())
                {
                    continue;
                }

                if (list[i].back() > rightest)
                {
                    rightest = list[i].back();
                }

                if (list[i].front() < leftest)
                {
                    leftest = list[i].front();
                }
            }

            return std::make_pair(leftest, rightest);
        }

    public:
        int maxArea(vector<int>& height)
        {
            auto it = height.begin();
            int max_height = 0;
            for (it; it != height.end(); ++it)
            {
                int pos = std::distance(height.begin(), it);
                if (*it > max_height)
                {
                    max_height = *it;
                }
                height_list[*it].emplace_back(pos);
            }

            int max_water = 0;
            for (int taking_height = max_height; taking_height > 0 ; --taking_height)
            {
                if (height_list[taking_height].empty())
                {
                    continue;
                }

                auto boundary = get_boundary(taking_height, height_list, max_height);

                int temp_water = taking_height * (boundary.second - boundary.first);
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

Algorithm
Self:
```
record each level postion in list

max = 0
for each level:
    tmp = level * (list.find_rightest() - list.find_leftest())
    max = get_max(max, min)
```

Ans:
```
left = height.begin()
right = height.end() - 1

max = 0
while true:
    tmp = min(right, right) * distance(right, left)

    //
    // smaller should move
    // greater move can not get greater area
    //
    if right < left:
        --right
    else:
        ++left

    if distance(right, left) == 1:
        break;
```

Time Complexity:
Self: n + (1+n)*n/2 => log(n^2)
Ans: log(n)

Space Complexity:
Self: log(1)
Ans: log(1)
*/