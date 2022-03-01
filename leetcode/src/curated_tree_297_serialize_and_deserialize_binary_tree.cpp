#include "treenode.hpp"
#include <vector>
#include <string>
#include <sstream>

namespace p_curated_tree_297_serialize_and_deserialize_binary_tree
{
    class Codec
    {
        int getElementAndMovePos(const std::string& s, int& pos)
        {
            if (pos >= s.size())
            {
                return -9999;
            }

            int val = 0;

            if (s[pos] == 'n')
            {
                pos = pos + 2;
                return -9999;
            }

            bool is_negitive = false;

            while (s[pos] != ',' && pos < s.size())
            {
                if (s[pos] == '-')
                {
                    is_negitive = true;
                    ++pos;
                    continue;
                }

                val = val * 10 + s[pos] - '0';

                ++pos;
            }

            ++pos; // ship ','
            return is_negitive ? -val : val;
        }

        TreeNode* createTree(std::string& data, int& pos)
        {
            if (pos >= data.size())
            {
                return nullptr;
            }

            int val = getElementAndMovePos(data, pos);

            if (val == -9999) // null
            {
                return nullptr;
            }
            else
            {
                TreeNode* taking = new TreeNode(val);

                taking->left = createTree(data, pos);
                taking->right = createTree(data, pos);

                return taking;
            }
        }

        void printPreOrder(std::vector<std::string>& s_list, TreeNode* root)
        {
            if (root == nullptr)
            {
                //s_list.push_back("n");
                s_list.emplace_back("n");
                return;
            }

            //s_list.push_back(std::to_string(root->val));
            s_list.emplace_back(std::to_string(root->val));

            printPreOrder(s_list, root->left);
            printPreOrder(s_list, root->right);
        }

    public:
        TreeNode* deserialize(std::string data)
        {
            if (data.size() == 0)
            {
                return nullptr;
            }

            int pos = 0;
            TreeNode* head = createTree(data, pos);

            return head;
        }

        std::string serialize(TreeNode* root)
        {
            std::vector<std::string> s_list;

            printPreOrder(s_list, root);

            std::stringstream ss;

            for (int pos = 0; pos < s_list.size(); ++pos)
            {
                ss << s_list[pos];

                if (pos != s_list.size() - 1)
                {
                    ss << ',';
                }
            }

            return ss.str();
        }
    };
} // namespace p_curated_tree_297_serialize_and_deserialize_binary_tree

/*
# Problem:
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

## HINT:
* Use pre-order dfs to serialize tree.
* Use ',' to split each data, and 'n' represented nullptr.
* Use mid-left-right order to deserialize the string to tree.
* Be careful of negative value and moving position.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/