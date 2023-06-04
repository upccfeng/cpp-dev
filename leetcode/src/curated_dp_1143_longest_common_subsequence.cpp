#include <string>
#include <vector>

namespace p_curated_dp_1143_longest_common_subsequence
{
    class Solution
    {
    public:
        int longestCommonSubsequence(std::string text1, std::string text2)
        {
            std::vector<std::vector<int>> dp2(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

            for (int i = text1.size() - 1; i >= 0; --i)
            {
                for (int j = text2.size() - 1; j >= 0; --j)
                {
                    if (text1[i] == text2[j])
                    {
                        dp2[i][j] = 1 + dp2[i + 1][j + 1];
                    }
                    else
                    {
                        dp2[i][j] = std::max(dp2[i + 1][j], dp2[i][j + 1]);
                    }
                }

            }

            return dp2[0][0];
        }
    };
} // namespace p_curated_dp_1143_longest_common_subsequence

/*
# Problem:
https://leetcode.com/problems/longest-common-subsequence/

## HINT:
* For string A and B, if A[0] is the same as B[0], the number will be 1 + F(A[1 ~ end], B[1 ~ end])
*                     if A[0] is not the same as B[0], the number will be MAX(F(A[0 ~ end], B[1 ~ end]), F(A[1 ~ end], B[0 ~ end]))
* Use 2D dp.
* Bottom up.

## Time Complexity:
BigO(n * m)

## Space Complexity:
BigO(n * m)
*/