#include <string>
#include <vector>
#include <map>

using namespace std;

namespace p763
{
    class Solution
    {
        std::map<char, int> last_map;

    public:
        vector<int> partitionLabels(string S)
        {
            for (int pos = 0; pos < S.size(); ++pos)
            {
                last_map[S[pos]] = pos;
            }
            int begin = 0;
            int iter = 0;
            int goal = last_map[S[0]];
            vector<int> ans;
            while (goal != S.size())
            {
                if (iter == goal)
                {
                    ans.emplace_back(goal - begin + 1);
                    begin = iter + 1;
                    if (begin < S.size())
                    {
                        goal = last_map[S[begin]];
                    }
                }

                if (iter == S.size())
                {
                    break;
                }

                if (last_map[S[iter]] > goal)
                {
                    goal = last_map[S[iter]];
                }
                ++iter;
            }
            return ans;
        }
    };
} // namespace p763

/*
Problem: https://leetcode.com/problems/partition-labels/

HINT:
use a map to record the rightest position for each char in target string.

Time Complexity: n*log(n) + n -> BIG_O(n*log(n))
std::map insert time complexity is BIG_O(log(n)). If use hash_map, the insert action clould reduce to BIG_O(1).

Space Complexity: BIG_O(1)
There are only 26 chars need to store.
*/