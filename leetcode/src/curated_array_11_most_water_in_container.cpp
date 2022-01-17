#include <vector>
#include <list>

namespace p_curated_array_11_most_water_in_container
{
    class Solution
    {
    public:
        int maxArea(std::vector<int>& height)
        {
            int left = 0;
            int right = height.size() - 1;

            int max = 0;
            while (left < right)
            {
                int heigh = height[left] < height[right] ? height[left] : height[right];
                int taking = (right - left) * heigh;

                max = taking > max ? taking : max;

                if (height[left] > height[right])
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }

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
        int maxArea(std::vector<int>& height)
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
} // namespace p_curated_array_11_most_water_in_container

/*
Problem: https://leetcode.com/problems/container-with-most-water/

HINT:
* Use left and right to check the area between these two.
* Move the smaller one.

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
Self: n + (1+n)*n/2 => BigO(n^2)
BigO(n)

Space Complexity:
Self: BigO(1)
BigO(1)
*/