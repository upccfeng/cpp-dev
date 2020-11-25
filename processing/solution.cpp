#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
    std::map<char, int> last_map;
public:
    // https://leetcode.com/problems/partition-labels/
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
            /*
            * if iter == goal:
            *     do something
            * if last_map[S[iter]] > goal:
            *     goal = last_map[S[iter]]
            * iter++
            */
        }
        return ans;
    }
};