#include "heap.hpp"
#include <cassert>

int Heap::_getSize()
{
    return last;
}

bool Heap::_isKeySmaller(int lhs, int rhs)
{
    return lhs < rhs;
}

bool Heap::_isKeyBigger(int lhs, int rhs)
{
    return lhs > rhs;
}

bool Heap::_isBetterByPos(int lhs_pos, int rhs_pos)
{
    // return _isKeySmaller(elements[lhs_pos], elements[rhs_pos]);
    return _isKeyBigger(cnts[lhs_pos], cnts[rhs_pos]);
}

void Heap::_adjustToUp(int pos)
{
    if (pos == 0)
    {
        return;
    }
    else
    {
        int parent_pos = (pos + 1) / 2 - 1;
        //               ^^^^           ^^^   base 1

        if (_isBetterByPos(pos, parent_pos))
        {
            int tmp = elements[pos];
            elements[pos] = elements[parent_pos];
            elements[parent_pos] = tmp;

            tmp = cnts[pos];
            cnts[pos] = cnts[parent_pos];
            cnts[parent_pos] = tmp;

            _adjustToUp(parent_pos);
        }
    }

    return;
}

void Heap::_adjustToDown(int pos)
{
    if (pos >= last)
    {
        return;
    }
    else
    {
        int left_pos = (pos + 1) * 2 - 1;
        int right_pos = (pos + 1) * 2 + 1 - 1;

        int min_value_pos;
        if (left_pos >= _getSize())
        {
            // there is no child
            return;
        }
        else
        {
            if (right_pos >= _getSize())
            {
                // only left_pos
                min_value_pos = left_pos;
            }
            else
            {
                // there are two children
                if (_isBetterByPos(left_pos, right_pos))
                {
                    min_value_pos = left_pos;
                }
                else
                {
                    min_value_pos = right_pos;
                }
            }
        }

        if (_isBetterByPos(min_value_pos, pos))
        {
            int tmp = elements[pos];
            elements[pos] = elements[min_value_pos];
            elements[min_value_pos] = tmp;

            tmp = cnts[pos];
            cnts[pos] = cnts[min_value_pos];
            cnts[min_value_pos] = tmp;

            _adjustToDown(min_value_pos);
        }
    }

}

int Heap::_findPos(int value)
{
    for (int i = 0; i < last; ++i)
    {
        if (elements[i] == value)
        {
            return i;
        }
    }

    return -1;
}

void Heap::insert(int val)
{
    int pos = _findPos(val);

    if (pos == -1)
    {
        if (_getSize() + 1 > elements.size())
        {
            elements.resize(elements.size() * 2);
            cnts.resize(cnts.size() * 2);
        }

        elements[last] = val;
        cnts[last] = 1;
        _adjustToUp(last);

        ++last;
    }
    else
    {
        ++cnts[pos];

        _adjustToUp(pos);
    }
}

void Heap::removeValue(int value, bool remove_all)
{
    int pos = _findPos(value);

    if (pos != -1)
    {
        if (cnts[pos] == 1 || remove_all)
        {
            elements[pos] = elements[last - 1];
            cnts[pos] = cnts[last - 1];

            elements[last - 1] = 0; // not necessary, just for visualize debug.
            cnts[last - 1] = 0; // not necessary, just for visualize debug.
            --last;

            _adjustToDown(pos);
        }
        else
        {
            assert(cnts[pos] > 1);
            --cnts[pos];

            _adjustToDown(pos);
        }
    }
}

void Heap::removeTop(bool remove_all)
{
    if (_getSize() != 0)
    {
        removeValue(elements[0], remove_all);
    }
}

int Heap::getValueCnt(int val)
{
    int pos = _findPos(val);

    if (pos == -1)
    {
        return -1;
    }
    else
    {
        return cnts[pos];
    }
}

int* Heap::getTopPtr()
{
    if (_getSize() == 0)
    {
        return nullptr;
    }
    else
    {
        return &elements[0];
    }
}