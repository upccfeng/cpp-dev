#include "assert.h"
#include <vector>
#include <algorithm>
#include <cmath>

namespace p_218
{
    class MyHeap
    {
    private:
        std::vector<int> elements;
        std::vector<int> cnts;
        int last;

        int _getSize()
        {
            return last;
        }

        bool _isKeyBigger(int lhs, int rhs)
        {
            return lhs > rhs;
        }

        bool _isBetterByPos(int lhs_pos, int rhs_pos)
        {
            // return _isKeySmaller(elements[lhs_pos], elements[rhs_pos]);
            return _isKeyBigger(elements[lhs_pos], elements[rhs_pos]);
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

                if (_isBetterByPos(pos, parent_pos))
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
                        if (_isBetterByPos(left_pos, right_pos))
                        {
                            min_value_pos = left_pos;
                        }
                        else
                        {
                            min_value_pos = right_pos;
                        }
                    }
                }

                if (_isBetterByPos(min_value_pos, pos))
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

        MyHeap() : elements(1), cnts(1), last(0) {};

        void push(int val)
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

                _adjustToUp(pos);
            }
        }

        void removeValue(int value, bool remove_all = false)
        {
            int pos = _findPos(value);

            if (pos != -1)
            {
                if (cnts[pos] == 1 || remove_all)
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

                    _adjustToDown(pos);
                }
            }
        }

        void pop(bool remove_all)
        {
            if (_getSize() != 0)
            {
                removeValue(elements[0], remove_all);
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

        int* top()
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
        std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings)
        {
            std::vector<std::pair<int, int>> events;

            for (const auto& building : buildings)
            {
                events.push_back({ building[0], building[2] });  // enter event
                events.push_back({ building[1], -building[2] }); // leave event, negitive means leave
            }

            std::sort(events.begin(), events.end(), [](const auto& lhs, const auto& rhs) {

                if (lhs.first == rhs.first)
                {
                    return lhs.second > rhs.second; // The enter event should be first
                }

                return lhs.first < rhs.first;
                });

            MyHeap myheap;

            myheap.push(0);

            std::vector<std::vector<int>> ret;
            for (auto& e : events)
            {
                int height = e.second;
                int pos = e.first;

                if (height > 0)
                {
                    // enter event
                    if (height > *myheap.top())
                    {
                        ret.push_back({ pos, height });
                    }

                    myheap.push(height);
                }
                else
                {
                    // leave event
                    height = -height;

                    myheap.removeValue(height);

                    if (height > *myheap.top())
                    {
                        ret.push_back({ pos, *myheap.top() });
                    }
                }

            }

            return ret;
        }
    };
} // namespace p_218

/*
# Problem:
https://leetcode.com/problems/the-skyline-problem/

## HINT:
* While getting a higher building, record the node
* While removing a building, check the height is higher than seocnd, if yes, record the node.
* Use priority_queue(heap), but need to support remove particular elements
* For removing value, use a hash map to record the position can sppeed up.

## Time Complexity:
BigO(n * n)

## Space Complexity:
BigO(n)
*/