
namespace p_curated_binary_371_sum_of_two
{
    class Solution
    {
    public:
        int getSum(int a, int b)
        {
            int ret = 0;
            bool carry = 0;
            unsigned int filter = 0x1;
            while (filter != 0)
            {
                bool ta = a & filter;
                bool tb = b & filter;

                if (!carry)
                {
                    carry = ta & tb;

                    if (ta ^ tb)
                    {
                        ret = ret | filter;
                    }
                }
                else
                {
                    carry = ta | tb;

                    if (!(ta ^ tb))
                    {
                        ret = ret | filter;
                    }
                }

                filter = filter << 1;
            }

            return ret;
        }
    };
} // namespace p_curated_binary_371_sum_of_two

/*
# Problem:
https://leetcode.com/problems/sum-of-two-integers/

## HINT:
* Bitwise operator
* Just caculate 32-bit, and use uint from 1 to 0.

## Algorithm:

int ret = 0
bool carry = 0
unsigned int filter = 0x1
while (filter != 0)
    ta = a & filter
    tb = b & filter

    if (!carry):
        carry = ta & tb

        if (ta ^ tb):
            ret = ret | filter
    else:
        carry = ta | tb

        if (!(ta ^ tb)):
            ret = ret | filter

    filter = filter << 1

return ret;

## Time Complexity:
BigO(32)

## Space Complexity:
BigO(1)
*/