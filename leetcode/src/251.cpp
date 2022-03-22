#include "assert.h"
#include <vector>

namespace p_251
{
    class Vector2D
    {
        std::vector<int> data;
        int size;
        std::vector<int>::iterator iter;

    public:
        Vector2D(std::vector<std::vector<int>>& vec)
        {
            size = 0;
            for (auto& v : vec)
            {
                size += v.size();
            }

            data.resize(size);


            int i = 0;
            for (auto& v : vec)
            {
                for (int e : v)
                {
                    data[i++] = e;
                }
            }

            iter = data.begin();
        }

        int next()
        {
            return *iter++;
        }

        bool hasNext()
        {
            if (iter != data.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
} // namespace p_251

/*
# Problem:
https://leetcode.com/problems/flatten-2d-vector/

## HINT:

## Time Complexity:
init: BigO(n)
next: BigO(1)
hasNext: BigO(1)

## Space Complexity:
BigO(n)
*/