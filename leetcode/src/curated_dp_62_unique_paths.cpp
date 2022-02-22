#include <map>

namespace p_curated_dp_62_unique_paths
{
    class Solution
    {
        // If want to use unordered_map, need to implement hash function.
        std::map<std::pair<int, int>, int> cache;

        int get_path_count(int m, int n, int m_pos, int n_pos)
        {
            std::pair<int, int> key = std::make_pair(m_pos, n_pos);

            if (m_pos == m - 1 && n_pos == n - 1)
            {
                return 1;
            }
            else if (m_pos == m - 1)
            {
                if (cache.find(key) == cache.end())
                {
                    cache[key] = get_path_count(m, n, m_pos, n_pos + 1);
                }
            }
            else if (n_pos == n - 1)
            {
                if (cache.find(key) == cache.end())
                {
                    cache[key] = get_path_count(m, n, m_pos + 1, n_pos);
                }
            }
            else
            {
                if (cache.find(key) == cache.end())
                {
                    cache[key] = get_path_count(m, n, m_pos, n_pos + 1) + get_path_count(m, n, m_pos + 1, n_pos);
                }
            }

            return cache[key];
        }

    public:
        int uniquePaths(int m, int n)
        {
            return get_path_count(m, n, 0, 0);
        }
    };
} // namespace p_curated_dp_62_unique_paths

/*
# Problem:
https://leetcode.com/problems/unique-paths/

## HINT:
* get_paths(i, j) =
                    if i < m - 1 && j < n - 1       get_paths(i, j + 1) + get_paths(i + 1, j).
                    if i < m - 1 && j == n - 1      get_paths(i + 1, j).
                    if i == m - 1 && j < n - 1      get_paths(i, j + 1)
                    else                            1
* Use cache to speed up.
* If want to use std::pair<int, int> or other structure as key in unordered_map, need to implement the hash function for this key.

## Time Complexity:
BigO(m * n)

## Space Complexity:
BigO(m * n)
*/