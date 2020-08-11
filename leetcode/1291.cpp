#include <iostream>
#include <vector>

using namespace std;

/*
#include "leetcode/contest_problem_solution/1291.cpp"

int main()
{
    Solution s;
    std::vector<int> ans = s.sequentialDigits(10, 1000000000);
    for(auto& e : ans)
    {
        std::cout << e << std::endl;
    }
}
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int taking = low;
        int count_low = 0;
        while(taking != 0) 
        {
            count_low++;
            taking /= 10;
        }
        taking = high;
        int count_high = 0;
        while(taking != 0) 
        {
            count_high++;
            taking /= 10;
        }
        vector<int> canidate = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ans;
        int last = 10;
        for(int count = count_low; count <= count_high; count++)
        {
            for(int start = 0; start < canidate.size(); start++)
            {
                int temp_ans = 0;
                for(int i = 0; i < count; i++)
                {
                    if(start + i < canidate.size())
                        temp_ans = temp_ans * 10 + canidate[start + i];
                    else
                        break;
                }
                if(temp_ans >= low && temp_ans <= high && temp_ans > last)
                {
                    ans.push_back(temp_ans);
                    last = temp_ans;
                }       
                
                if(temp_ans > high)
                    break;
            }
        }

        return ans;
    }
};