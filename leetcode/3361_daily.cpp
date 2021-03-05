#include <stack>
using namespace std;

#include "common.hpp"
using namespace common;

namespace p3661_daily
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

            stack<pair<TreeNode*, bool>> previous;

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
                    previous.push(std::make_pair(taking, true));
                    taking = taking->left;
                    ++current_level;
                }
                else if (taking->right != nullptr)
                {
                    previous.push(std::make_pair(taking, false));
                    taking = taking->right;
                    ++current_level;
                }
                else
                {
                    while (!previous.empty())
                    {
                        auto tmp = previous.top();
                        previous.pop();
                        --current_level;

                        if (tmp.second && tmp.first->right)
                        {
                            previous.push(std::make_pair(tmp.first, false));
                            taking = (tmp.first)->right;
                            ++current_level;
                            break;
                        }
                    }

                    if (previous.empty())
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
} // namespace p3661_daily

/*
# Problem:

https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3661/

## HINT:

## Algorithm:

## Time Complexity:

## Space Complexity:
*/