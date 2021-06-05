#include "binary_tools.hpp"

std::vector<int> BinaryTools::binary_of_two_int_sum(int a, int b)
{
    std::vector<int> _a, _b;

    while (a > 0)
    {
        _a.emplace_back(a % 2);

        a /= 2;
    }

    while (b > 0)
    {
        _b.emplace_back(b % 2);

        b /= 2;
    }

    std::vector<int> t(_a.size() + _b.size(), 0);
    for (int bcnt = 0; bcnt < _b.size(); ++bcnt)
    {
        for (int acnt = 0; acnt < _a.size(); ++acnt)
        {
            int tmp = t[bcnt + acnt] + _b[bcnt] * _a[acnt];
            while (tmp > 1)
            {
                t[bcnt + acnt + 1] = t[bcnt + acnt + 1] + tmp / 2;
                tmp = tmp - 2 * (tmp / 2);
            }

            t[bcnt + acnt] = tmp;
        }
    }

    return t;
}