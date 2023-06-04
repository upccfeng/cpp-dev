
#include <string>
using namespace std;
class Solution
{
public:
    int dayOfYear(string date)
    {
        string *ymd = datesplit(date);
        int year = stoi(ymd[0]);
        int month = stoi(ymd[1]);
        int day = stoi(ymd[2]);
        int monthday[12];
        monthday[0] = 31;
        monthday[1] = 28;
        monthday[2] = 31;
        monthday[3] = 30;
        monthday[4] = 31;
        monthday[5] = 30;
        monthday[6] = 31;
        monthday[7] = 31;
        monthday[8] = 30;
        monthday[9] = 31;
        monthday[10] = 30;
        monthday[11] = 31;
        if (isLeap(year))
        {
            monthday[1] = 29;
        }
        int ans = 0;
        for (int i = 0; i < month - 1; i++)
        {
            ans += monthday[i];
        }
        ans += day;

        return ans;
    }
    bool isLeap(int year)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return true;
        return false;
    }
    string *datesplit(string &origin)
    {
        string *ymd = new string[3];
        int taking = 0;
        for (auto c : origin)
        {
            if (c != '-')
            {
                ymd[taking] += c;
            }
            else
            {
                taking++;
            }
        }
        return ymd;
    }
};