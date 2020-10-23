#include "sort_tools.hpp"

void SortTools::bubblesort(std::vector<int> &target)
{
    int target_size = target.size();
    int times = target_size;
    bool isSorted;
    while (times > 1)
    {
        isSorted = true;
        for (int i = 0; i < times - 1; i++)
        {
            if (target[i] > target[i + 1])
            {
                int temp;
                temp = target[i];
                target[i] = target[i + 1];
                target[i + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            break;
        times--;
    }
}

void SortTools::quicksort(std::vector<int> &target, int left_bound, int right_bound)
{
    if (right_bound - left_bound < 1)
    {
        return;
    }
    int middle = target[left_bound];
    int big_pos = left_bound + 1;
    int small_pos = right_bound;
    while (true)
    {
        for (big_pos; big_pos <= right_bound; big_pos++)
        {
            if(target[big_pos] > middle)
            {
                break;
            }
        }
        for (small_pos; small_pos > left_bound; small_pos--)
        {
            if(target[small_pos] < middle)
            {
                break;
            }
        }

        if (big_pos < small_pos)
        {
            std::swap(target[big_pos], target[small_pos]);
            big_pos++;
            small_pos--;
        }
        else
        {
            if (big_pos > right_bound)
                big_pos--;
            if (small_pos < left_bound)
                small_pos--;

            std::swap(target[left_bound], target[small_pos]);
            if (right_bound - small_pos > 1)
            {
                quicksort(target, small_pos + 1, right_bound);
            }
            if (small_pos - 1 - left_bound > 1)
            {
                quicksort(target, left_bound, small_pos - 1);
            }
            break;
        }
    }
}