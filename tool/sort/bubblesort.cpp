#include "sort.hpp"

void SortFunc::bubblesort(std::vector<int> &target)
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