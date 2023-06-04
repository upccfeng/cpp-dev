#include "treenode.hpp"
#include "math.h"
#include <memory>
#include <queue>

int TreeHelper::readStringTil(const std::string& str, int& pos, char end_char)
{
    int value = 0;
    int sign = 1;

    if (pos >= str.size())
    {
        return -999999;
    }

    while (pos < str.size() && str[pos] != ',')
    {
        if (str[pos] == '-')
        {
            sign = -1;
        }
        else if (str[pos] == 'n')
        {
            value = -999999; // assert min value is greater than -999999

            pos = pos + 4;
            break;
        }
        else
        {
            value = value * 10 + str[pos] - '0';
        }

        pos++;
    }

    pos++;
    return value * sign;
}

TreeNode* TreeHelper::create(const std::string& str)
{
    if (str == "")
    {
        return nullptr;
    }
    
    int pos = 0;
    int value = readStringTil(str, pos, ',');

    TreeNode* head = new TreeNode(value);
    TreeNode* taking = head;

    std::queue<TreeNode*> queue;

    while (pos < str.size())
    {
        int left_value = readStringTil(str, pos, ',');
        int right_value = readStringTil(str, pos, ',');

        if (left_value != -999999)
        {
            taking->left = new TreeNode(left_value);
            queue.push(taking->left);
        }

        if (right_value != -999999)
        {
            taking->right = new TreeNode(right_value);
            queue.push(taking->right);
        }

        if (!queue.empty())
        {
            taking = queue.front();
            queue.pop();
        }
        else
        {
            break;
        }
    }

    return head;
}

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

void TreeHelper::dfsWithValue(std::vector<TreeNode*>& ret, TreeNode* root, int target)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->val == target)
    {
        ret.push_back(root);
    }

    dfsWithValue(ret, root->left, target);
    dfsWithValue(ret, root->right, target);
}


std::vector<TreeNode*> TreeHelper::findElements(TreeNode* head, int target)
{
    std::vector<TreeNode*> ret;

    dfsWithValue(ret, head, target);

    return ret;
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
