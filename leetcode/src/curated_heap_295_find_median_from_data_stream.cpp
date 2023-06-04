#include <vector>
#include <queue>

namespace p_curated_heap_295_find_median_from_data_stream
{
    class MedianFinder {
        std::priority_queue<int, std::vector<int>, std::less<int>> left_pq;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right_pq;

    public:
        MedianFinder()
        {

        }

        void balancePriorityQueues()
        {
            // The max times of these loop is two.
            while ((int)left_pq.size() - (int)right_pq.size() < -1 ||
                (int)left_pq.size() - (int)right_pq.size() > 1 ||
                (left_pq.size() > 0 && right_pq.size() > 0 && left_pq.top() > right_pq.top()) /*||
                (left_pq.size() > 0 && right_pq.size() > 0 && right_pq.top() < left_pq.top())*/)
            {
                if ((int)left_pq.size() - (int)right_pq.size() < -1)
                {
                    left_pq.push(right_pq.top());
                    right_pq.pop();

                    continue;
                }

                if ((int)left_pq.size() - (int)right_pq.size() > 1)
                {
                    right_pq.push(left_pq.top());
                    left_pq.pop();

                    continue;
                }

                if (left_pq.size() > 0 && right_pq.size() > 0 && left_pq.top() > right_pq.top())
                {
                    right_pq.push(left_pq.top());
                    left_pq.pop();

                    continue;
                }

                // No need, this case will be covered by previous "three".
                //if (left_pq.size() > 0 && right_pq.size() > 0 && right_pq.top() < left_pq.top())
                //{
                //    left_pq.push(right_pq.top());
                //    right_pq.pop();

                //    continue;
                //}
            }

        }

        void addNum(int num)
        {
            left_pq.push(num);

            balancePriorityQueues();
        }

        double findMedian()
        {
            if ((left_pq.size() + right_pq.size()) % 2 == 0)
            {
                return (double(left_pq.top()) + double(right_pq.top())) / 2;
            }
            else
            {
                if (left_pq.size() > right_pq.size())
                {
                    return double(left_pq.top());
                }
                else
                {
                    return double(right_pq.top());
                }
            }
        }
    };
} // namespace p_curated_heap_295_find_median_from_data_stream

/*
# Problem:
https://leetcode.com/problems/find-median-from-data-stream/

## HINT:
* Use two Heaps to record mid-left and mid-right.
* Make sure the count diff between these two is less than 2 in order to get mid in BigO(1).
* Once the count diff between these two is 0, return (mid-left.top + mid-right.top) / 2
* Once the count diff between these two is 1, return mid-Bigger.top
* Always make these two heaps meat below conditions:
* - | mid-left.size() - mid-right.size() | <= 1
* - mid-left.top < mid-right.top
* - mid-right.top > mid-left.top           P.S. No need, it will be covered by previous two condition

## Time Complexity:
Insert: BigO(log(n))
GetMid: BigO(1)

## Space Complexity:
BigO(n)
*/