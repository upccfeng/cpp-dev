#include <vector>

namespace p_curated_array_152_max_product_subarray
{
    class Solution
    {
    public:
        int maxProduct(std::vector<int>& nums)
        {
            int max = nums[0];
            int product = 1;
            int neg = 0;

            for (auto e : nums)
            {
                product *= e;
                max = product > max ? product : max;

                if (product < 0)
                {
                    if (neg == 0)
                    {
                        neg = product;
                    }
                    else
                    {
                        max = product / neg > max ? product / neg : max;
                    }
                }

                if (product == 0)
                {
                    neg = 0;
                    product = 1;
                }

            }

            return max;
        }
    };
} // namespace p_curated_array_152_max_product_subarray

/*
# Problem:
https://leetcode.com/problems/maximum-product-subarray/

## HINT:
* Remember the first negitive value.
* Change neg while product is zero.
* If product < 0, the memebers contain odd number of neg. The index of first negitive value is NEG.
  * Product of n ~ (m - 1) is positive. n should be 0 or nums[n-1] should be 0.
  * The taking value is negitive.
  * The product of (NEG + 1) ~ (m) may be greater than MAX. Meaans that we need to check if "product / RPODUCT(n ~ NEG)" is greater than max.

## Algorithm:

max = nums[0]
product = 1
neg = 0

for e in nums:
    product *= e
    max = max(max, product)

    if (product < 0):
        if (neg == 0):
            neg = product                   # Store the product of n ~ m, which n is zeror or nums[n-1] is zero. m is the first negitive value in this subarray.
        else:
            max = max(max, product / neg)   # Compare max and product/PRODUCT(n~m)

    if (product == 0):
        product = 1
        neg = 0

return max

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(1)
*/


