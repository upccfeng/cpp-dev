#include <vector>
#include <map>
#include <string>

namespace p_2211_weekly_285
{
    class Solution {
        std::map<int, bool> left_cache;
        std::map<int, bool> right_cache;

        bool isCollision(std::string& dir, bool is_left, int pos)
        {
            if (pos < 0 || pos == dir.size())
            {
                return false;
            }

            if (is_left)
            {
                if (left_cache.find(pos) != left_cache.end())
                {
                    return left_cache[pos];
                }

                if (dir[pos] == 'R' || dir[pos] == 'S')
                {
                    return true;
                }
                else
                {
                    left_cache[pos] = isCollision(dir, is_left, pos - 1);
                    return left_cache[pos];
                }
            }
            else
            {
                if (right_cache.find(pos) != right_cache.end())
                {
                    return right_cache[pos];
                }

                if (dir[pos] == 'L' || dir[pos] == 'S')
                {
                    return true;
                }
                else
                {
                    right_cache[pos] = isCollision(dir, is_left, pos + 1);
                    return right_cache[pos];
                }
            }
        }

    public:
        int countCollisions(std::string directions)
        {
            int ret = 0;
            for (int i = 0; i < directions.size(); i++)
            {
                char d = directions[i];

                if (d == 'L')
                {
                    if (isCollision(directions, true, i - 1))
                    {
                        ret++;
                    }
                }
                else if (d == 'R')
                {
                    if (isCollision(directions, false, i + 1))
                    {
                        ret++;
                    }
                }
                else
                {
                    ;
                }
            }

            return ret;
        }
    };
} // namespace p_2211_weekly_285

/*
# Problem:
https://leetcode.com/problems/count-collisions-on-a-road/

## HINT:
* For each car, find isCollision on right side or left side.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/