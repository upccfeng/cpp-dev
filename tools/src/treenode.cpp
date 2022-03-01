#include "treenode.hpp"
#include "math.h"
#include <memory>

TreeNode* TreeHelper::create(const std::vector<int>& target, const std::vector<bool>& valid)
{
    std::vector<TreeNode*> nodes(target.size());
    for (auto& n : nodes)
    {
        n = new TreeNode();
    }

    for (int taking = 0; taking < target.size(); ++taking)
    {
        bool is_valid = true;

        if (valid.size() != 0)
        {
            is_valid = valid[taking];
        }

        if (is_valid)
        {
            nodes[taking]->val = target[taking];

            if (taking * 2 + 1 < target.size())
            {
                bool is_left_valid = true;
                if (valid.size() != 0)
                {
                    is_left_valid = taking * 2 + 1 < target.size() && valid[taking * 2 + 1];
                }
                if (taking * 2 + 1 < target.size() && is_left_valid)
                {
                    nodes[taking]->left = nodes[taking * 2 + 1];
                }

                bool is_right_valid = true;
                if (valid.size() != 0)
                {
                    is_right_valid = taking * 2 + 2 < target.size() && valid[taking * 2 + 2];
                }
                if (taking * 2 + 2 < target.size() && is_right_valid)
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

    return nodes.size() == 0 ? nullptr : nodes[0];
}

bool TreeHelper::isTheSame(TreeNode* p, TreeNode* q)
{
    if (p != nullptr && q != nullptr)
    {
        if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isTheSame(p->left, q->left) && isTheSame(p->right, q->right);
        }
    }
    else
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool TreeHelper::compare(TreeNode* lhs, TreeNode* rhs)
{
    return isTheSame(lhs, rhs);
}

bool TreeHelper::compare(TreeNode* lhs, std::pair<std::vector<int>, std::vector<bool>>& rhs_p)
{
    std::shared_ptr<TreeNode> rhs = std::shared_ptr<TreeNode>(TreeHelper::create(rhs_p.first, rhs_p.second), TreeHelper::remove);
    return compare(lhs, rhs.get());
}

void TreeHelper::remove(TreeNode* head)
{
    // FIXME: free it which bfs or dfs.
}
