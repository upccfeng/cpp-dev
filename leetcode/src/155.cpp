#include "assert.h"
#include <limits.h>
#include <vector>

namespace p_155
{
    class MinStack
    {
        int size;
        std::vector<int> data;
        //std::vector<int> mins;

        int min_cache;

        int _findMin()
        {
            int min = INT_MAX;

            for (int i = 0; i < size; i++)
            {
                if (data[i] < min)
                {
                    min = data[i];
                }
            }

            return min;
        }

    public:
        MinStack() : size(0), data(1)/*, mins(1)*/, min_cache(INT_MAX) {}

        void push(int val)
        {
            if (size == data.size())
            {
                data.resize(data.size() * 2);
                //mins.resize(mins.size() * 2);
            }

            data[size] = val;
            //mins[size] = std::min(val, size - 1 < 0 ? INT_MAX : mins[size - 1]);

            if (val < min_cache)
            {
                min_cache = val;
            }

            size++;
        }

        void pop()
        {
            assert(size >= 0);
            size--;

            if (data[size] == min_cache)
            {
                min_cache = _findMin();
            }
        }

        int top()
        {
            assert(size >= 0);
            return data[size - 1];
        }

        int getMin()
        {
            return min_cache;
            //return mins[size - 1];
        }
    };
} // namespace p_155

/*
# Problem:
https://leetcode.com/problems/min-stack/

## HINT:
* Use cache or another spaces to record the min for each position.

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(n)
*/