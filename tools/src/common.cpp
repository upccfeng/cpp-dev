#include "common.hpp"
#include "math.h"
using namespace common;

TreeNode* TreeNode::makeTree(const std::vector<int>& target, const std::vector<bool>& valid, const int level)
{
    int node_cnt = 0;
    for (int l = 0; l < level; ++l)
    {
        node_cnt += pow(2, l);
    }

    TreeNode* head = new TreeNode[node_cnt];

    for (int taking = 0; taking < target.size(); ++taking)
    {
        if (valid[taking])
        {
            head[taking].val = target[taking];

            if (taking * 2 + 1 < target.size())
            {
                if (valid[taking * 2 + 1])
                    head[taking].left = &head[taking * 2 + 1];
                if (valid[taking * 2 + 2])
                    head[taking].right = &head[taking * 2 + 2];
            }
        }
    }

    return head;
}

void TreeNode::freeTree(TreeNode* head)
{
    delete[] head;
}
