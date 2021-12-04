#include <iostream>
using namespace std;
class Solution
{
public:
    string alphabetBoardPath(string target)
    {

        int taking_r = 0;

        int taking_c = 0;

        char prec = 'a';
        string ans;
        for (char c : target)
        {
            int now_r = (c - 97) / 5;
            int now_c = (c - 97) % 5;
            int diffc = now_c - taking_c;
            int diffr = now_r - taking_r;
            taking_c = now_c;
            taking_r = now_r;
            if (prec != 'z')
            {
                if (diffc < 0)
                {
                    for (int i = 0; i < (-diffc); i++)
                    {
                        ans += "L";
                    }
                }
                else
                {
                    for (int i = 0; i < diffc; i++)
                    {
                        ans += "R";
                    }
                }
                if (diffr < 0)
                {
                    for (int i = 0; i < (-diffr); i++)
                    {
                        ans += "U";
                    }
                }
                else
                {
                    for (int i = 0; i < diffr; i++)
                    {
                        ans += "D";
                    }
                }
            }
            else
            {
                if (diffr < 0)
                {
                    for (int i = 0; i < (-diffr); i++)
                    {
                        ans += "U";
                    }
                }
                else
                {
                    for (int i = 0; i < diffr; i++)
                    {
                        ans += "D";
                    }
                }
                if (diffc < 0)
                {
                    for (int i = 0; i < (-diffc); i++)
                    {
                        ans += "L";
                    }
                }
                else
                {
                    for (int i = 0; i < diffc; i++)
                    {
                        ans += "R";
                    }
                }
            }
            prec = c;
            ans += "!";
        }
        return ans;
    }
};