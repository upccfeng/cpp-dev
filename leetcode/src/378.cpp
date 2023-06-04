#include "assert.h"
#include <vector>
#include <algorithm>

namespace p_378
{
    class Solution
    {
        int get_row(int N, int target)
        {
            return target / N;
        }

        int get_col(int N, int target)
        {
            return target % N;
        }

        int quickSelect(std::vector<std::vector<int>>& matrix, int N, int k, int left, int right)
        {
            int mid = (left + right) / 2;
            std::swap(matrix[get_row(N, mid)][get_col(N, mid)], matrix[get_row(N, left)][get_col(N, left)]);

            int pivot_pos = left;
            int pivot = matrix[get_row(N, pivot_pos)][get_col(N, pivot_pos)];

            int l = left + 1;
            int r = right;

            while (l < r)
            {
                while (l < r && matrix[get_row(N, l)][get_col(N, l)] <= pivot)
                {
                    l++;
                }

                while (l < r && matrix[get_row(N, r)][get_col(N, r)] >= pivot)
                {
                    r--;
                }

                if (l < r)
                {
                    std::swap(matrix[get_row(N, l)][get_col(N, l)], matrix[get_row(N, r)][get_col(N, r)]);
                }
            }

            l--; // If move left first and move from left + 1, the position "l - 1" will guarantee the left side are all smaller than pivot. 
            std::swap(matrix[get_row(N, l)][get_col(N, l)], matrix[get_row(N, pivot_pos)][get_col(N, pivot_pos)]);

            if (k > l + 1)
            {
                return quickSelect(matrix, N, k, l + 1, right);
            }
            else if (k < l + 1)
            {
                return quickSelect(matrix, N, k, left, l);
            }
            else
            {
                return matrix[get_row(N, l)][get_col(N, l)];
            }
        }

        int quickSelectMoveRightFirst(std::vector<std::vector<int>>& matrix, int N, int k, int left, int right)
        {
            int pivot_pos = left;
            int pivot = matrix[get_row(N, pivot_pos)][get_col(N, pivot_pos)];

            int l = left;
            int r = right;

            while (l < r)
            {
                while (l < r && matrix[get_row(N, r)][get_col(N, r)] >= pivot)
                {
                    r--;
                }

                while (l < r && matrix[get_row(N, l)][get_col(N, l)] <= pivot)
                {
                    l++;
                }

                if (l < r)
                {
                    std::swap(matrix[get_row(N, l)][get_col(N, l)], matrix[get_row(N, r)][get_col(N, r)]);
                }
            }

            std::swap(matrix[get_row(N, l)][get_col(N, l)], matrix[get_row(N, pivot_pos)][get_col(N, pivot_pos)]);

            if (k > l + 1)
            {
                return quickSelect(matrix, N, k, l + 1, right);
            }
            else if (k < l + 1)
            {
                return quickSelect(matrix, N, k, left, l);
            }
            else
            {
                return matrix[get_row(N, l)][get_col(N, l)];
            }
        }


    public:
        int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
        {
            int N = matrix.size();

            return quickSelect(matrix, N, k, 0, N * N - 1);
        }
    };
} // namespace p_378

/*
# Problem:
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

## HINT:
* Use quick select.

## Time Complexity:
BigO(n * log(n))

## Space Complexity:
BigO(log(n * n))
*/