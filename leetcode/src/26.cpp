#include <vector>

using namespace std;

namespace p26
{
    class Solution
    {
    public:
        int removeDuplicates(vector<int>& nums) {
            int count = 0;

            for (const auto& e : nums)
            {
                if (count == 0 || e != nums[count - 1])
                {
                    nums[count++] = e;
                }
            }

            return count;
        }
    };
} // namespace p26

/*
# Problem:

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## HINT:

Record the number of processed elements

## Algorithm:

```
count = 0

for e in nums:
    if count == 0 and e != nums[count - 1]:
        nums[count++] = e

return count
```

## Time Complexity:
O(n)

## Space Complexity:
O(1)
*/