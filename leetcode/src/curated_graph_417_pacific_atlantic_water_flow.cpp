#include <vector>
#include <set>

namespace p_curated_graph_417_pacific_atlantic_water_flow
{
    class Solution
    {
        bool isOutOfBoundary(const std::vector<std::vector<int>>& heights, int pos_i, int pos_j)
        {
            if (pos_i < 0 || pos_i >= heights.size())
            {
                return true;
            }

            if (pos_j < 0 || pos_j >= heights[pos_i].size())
            {
                return true;
            }

            return false;
        }

        void dfs(std::vector<std::vector<int>>& heights, int pos_i, int pos_j, std::set<std::pair<int, int>>& visited, int preHeight)
        {
            std::pair<int, int> position(pos_i, pos_j);
            if (visited.find(position) != visited.end() ||
                isOutOfBoundary(heights, pos_i, pos_j) ||
                heights[pos_i][pos_j] < preHeight)
            {
                return;
            }

            visited.insert(position);

            dfs(heights, pos_i + 1, pos_j, visited, heights[pos_i][pos_j]);
            dfs(heights, pos_i - 1, pos_j, visited, heights[pos_i][pos_j]);
            dfs(heights, pos_i, pos_j + 1, visited, heights[pos_i][pos_j]);
            dfs(heights, pos_i, pos_j - 1, visited, heights[pos_i][pos_j]);
        }

    public:
        std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
        {
            std::set<std::pair<int, int>> pacificReachable;
            std::set<std::pair<int, int>> atlanticReachable;

            int ROWS = heights.size();
            int COLS = heights[0].size();

            for (int pos = 0; pos < COLS; ++pos)
            {
                dfs(heights, 0, pos, pacificReachable, heights[0][pos]);
                dfs(heights, ROWS - 1, pos, atlanticReachable, heights[ROWS - 1][pos]);
            }

            for (int pos = 0; pos < ROWS; ++pos)
            {
                dfs(heights, pos, 0, pacificReachable, heights[pos][0]);
                dfs(heights, pos, COLS - 1, atlanticReachable, heights[pos][COLS - 1]);
            }

            std::vector<std::vector<int>> ans;

            for (int i = 0; i < heights.size(); ++i)
            {
                for (int j = 0; j < heights[i].size(); ++j)
                {
                    std::pair<int, int> key(i, j);
                    auto found_pac = pacificReachable.find(key) != pacificReachable.end();
                    auto found_atl = atlanticReachable.find(key) != atlanticReachable.end();

                    if (found_pac && found_atl)
                    {
                        ans.push_back(std::vector<int>({ i, j }));
                    }
                }
            }

            return ans;
        }
    };
} // namespace p_curated_graph_417_pacific_atlantic_water_flow

/*
# Problem:
https://leetcode.com/problems/pacific-atlantic-water-flow/

## HINT:
* Only travers the nodes which are close to mark the possible nodes for each sea.
* Use two set to record is it possbile to get to each sea.
* Traverse each point (i, j), if point(i, j) exists in both set, add to the ans.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/