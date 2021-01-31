#include <vector>
#include <string>

using namespace std;

namespace p10
{
    class Solution
    {
        bool is_belong(const char& taking, const char& target)
        {
            if (taking == target || target == '.')
                return true;
            else
                return false;
        }

        bool sp_table[20][30];
    public:
        bool isMatch(string s, string p) {
            std::vector<std::pair<char, bool>> p_model;
            for (const auto& e : p)
            {
                if (e == '*')
                {
                    p_model.back().second = true;
                }
                else
                {
                    p_model.emplace_back(std::make_pair(e, false));
                }
            }

            int p_boundary = p_model.size();
            int s_boundary = s.size();
            for (int i = 0; i < p_boundary; ++i)
            {
                for (int j = 0; j < s_boundary; ++j)
                {
                    sp_table[i][j] = p_model[i].first == s[j] ? true : false;
                }
            }
            /*
            do something!!
            */
        }
    };
} // namespace p10

/*
Problem: https://leetcode.com/problems/longest-palindromic-substring/

HINT:

Algorithm:

```
for start_c in s:
    longgest_pal = start_c
    r_boundary = start_c.pos() + 1
    l_boundary = start_c.pos() - 1
    while(??):
        case: r == l:
        case: r == r-1:
        case: l == l+1:
```

Time Complexity:

Space Complexity:

Test Code:
namespace p10
{
    using Solution = Solution;

    TEST(test_10, Case_1)
    {
        Solution s;
        string input_s = "aa";
        string input_p = "a";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_2)
    {
        Solution s;
        string input_s = "aa";
        string input_p = "a*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_3)
    {
        Solution s;
        string input_s = "ab";
        string input_p = ".*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_4)
    {
        Solution s;
        string input_s = "aab";
        string input_p = "c*a*b*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_5)
    {
        Solution s;
        string input_s = "mississippi";
        string input_p = "mis*is*p*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_1)
    {
        Solution s;
        string input_s = "miissppp";
        string input_p = "mis*is*p*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_2)
    {
        Solution s;
        string input_s = "sdfjgnsdzvjhkhxckjvhjkhk";
        string input_p = ".*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_3)
    {
        Solution s;
        string input_s = "adsjkgocxx";
        string input_p = "..........";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_4)
    {
        Solution s;
        string input_s = "adsjkgocxx";
        string input_p = "...";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_5)
    {
        Solution s;
        string input_s = "adsjkgocxx";
        string input_p = "";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_6)
    {
        Solution s;
        string input_s = "";
        string input_p = "";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Customer_7)
    {
        Solution s;
        string input_s = "";
        string input_p = "asdf.*d*";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Fail_1)
    {
        Solution s;
        string input_s = "ab";
        string input_p = ".*c";
        bool result = s.isMatch(input_s, input_p);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Fail_2)
    {
        Solution s;
        string input_s = "aaa";
        string input_p = "a*a";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_10, Case_Fail_3)
    {
        Solution s;
        string input_s = "aaa";
        string input_p = "ab*a*c*a";
        bool result = s.isMatch(input_s, input_p);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }
} // namespace p10
*/