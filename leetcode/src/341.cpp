#include "assert.h"
#include <vector>

namespace p_341
{

    // This is the interface that allows for creating nested lists.
    // You should not implement it, or speculate about its implementation
    class NestedInteger {
        bool is_int;
        int value;
        std::vector<NestedInteger> nested;

    public:
        NestedInteger(int value) : is_int(true), value(value), nested() {}
        NestedInteger(std::vector<NestedInteger> nested) : is_int(false), value(0), nested(nested) {}


        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const
        {
            return is_int;
        }

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const
        {
            return value;
        }

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const std::vector<NestedInteger>& getList() const
        {
            return nested;
        }
    };

    class NestedIterator
    {
        std::vector<int> flat;
        int size;
        int iter;

        void flatten(const std::vector<NestedInteger>& nestedList)
        {
            for (auto& nested : nestedList)
            {
                if (nested.isInteger())
                {
                    flat.push_back(nested.getInteger());
                    size++;
                }
                else
                {
                    flatten(nested.getList());
                }
            }
        }

    public:
        NestedIterator(std::vector<NestedInteger>& nestedList)
        {
            size = 0;
            flatten(nestedList);

            iter = 0;
        }

        int next()
        {
            return flat[iter++];
        }

        bool hasNext()
        {
            return iter < size;
        }
    };
} // namespace p_341

/*
# Problem:
https://leetcode.com/problems/flatten-nested-list-iterator/

## HINT:
* Just implement the recursive init.

## Time Complexity:
Init: BigO(n)
next & hasNext: BigO(1)

## Space Complexity:
BigO(n)
*/