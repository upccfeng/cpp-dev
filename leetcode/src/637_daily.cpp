#include <stack>
using namespace std;

#include "treenode.hpp"

namespace p637_daily
{
    class Solution
    {
    public:
        vector<double> averageOfLevels(TreeNode* root)
        {
            vector<double> ret;
            vector<int> cnt;
            int current_level = 0;
            TreeNode* taking = root;

            stack<pair<TreeNode*, int>> previous_level;

            while(taking)
            {
                if (current_level >= ret.size())
                {
                    ret.emplace_back(taking->val);
                    cnt.emplace_back(1);
                }
                else
                {
                    ret[current_level] += taking->val;
                    ++cnt[current_level];
                }

                if (taking->left != nullptr)
                {
                    previous_level.push(std::make_pair(taking, current_level));
                    taking = taking->left;
                    ++current_level;
                }
                else if (taking->right != nullptr)
                {
                    taking = taking->right;
                    ++current_level;
                }
                else
                {
                    bool next = false;
                    while (!previous_level.empty())
                    {
                        auto tmp = previous_level.top();
                        previous_level.pop();
                        current_level = tmp.second;

                        if (tmp.first->right)
                        {
                            next = true;
                            taking = tmp.first->right;
                            ++current_level;
                            break;
                        }
                    }

                    if (!next && previous_level.empty())
                        break;
                }
            }


            for (int i = 0; i < ret.size(); ++i)
            {
                ret[i] /= cnt[i];
            }

            return ret;
        }
    };
} // namespace p637_daily

/*
# Problem:

https://leetcode.com/problems/average-of-levels-in-binary-tree/

## HINT:

Traversal the tree, and record the total and count of ever level.

## Algorithm:

```
ret = {}
cnt = {}
current_level = 0
TreeNode* taking = root
previous_level;

while(taking)
{
    if current_level >= ret.size():
        ret.append(taking->val)
        cnt.append(1)
    else:
        ret[current_level] += taking->val
        ++cnt[current_level]

    if taking->left != nullptr:
        previous_level.append({taking, current_level})
        taking = taking->left
        ++current_level
    elif taking->right != nullptr:
        taking = taking->right
        ++current_level
    else:
        next = false
        while !previous_level.empty():
            tmp = previous_level.top()
            previous_level.pop()
            current_level = tmp.second

            if tmp.first->right:
                next = true
                taking = tmp.first->right
                ++current_level
                break

        if !next and previous_level.empty():
            break;

for i in range(0, ret.size()):
    ret[i] /= cnt[i]

return ret
```

## Time Complexity:
O(log n)

## Space Complexity:
O(log n): hight of tree
*/