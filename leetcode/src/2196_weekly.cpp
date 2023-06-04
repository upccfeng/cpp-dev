#include "treenode.hpp"
#include <unordered_map>

namespace p_2196_weekly
{
    class Solution
    {
        TreeNode* createNode(std::unordered_map<int, std::pair<std::pair<bool, TreeNode*>, std::pair<TreeNode*, TreeNode*>>>& map, int target)
        {
            if (map.find(target) == map.end())
            {
                map[target] = { {false, new TreeNode(target)}, {nullptr, nullptr} };

                return map[target].first.second;
            }
            else
            {
                return map[target].first.second;;
            }
        }

    public:
        TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions)
        {
            std::unordered_map<int, std::pair<std::pair<bool, TreeNode*>, std::pair<TreeNode*, TreeNode*>>> map;

            for (auto& d : descriptions)
            {
                TreeNode* child = createNode(map, d[1]);
                TreeNode* parent = createNode(map, d[0]);

                map[d[1]].first.first = true;
                if (d[2] == 1)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
            }

            for (auto& kv : map)
            {
                if (kv.second.first.first == false)
                {
                    return kv.second.first.second;
                }
            }

            return nullptr;
        }
    };
}

/*
# Problem:
https://leetcode.com/problems/create-binary-tree-from-descriptions/

## HINT:
* Record the number, is_parent, left, right in a hash.
* Create the node and child for each element.
* Mark the node as parent or not.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/