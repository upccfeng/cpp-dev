#include "treenode.hpp"
#include "math.h"

TreeNode* TreeHelper::create(const std::vector<int>& target, const std::vector<bool>& valid)
{
    //int node_cnt = 0;
    //for (int l = 0; l < level; ++l)
    //{
    //    node_cnt += pow(2, l);
    //}

    std::vector<TreeNode*> nodes(target.size());
    for (auto& n : nodes)
    {
        n = new TreeNode();
    }

    for (int taking = 0; taking < target.size(); ++taking)
    {
        if (valid[taking])
        {
            nodes[taking]->val = target[taking];

            if (taking * 2 + 1 < target.size())
            {
                if (taking * 2 + 1 < target.size() && valid[taking * 2 + 1])
                {
                    nodes[taking]->left = nodes[taking * 2 + 1];
                }
                if (taking * 2 + 2 < target.size() && valid[taking * 2 + 2])
                {
                    nodes[taking]->right = nodes[taking * 2 + 2];
                }
            }
        }
        else
        {
            delete nodes[taking];
        }
    }

    return nodes[0];
}

void TreeHelper::remove(TreeNode* head)
{
    // FIXME: free it which bfs or dfs.
}
