#include <iostream>
#include <vector>

#include "../sort/sort.hpp"

using namespace std;

// [0,11,6,1,4,3]
// [5,4,11,10,1,0]
//5

//7,6,3,0,3
//9
//

//[5,16,19,2,1,12,7,14,5,16]
//[6,17,4,3,6,13,4,3,18,17,16,7,14,1,16]
//8
// vector<int> arr1 = {5, 16, 19, 2, 1, 12, 7, 14, 5, 16};
// vector<int> arr2 = {6, 17, 4, 3, 6, 13, 4, 3, 18, 17, 16, 7, 14, 1, 16};
// Solution s;
// int ans = s.makeArrayIncreasing(arr1, arr2);
// cout << ans << endl;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int ans = 0;
        quicksort(arr2, 0, arr2.size() - 1);

        for (int i = 1; i < arr1.size(); i++)
        {
            if (arr1[i] <= arr1[i - 1])
            {
                int original = arr1[i];
                if (change_pre(arr1, arr2, i))
                {
                    ans++;
                    arr1[i] = original;
                    if (arr1[i] <= arr1[i - 1])
                    {
                        if (change_self(arr1, arr2, i))
                        {
                            ans++;
                            i++;
                        }
                        else
                        {
                            return -1;
                        }
                    }
                }
                else if (change_self(arr1, arr2, i))
                {
                    ans++;
                }
                else
                {
                    return -1;
                }
            }
        }
        for (int i = 1; i < arr1.size(); i++)
        {
            if (arr1[i] <= arr1[i - 1])
                ans = -1;
        }
        return ans;
    }
    bool change_self(vector<int> &arr1, vector<int> &arr2, int pos)
    {
        for (int i = 0; i < arr2.size(); i++)
        {
            if (arr2[i] > arr1[pos - 1])
            {
                arr1[pos] = arr2[i];
                return true;
            }
        }
        return false;
    }
    bool change_pre(vector<int> &arr1, vector<int> &arr2, int pos)
    {
        for (int i = 0; i < arr2.size(); i++)
        {
            if (pos > 1 && arr2[i] > arr1[pos - 2])
            {
                arr1[pos - 1] = arr2[i];
                arr1[pos] = arr2[i] + 1;
                return true;
            }
        }
        return false;
    }
    void quicksort(std::vector<int> &target, int leftp, int rightp)
    {
        if (leftp == rightp)
        {
            return;
        }
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
};