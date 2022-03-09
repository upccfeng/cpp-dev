#include "assert.h"
#include "listnode.hpp"
#include <vector>

namespace p_curated_heap_23_merge_k_sorted_lists
{
    // The same as heap.cpp
    class Heap
    {
        std::vector<int> elements;
        std::vector<int> cnts;
        int last;

        int _getSize()
        {
            return last;
        }

        bool _isBetter(int lhs, int rhs)
        {
            return lhs < rhs;
        }

        void _adjustToUp(int pos)
        {
            if (pos == 0)
            {
                return;
            }
            else
            {
                int parent_pos = (pos + 1) / 2 - 1;
                //               ^^^^           ^^^   base 1
                if (_isBetter(elements[pos], elements[parent_pos]))
                {
                    int tmp = elements[pos];
                    elements[pos] = elements[parent_pos];
                    elements[parent_pos] = tmp;

                    tmp = cnts[pos];
                    cnts[pos] = cnts[parent_pos];
                    cnts[parent_pos] = tmp;

                    _adjustToUp(parent_pos);
                }
            }

            return;
        }

        void _adjustToDown(int pos)
        {
            if (pos >= last)
            {
                return;
            }
            else
            {
                int left_pos = (pos + 1) * 2 - 1;
                int right_pos = (pos + 1) * 2 + 1 - 1;

                int min_value_pos;
                if (left_pos >= _getSize())
                {
                    // there is no child
                    return;
                }
                else
                {
                    if (right_pos >= _getSize())
                    {
                        // only left_pos
                        min_value_pos = left_pos;
                    }
                    else
                    {
                        // there are two children
                        if (_isBetter(elements[left_pos], elements[right_pos]))
                        {
                            min_value_pos = left_pos;
                        }
                        else
                        {
                            min_value_pos = right_pos;
                        }
                    }
                }

                if (_isBetter(elements[min_value_pos], elements[pos]))
                {
                    int tmp = elements[pos];
                    elements[pos] = elements[min_value_pos];
                    elements[min_value_pos] = tmp;

                    tmp = cnts[pos];
                    cnts[pos] = cnts[min_value_pos];
                    cnts[min_value_pos] = tmp;

                    _adjustToDown(min_value_pos);
                }
            }

        }

        int _findPos(int value)
        {
            for (int i = 0; i < last; ++i)
            {
                if (elements[i] == value)
                {
                    return i;
                }
            }

            return -1;
        }

    public:

        Heap() : elements(1), cnts(1), last(0) {};

        void insert(int val)
        {
            int pos = _findPos(val);

            if (pos == -1)
            {
                if (_getSize() + 1 > elements.size())
                {
                    elements.resize(elements.size() * 2);
                    cnts.resize(cnts.size() * 2);
                }

                elements[last] = val;
                cnts[last] = 1;
                _adjustToUp(last);

                ++last;
            }
            else
            {
                ++cnts[pos];
            }
        }

        void removeValue(int value)
        {
            int pos = _findPos(value);

            if (pos != -1)
            {
                if (cnts[pos] == 1)
                {
                    elements[pos] = elements[last - 1];
                    cnts[pos] = cnts[last - 1];

                    elements[last - 1] = 0; // not necessary, just for visualize debug.
                    cnts[last - 1] = 0; // not necessary, just for visualize debug.
                    --last;

                    _adjustToDown(pos);
                }
                else
                {
                    assert(cnts[pos] > 1);
                    --cnts[pos];
                }
            }
        }

        void removeTop()
        {
            if (_getSize() != 0)
            {
                removeValue(elements[0]);
            }
        }

        int getValueCnt(int val)
        {
            int pos = _findPos(val);

            if (pos == -1)
            {
                return -1;
            }
            else
            {
                return cnts[pos];
            }
        }

        int* getTopPtr()
        {
            if (_getSize() == 0)
            {
                return nullptr;
            }
            else
            {
                return &elements[0];
            }
        }
    };

    class Solution
    {
    public:
        ListNode* mergeKLists(std::vector<ListNode*>& lists)
        {
            Heap heap;

            for (auto list : lists)
            {
                ListNode* taking = list;

                while (taking != nullptr)
                {
                    heap.insert(taking->val);

                    taking = taking->next;
                }
            }

            ListNode* root = nullptr;
            auto top = heap.getTopPtr();
            ListNode* taking = nullptr;
            while (top != nullptr)
            {
                if (root == nullptr)
                {
                    root = new ListNode(*top);
                    taking = root;
                }
                else
                {
                    taking->next = new ListNode(*top);
                    taking = taking->next;
                }

                heap.removeTop();
                top = heap.getTopPtr();
            }

            return root;
        }
    };
} // namespace p_curated_heap_23_merge_k_sorted_lists

/*
# Problem:
https://leetcode.com/problems/merge-k-sorted-lists/

## HINT:
* Create a heap by lists. The heap should record the cnt of value. Pop the Heap until empty.

## Time Complexity:
BigO(n * k * log(n))

## Space Complexity:
Big(n * k)
*/