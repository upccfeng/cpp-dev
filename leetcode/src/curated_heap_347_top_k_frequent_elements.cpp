#include <vector>
#include <queue>
#include <unordered_map>

namespace p_curated_heap_347_top_k_frequent_elements
{
    class Heap
    {
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
            return _isKeyBigger(cnts[lhs_pos], cnts[rhs_pos]);
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

                _adjustToUp(pos);
            }
        }

        void removeValue(int value, bool remove_all)
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

        void removeTop(bool remove_all)
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
        std::vector<int> topKFrequentHeap(std::vector<int>& nums, int k)
        {
            Heap heap;

            for (auto e : nums)
            {
                heap.insert(e);
            }

            std::vector<int> ret;
            for (int i = 0; i < k; ++i)
            {
                ret.emplace_back(*heap.getTopPtr());
                heap.removeTop(true);
            }
            return ret;
        }
        std::vector<int> topKFrequentPriorityQueue(std::vector<int>& nums, int k)
        {
            auto cmp = [](std::pair<int, int> lhs, std::pair<int, int> rhs) {
                return lhs.first < rhs.first; // The less-comparison will make max-heap, because the nodes will be less than the frontest one.
            };

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

            std::unordered_map<int, int> cnt_map;

            for (auto n : nums)
            {
                ++cnt_map[n];
            }

            for (auto& cnt : cnt_map)
            {
                pq.push({ cnt.second, cnt.first });
            }

            std::vector<int> ret;

            for (int i = 0; i < k; ++i)
            {
                ret.emplace_back(pq.top().second);
                pq.pop();
            }

            return ret;
        }

        std::vector<int> topKFrequent(std::vector<int>& nums, int k)
        {
            return topKFrequentPriorityQueue(nums, k);
        }

    };
} // namespace p_curated_heap_347_top_k_frequent_elements

/*
# Problem:
https://leetcode.com/problems/top-k-frequent-elements/

## HINT:
* Use Heap(Priority_Queue)
* Use std::priority_queue
* Max-Heap should use less comparion(std::less<int>).

## Time Complexity:
BigO(n * log(n));

## Space Complexity:
BigO(n)
*/