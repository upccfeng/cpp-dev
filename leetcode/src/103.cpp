#include "treenode.hpp"
#include <vector>

namespace p_103
{
    class Solution
    {
        void dfs(TreeNode* root, std::vector<std::vector<int>>& ret, int level)
        {
            if (root == nullptr)
            {
                return;
            }

            if (ret.size() < level)
            {
                ret.resize(level);
            }

            ret[level - 1].push_back(root->val);
            dfs(root->left, ret, level + 1);
            dfs(root->right, ret, level + 1);
        }

    public:
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
            std::vector<std::vector<int>> ret;

            dfs(root, ret, 1);

            for (int i = 0; i < ret.size(); i++)
            {
                if (i % 2 == 1)
                {
                    std::reverse(ret[i].begin(), ret[i].end());
                }
            }

            return ret;
        }
    };
} // namespace p_103

/*
# Problem:
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

## HINT:
* DFS with level info
* reverse the odd level list

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/