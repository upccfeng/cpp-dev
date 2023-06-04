#include "assert.h"
#include <vector>
#include <set>

namespace p_210
{
    class Solution
    {
        bool isFinished(std::set<int>& dependency, std::vector<int>& visited, int target)
        {
            for (auto next : dependency)
            {
                if (!visited[next])
                {
                    return false;
                }
            }

            return true;
        }

        void dfs(int numCourses, std::vector<std::set<int>>& dependency, std::vector<int>& visited, std::vector<int>& path, int taking)
        {
            if (visited[taking] || path.size() == numCourses)
            {
                return;
            }

            visited[taking] = true;
            path.push_back(taking);

            for (int i = 0; i < numCourses; i++)
            {
                if (!visited[i] && isFinished(dependency[i], visited, i))
                {
                    dfs(numCourses, dependency, visited, path, i);
                }
            }
        }

    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            std::vector<std::set<int>> dependency(numCourses);

            // BigO(E)
            for (const auto& d : prerequisites)
            {
                dependency[d[0]].insert(d[1]);
            }


            std::vector<int> visited(numCourses, false);
            std::vector<int> path;

            // BigO(V * E)
            for (int i = 0; i < numCourses; i++)
            {
                if (dependency[i].empty())
                {
                    dfs(numCourses, dependency, visited, path, i);

                    if (path.size() == numCourses)
                    {
                        return path;
                    }

                    break;              // just need start at empty position once.
                }
            }

            return {};
        }
    };
} // namespace p_210

/*
# Problem:
https://leetcode.com/problems/course-schedule-ii/

## HINT:
* Using graphic concept and run dfs
* Method-2:
* To improve the speed, run dfs with cycle and visited to reach BigO(V + E)
* The condition for pushing element into ret is all the nexts for this vertex is visited (not cycle).
* Run from 0 -> n, and return empty list once there is cycle.

## Time Complexity:
BigO(V * E)

## Space Complexity:
BigO(V + E)
*/