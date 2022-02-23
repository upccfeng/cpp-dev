#include <set>
#include <unordered_map>

namespace p_curated_graph_207_course_schedule
{
    class Solution
    {
        std::unordered_map<int, bool> cache;

        bool isCircle(int numCourses, int taking, std::unordered_map<int, std::set<int>>& edges, std::vector<bool>& discovered)
        {
            if (discovered[taking])
            {
                return true;
            }
            else
            {
                if (cache.find(taking) != cache.end())
                {
                    return cache[taking];
                }

                // Another method for avoiding redundant executions.
                // if (edges.size() == 0)
                // {
                //    return false;
                // }

                discovered[taking] = true;

                cache[taking] = false;

                for (auto e : edges[taking])
                {
                    if (isCircle(numCourses, e, edges, discovered))
                    {
                        cache[taking] = true;
                        break;
                        // return true;
                    }
                }

                discovered[taking] = false;

                return cache[taking];
                // edges[taking].clear();
                // return false;
            }
        }
    public:
        bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            std::unordered_map<int, std::set<int>> edges;

            // BigO(n)
            for (const auto& relate : prerequisites)
            {
                if (relate[0] == relate[1])
                {
                    return false;
                }

                edges[relate[0]].insert(relate[1]);
            }

            std::vector<bool> discovered(numCourses, false);

            // BigO(n) * (BigO(n) + BigO(E))
            for (int start = 0; start < numCourses; ++start)
            {
                if (isCircle(numCourses, start, edges, discovered))
                {
                    return false;
                }
            }

            return true;
        }
    };
} // namespace p_curated_graph_207_course_schedule

/*
# Problem:
https://leetcode.com/problems/course-schedule/

## HINT:
* If there is a cycle in prerequisites, it is impossible to complete all courses.
* Start from all nodes to find is there a cycle or not.
* Avoid redundant executions by caching or removing used edges.

## Time Complexity:
BigO(n * (n + E))

## Space Complexity:
BigO(n + E)
*/