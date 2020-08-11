#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

class Solution
{
    int arraySize;

public:
    int newfindfindNextData(int now, vector<int> &ans, int *dataArray)
    {
        bitset<16> bits = now;
        for (int i = 0; i < 16; i++)
        {
            bits[i] = ~bits[i];
            int nowdata = int(bits.to_ulong());
            if (dataArray[nowdata] != -1)
            {
                ans.push_back(nowdata);
                dataArray[nowdata] = -1;
                return nowdata;
            }
            else
            {
                bits[i] = ~bits[i];
            }
        }
        return -1;
    }
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> ans;
        arraySize = pow(2, n);
        int dataArray[arraySize] = {0};

        ans.push_back(start);
        dataArray[start] = -1;
        int taking = start;
        while (ans.size() < arraySize)
        {
            taking = newfindfindNextData(taking, ans, dataArray);
        }

        // using Gray Code
        // start is one of Gray Code
        // run in sequence of pow(2, n)
        // B(i) xor (B(i) >> 1) == G(i), i is the current bit we process
        /*
        vector<int> ans;
        arraySize = pow(2, n);
        for (int i = 0; i < arraySize; i++)
        {
            ans.push_back(start ^ i ^ i >> 1); // start at "start" to generate gray code sequence
        }
        */
        return ans;
    }
};