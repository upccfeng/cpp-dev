#pragma once
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeHelper
{
private:
    static bool TreeHelper::isTheSame(TreeNode* p, TreeNode* q);
    static int TreeHelper::readStringTil(const std::string& str, int& pos, char end_char);

public:
    static TreeNode* create(const std::vector<int>& target, const std::vector<bool>& valid);
    static TreeNode* TreeHelper::create(const std::string& str);
    static void remove(TreeNode* head);
    static bool compare(TreeNode* lhs, TreeNode* rhs);
    static bool compare(TreeNode* lhs, std::pair<std::vector<int>, std::vector<bool>>& rhs);
};
