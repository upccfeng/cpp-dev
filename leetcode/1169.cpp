#include <iostream>
#include <vector>
#include "../string_tool/string_tool.hpp"

using namespace std;

class Solution
{
public:
    struct transaction
    {
        string name;
        int time;
        int amount;
        string city;
        bool valid = true;
    };
    //"alice,20,800,mtv" = <name>, <time>, <amount>, "city"
    //{"alice,20,800,mtv", "alice,50,100,beijing"};
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        int listlen = transactions.size();
        transaction *tlist = new transaction[listlen];
        for (int i = 0; i < listlen; i++)
        {
            vector<string> result;
            StringTool strtool;
            strtool.SplitStringByToken(result, transactions[i], ",");
            tlist[i].name = result[0];
            tlist[i].time = stoi(result[1]);
            tlist[i].amount = stoi(result[2]);
            tlist[i].city = result[3];
        }

        vector<string> ans;
        for (int i = 0; i < listlen; i++)
        {
            if (isExceed(tlist[i].amount))
            {
                if (tlist[i].valid)
                {
                    tlist[i].valid = false;
                    ans.push_back(transactions[i]);
                }
            }
            else
            {
                for (int j = 0; j < listlen; j++)
                {
                    if (i != j && tlist[i].name == tlist[j].name)
                    {
                        if (isInvalid(tlist[i], tlist[j]))
                        {

                            if (tlist[i].valid)
                            {
                                tlist[i].valid = false;
                                ans.push_back(transactions[i]);
                            }
                            if (tlist[j].valid)
                            {
                                tlist[j].valid = false;
                                ans.push_back(transactions[j]);
                            }
                        }
                        break;
                    }
                }
            }
        }

        delete[] tlist;
        return ans;
    }
    //the amount exceeds $1000, or;
    bool isExceed(int amount)
    {
        if (amount > 1000)
            return true;
        return false;
    }
    //if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
    // if (name1 == name 2 && city1 != city2 && time1-time2<=60) is failed
    bool isInvalid(transaction &a, transaction &b)
    {
        if (a.name == b.name && a.city != b.city && abs(a.time - b.time) <= 60)
        {
            return true;
        }
        return false;
    }
};
