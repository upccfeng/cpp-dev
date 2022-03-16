#include "treenode.hpp"
#include "assert.h"
#include <vector>

namespace p_236
{
    class Solution
    {

        bool dfs(std::vector<TreeNode*>& ans, std::vector<TreeNode*>& path, TreeNode* root, TreeNode* target)
        {
            if (root == nullptr)
            {
                return false;
            }

            path.push_back(root);

            if (root == target)
            {
                ans = path;
                path.pop_back();
                return true;
            }

            bool ret = false;

            ret |= dfs(ans, path, root->left, target);
            if (!ret)
            {
                ret |= dfs(ans, path, root->right, target);
            }

            path.pop_back();

            return ret;
        }

    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            std::vector<TreeNode*> path;
            bool found = false;

            std::vector<TreeNode*> path_p;
            found = dfs(path_p, path, root, p);

            assert(found == true);

            std::vector<TreeNode*> path_q;
            found = dfs(path_q, path, root, q);

            assert(found == true);

            int i = 0;
            while (i < path_p.size() && i < path_q.size())
            {
                if (path_p[i] != path_q[i])
                {
                    assert(i > 0);
                    return path_p[i - 1];
                }

                i++;
            }

            if (i == path_p.size())
            {
                return path_p[i - 1];
            }
            else if (i == path_q.size())
            {
                return path_q[i - 1];
            }
            else
            {
                return nullptr;
            }
        }
    };
} // namespace p_236

/*
# Problem:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

## HINT:
* dfs the node and record the path for each target.
* Return the last the same node.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(log(n))
*/