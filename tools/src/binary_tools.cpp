#include "binary_tools.hpp"

std::vector<int> BinaryTools::get_binary(int data)
{
    std::vector<int> _data;
    while (data > 0)
    {
        _data.emplace_back(data % 2);

        data /= 2;
    }

    return _data;
}

std::vector<int> BinaryTools::binary_of_two_int_sum(int a, int b)
{
    std::vector<int> _a = get_binary(a);
    std::vector<int> _b = get_binary(b);

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