#include "sort.hpp"
void SortFunc::quicksort(std::vector<int> &target, int leftp, int rightp)
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