#include "sort.hpp"

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

void SortTools::quicksort(std::vector<int> &target, int leftp, int rightp)
{
    int middle = target[leftp];
    int i = leftp + 1;
    int j = rightp;
    while (true)
    {
        for (i; i <= rightp; i++)
        {
            if (target[i] > middle)
            {
                break;
            }
        }
        for (j; j > leftp; j--)
        {
            if (target[j] < middle)
            {
                break;
            }
        }
        if (i < j)
        {
            std::swap(target[i], target[j]);
            i++;
            j--;
        }
        else
        {
            std::swap(target[leftp], target[j]);
            if (j - leftp > 1)
                quicksort(target, leftp, j - 1);
            if (rightp - j > 1)
                quicksort(target, j + 1, rightp);
            break;
        }
    }
}