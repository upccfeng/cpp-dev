#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include "7.cpp"

namespace p7
{
    using Solution = Solution;
    TEST(test_7, Case_1)
    {
        Solution s;
        int input = 123;
        int result = s.reverse(input);
        int expect = 321;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_2)
    {
        Solution s;
        int input = -123;
        int result = s.reverse(input);
        int expect = -321;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_3)
    {
        Solution s;
        int input = 120;
        int result = s.reverse(input);
        int expect = 21;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_4)
    {
        Solution s;
        int input = 0;
        int result = s.reverse(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_Customize_1)
    {
        Solution s;
        int input = pow(2, 31) - 1;
        int result = s.reverse(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_Customize_3)
    {
        Solution s;
        int input = -(pow(2, 31));
        int result = s.reverse(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_7, Case_Fail_1)
    {
        Solution s;
        int input = 1463847412;
        int result = s.reverse(input);
        int expect = 2147483641;
        ASSERT_EQ(result, expect);
    }
} // namespace p7

#include "8.cpp"

namespace p8
{
    using Solution = Solution;

    TEST(test_8, Case_1)
    {
        Solution s;
        std::string input = "42";
        int result = s.myAtoi(input);
        int expect = 42;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_2)
    {
        Solution s;
        std::string input = "   -42";
        int result = s.myAtoi(input);
        int expect = -42;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_3)
    {
        Solution s;
        std::string input = "4193 with words";
        int result = s.myAtoi(input);
        int expect = 4193;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_4)
    {
        Solution s;
        std::string input = "words and 987";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_5)
    {
        Solution s;
        std::string input = "-91283472332";
        int result = s.myAtoi(input);
        int expect = -pow(2, 31);
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_1)
    {
        Solution s;
        std::string input = "91283472332";
        int result = s.myAtoi(input);
        int expect = pow(2, 31) - 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_2)
    {
        Solution s;
        std::string input = "-+--+-+-999";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_3)
    {
        Solution s;
        std::string input = "-+009";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_4)
    {
        Solution s;
        std::string input = "+-xx99";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_Custmize_5)
    {
        Solution s;
        std::string input = "-2147483647";
        int result = s.myAtoi(input);
        int expect = -2147483647;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_1)
    {
        Solution s;
        std::string input = "  +0 123";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_2)
    {
        Solution s;
        std::string input = "-2147483648";
        int result = s.myAtoi(input);
        int expect = -2147483648;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_3)
    {
        Solution s;
        std::string input = "-5-";
        int result = s.myAtoi(input);
        int expect = -5;
        ASSERT_EQ(result, expect);
    }

    TEST(test_8, Case_fail_4)
    {
        Solution s;
        std::string input = "00000-42a1234";
        int result = s.myAtoi(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p8

#include "9.cpp"

namespace p9
{
    using Solution = Solution;

    TEST(test_9, Case_1)
    {
        Solution s;
        int input = 121;
        bool result = s.isPalindrome(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_9, Case_2)
    {
        Solution s;
        int input = -121;
        bool result = s.isPalindrome(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_9, Case_3)
    {
        Solution s;
        int input = 10;
        bool result = s.isPalindrome(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_9, Case_4)
    {
        Solution s;
        int input = -101;
        bool result = s.isPalindrome(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_9, Case_Customer_1)
    {
        Solution s;
        int input = 1234321;
        bool result = s.isPalindrome(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_9, Case_Customer_2)
    {
        Solution s;
        int input = 2147483647;
        bool result = s.isPalindrome(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p9

#include "11.cpp"

namespace p11
{
    using Solution = Solution;
    TEST(test_11, Case_1)
    {
        Solution s;
        std::vector<int> height = {1, 8, 6, 2, 5, 4, 8 ,3 ,7};
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_2)
    {
        Solution s;
        std::vector<int> height = {1, 1};
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_3)
    {
        Solution s;
        std::vector<int> height = {4, 3, 2, 1, 4};
        int result = s.maxArea(height);
        int expect = 16;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_4)
    {
        Solution s;
        std::vector<int> height = {1, 2, 1};
        int result = s.maxArea(height);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_customize_1)
    {
        Solution s;
        std::vector<int> height = {5, 4, 3, 2, 1, 1};
        int result = s.maxArea(height);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_1)
    {
        Solution s;
        std::vector<int> height = {2, 3, 10, 5, 7, 8, 9};
        int result = s.maxArea(height);
        int expect = 36;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_2)
    {
        Solution s;
        std::vector<int> height = {0, 2};
        int result = s.maxArea(height);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_3)
    {
        Solution s;
        std::vector<int> height = {1, 2};
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_4)
    {
        Solution s;
        std::vector<int> height = {1, 2, 4, 3};
        int result = s.maxArea(height);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_11, Case_wrong_case_5)
    {
        Solution s;
        std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 25, 7};
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }
} // namespace p11

#include "13.cpp"

namespace p13
{
    using Solution = Solution;

    TEST(test_13, Case_1)
    {
        Solution s;
        string input = "III";
        int result = s.romanToInt(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_13, Case_2)
    {
        Solution s;
        string input = "IV";
        int result = s.romanToInt(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_13, Case_3)
    {
        Solution s;
        string input = "IX";
        int result = s.romanToInt(input);
        int expect = 9;
        ASSERT_EQ(result, expect);
    }

    TEST(test_13, Case_4)
    {
        Solution s;
        string input = "LVIII";
        int result = s.romanToInt(input);
        int expect = 58;
        ASSERT_EQ(result, expect);
    }

    TEST(test_13, Case_5)
    {
        Solution s;
        string input = "MCMXCIV";
        int result = s.romanToInt(input);
        int expect = 1994;
        ASSERT_EQ(result, expect);
    }
} // namespace p13

#include "14.cpp"

namespace p14
{
    using Solution = Solution;

    TEST(test_14, Case_1)
    {
        Solution s;
        std::vector<std::string> input = {"flower", "flow", "flight"};
        std::string result = s.longestCommonPrefix(input);
        std::string expect = "fl";
        ASSERT_EQ(result, expect);
    }

    TEST(test_14, Case_2)
    {
        Solution s;
        std::vector<std::string> input = {"dog", "racecar", "car"};
        std::string result = s.longestCommonPrefix(input);
        std::string expect = "";
        ASSERT_EQ(result, expect);
    }
} // namespace p14

#include "17.cpp"

namespace p17
{
    using Solution = Solution;

    TEST(test_17, Case_1)
    {
        Solution s;
        string input = "23";
        vector<string> result = s.letterCombinations(input);
        vector<string> expect = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        ASSERT_EQ(result, expect);
    }

    TEST(test_17, Case_2)
    {
        Solution s;
        string input = "";
        vector<string> result = s.letterCombinations(input);
        vector<string> expect = {};
        ASSERT_EQ(result, expect);
    }

    TEST(test_17, Case_3)
    {
        Solution s;
        string input = "2";
        vector<string> result = s.letterCombinations(input);
        vector<string> expect = {"a", "b", "c"};
        ASSERT_EQ(result, expect);
    }

    TEST(test_17, Case_Customer_1)
    {
        Solution s;
        string input = "234";
        vector<string> result = s.letterCombinations(input);
        vector<string> expect = {
            "adg", "adh", "adi",
            "aeg", "aeh", "aei",
            "afg", "afh", "afi",
            "bdg", "bdh", "bdi",
            "beg", "beh", "bei",
            "bfg", "bfh", "bfi",
            "cdg", "cdh", "cdi",
            "ceg", "ceh", "cei",
            "cfg", "cfh", "cfi",
        };
        ASSERT_EQ(result, expect);
    }
} // namespace p17

#include "19.cpp"

namespace p19
{
    using Solution = Solution;

    TEST(test_19, Case_1)
    {
        Solution s;
        ListNode* input = ListNode::makeList({1,2,3,4,5});
        ListNode* result = s.removeNthFromEnd(input, 2);
        vector<int> expect = {1,2,3,5};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_19, Case_2)
    {
        Solution s;
        ListNode* input = ListNode::makeList({1});
        ListNode* result = s.removeNthFromEnd(input, 1);
        vector<int> expect = {};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_19, Case_3)
    {
        Solution s;
        ListNode* input = ListNode::makeList({1,2});
        ListNode* result = s.removeNthFromEnd(input, 1);
        vector<int> expect = {1};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_19, Case_Customer_1)
    {
        Solution s;
        ListNode* input = ListNode::makeList({1,2});
        ListNode* result = s.removeNthFromEnd(input, 2);
        vector<int> expect = {2};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }
} // namespace p19

#include "20.cpp"

namespace p20
{
    using Solution = Solution;

    TEST(test_20, Case_1)
    {
        Solution s;
        string input = "()";
        bool result = s.isValid(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_2)
    {
        Solution s;
        string input = "()[]{}";
        bool result = s.isValid(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_3)
    {
        Solution s;
        string input = "(]";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_4)
    {
        Solution s;
        string input = "([)]";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_5)
    {
        Solution s;
        string input = "{[]}";
        bool result = s.isValid(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_Customer_1)
    {
        Solution s;
        string input = "";
        bool result = s.isValid(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_Customer_2)
    {
        Solution s;
        string input = "{{{{";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_Customer_3)
    {
        Solution s;
        string input = "]]]]";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_Customer_4)
    {
        Solution s;
        string input = ")]]]]";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_20, Case_Customer_5)
    {
        Solution s;
        string input = "11";
        bool result = s.isValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p20

#include "21.cpp"

namespace p21
{
    using Solution = Solution;

    TEST(test_21, Case_1)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({1,2,4});
        ListNode* input_2 = ListNode::makeList({1,3,4});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {1,1,2,3,4,4};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_2)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({});
        ListNode* input_2 = ListNode::makeList({});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_3)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({});
        ListNode* input_2 = ListNode::makeList({0});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {0};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_Customer_1)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({1,2});
        ListNode* input_2 = ListNode::makeList({});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {1,2};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_Customer_2)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({1,2});
        ListNode* input_2 = ListNode::makeList({3,4});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {1,2,3,4};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_Customer_3)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({1,2,3});
        ListNode* input_2 = ListNode::makeList({4});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {1,2,3,4};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }

    TEST(test_21, Case_Customer_4)
    {
        Solution s;
        ListNode* input_1 = ListNode::makeList({1});
        ListNode* input_2 = ListNode::makeList({2,3,4});
        ListNode* result = s.mergeTwoLists(input_1, input_2);
        vector<int> expect = {1,2,3,4};
        ASSERT_TRUE(ListNode::cmp(result, expect));

        ListNode::freeList(result);
    }
} // namespace p21

#include "22.cpp"

namespace p22
{
    using Solution = Solution;

    TEST(test_22, Case_1)
    {
        Solution s;
        int input = 3;
        vector<string> result = s.generateParenthesis(input);
        vector<string> expect = {"((()))","(()())","(())()","()(())","()()()"};
        ASSERT_EQ(result, expect);
    }

    TEST(test_22, Case_2)
    {
        Solution s;
        int input = 1;
        vector<string> result = s.generateParenthesis(input);
        vector<string> expect = {"()"};
        ASSERT_EQ(result, expect);
    }
} // namespace p22

#include "26.cpp"

namespace p26
{
    using Solution = Solution;

    TEST(test_26, Case_1)
    {
        Solution s;
        vector<int> input = {1,1,2};
        int result_count = s.removeDuplicates(input);
        vector<int> result(input.begin(), input.begin() + result_count);
        vector<int> expect = {1,2};
        ASSERT_EQ(result, expect);
    }

    TEST(test_26, Case_2)
    {
        Solution s;
        vector<int> input = {0,0,1,1,1,2,2,3,3,4};
        int result_count = s.removeDuplicates(input);
        vector<int> result(input.begin(), input.begin() + result_count);
        vector<int> expect = {0,1,2,3,4};
        ASSERT_EQ(result, expect);
    }

    TEST(test_26, Case_Customer_1)
    {
        Solution s;
        vector<int> input = {};
        int result_count = s.removeDuplicates(input);
        vector<int> result(input.begin(), input.begin() + result_count);
        vector<int> expect = {};
        ASSERT_EQ(result, expect);
    }

    TEST(test_26, Case_Customer_2)
    {
        Solution s;
        vector<int> input = {1};
        int result_count = s.removeDuplicates(input);
        vector<int> result(input.begin(), input.begin() + result_count);
        vector<int> expect = {1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_26, Case_Customer_3)
    {
        Solution s;
        vector<int> input = {1,1,1,1};
        int result_count = s.removeDuplicates(input);
        vector<int> result(input.begin(), input.begin() + result_count);
        vector<int> expect = {1};
        ASSERT_EQ(result, expect);
    }
} // namespace p26

#include "28.cpp"

namespace p28
{
    using Solution = Solution;

    TEST(test_28, Case_1)
    {
        Solution s;
        string input_haystack = "hello";
        string input_needle = "ll";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_2)
    {
        Solution s;
        string input_haystack = "aaaaa";
        string input_needle = "bba";
        int result = s.strStr(input_haystack, input_needle);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_3)
    {
        Solution s;
        string input_haystack = "";
        string input_needle = "";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Customer_1)
    {
        Solution s;
        string input_haystack = "abc";
        string input_needle = "abc";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Customer_2)
    {
        Solution s;
        string input_haystack = "abcabc";
        string input_needle = "abc";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Customer_3)
    {
        Solution s;
        string input_haystack = "ababc";
        string input_needle = "abc";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Customer_4)
    {
        Solution s;
        string input_haystack = "ababc";
        string input_needle = "";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Customer_5)
    {
        Solution s;
        string input_haystack = "bbb";
        string input_needle = "xxx";
        int result = s.strStr(input_haystack, input_needle);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_28, Case_Fail_1)
    {
        Solution s;
        string input_haystack = "mississippi";
        string input_needle = "issip";
        int result = s.strStr(input_haystack, input_needle);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }
} // namespace p28

#include "29.cpp"

namespace p29
{
    using Solution = Solution;

    TEST(test_29, Case_1)
    {
        Solution s;
        int input_dividend = 10;
        int input_divisor = 3;
        int result = s.divide(input_dividend, input_divisor);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_2)
    {
        Solution s;
        int input_dividend = 7;
        int input_divisor = -3;
        int result = s.divide(input_dividend, input_divisor);
        int expect = -2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_3)
    {
        Solution s;
        int input_dividend = 0;
        int input_divisor = 1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_4)
    {
        Solution s;
        int input_dividend = 1;
        int input_divisor = 1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Customer_1)
    {
        Solution s;
        int input_dividend = -10;
        int input_divisor = -3;
        int result = s.divide(input_dividend, input_divisor);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Customer_2)
    {
        Solution s;
        int input_dividend = INT_MIN;
        int input_divisor = -1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = INT_MAX;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Customer_3)
    {
        Solution s;
        int input_dividend = INT_MAX;
        int input_divisor = -1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = INT_MIN + 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Fail_1)
    {
        Solution s;
        int input_dividend = INT_MAX;
        int input_divisor = 1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = INT_MAX;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Fail_2)
    {
        Solution s;
        int input_dividend = -1;
        int input_divisor = 1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Fail_3)
    {
        Solution s;
        int input_dividend = 1038925803;
        int input_divisor = -2147483648;
        int result = s.divide(input_dividend, input_divisor);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_29, Case_Fail_4)
    {
        Solution s;
        int input_dividend = -2147483648;
        int input_divisor = 1;
        int result = s.divide(input_dividend, input_divisor);
        int expect = -2147483648;
        ASSERT_EQ(result, expect);
    }
} // namespace p29

#include "33.cpp"

namespace p33
{
    using Solution = Solution;

    TEST(test_33, Case_1)
    {
        Solution s;
        vector<int> input = {4,5,6,7,0,1,2};
        int result = s.search(input, 0);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_33, Case_2)
    {
        Solution s;
        vector<int> input = {4,5,6,7,0,1,2};
        int result = s.search(input, 3);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_33, Case_3)
    {
        Solution s;
        vector<int> input = {1};
        int result = s.search(input, 0);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_33, Case_Customer_1)
    {
        Solution s;
        vector<int> input = {4,5,6,7,0,1,2};
        int result = s.search(input, 5);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_33, Case_Customer_2)
    {
        Solution s;
        vector<int> input = {4,5,6,7,0,1,2};
        int result = s.search(input, 1);
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test_33, Case_Fail_1)
    {
        Solution s;
        vector<int> input = {8,9,1,5,6,7};
        int result = s.search(input, 5);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }
} // namespace p33

#include "34.cpp"

namespace p34
{
    using Solution = Solution;

    TEST(test_34, Case_1)
    {
        Solution s;
        vector<int> input_nums = {5,7,7,8,8,10};
        int input_target = 8;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {3,4};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_2)
    {
        Solution s;
        vector<int> input_nums = {5,7,7,8,8,10};
        int input_target = 6;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {-1,-1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_3)
    {
        Solution s;
        vector<int> input_nums = {};
        int input_target = 0;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {-1,-1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_1)
    {
        Solution s;
        vector<int> input_nums = {5,7,7,8,8,10};
        int input_target = 7;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {1,2};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_2)
    {
        Solution s;
        vector<int> input_nums = {5,7,7,8,8,10};
        int input_target = 10;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {5,5};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_3)
    {
        Solution s;
        vector<int> input_nums = {5};
        int input_target = 5;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {0,0};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_4)
    {
        Solution s;
        vector<int> input_nums = {5};
        int input_target = 6;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {-1, -1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_5)
    {
        Solution s;
        vector<int> input_nums = {5,5,5};
        int input_target = 5;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {0,2};
        ASSERT_EQ(result, expect);
    }

    TEST(test_34, Case_Customer_6)
    {
        Solution s;
        vector<int> input_nums = {1,2,3,4,5,6,7,8,9,10,11};
        int input_target = 10;
        vector<int> result = s.searchRange(input_nums, input_target);
        vector<int> expect = {9,9};
        ASSERT_EQ(result, expect);
    }
} // namespace p34

#include "36.cpp"

namespace p36
{
    using Solution = Solution;

    TEST(test_36, Case_1)
    {
        Solution s;
        vector<vector<char>> input = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        bool result = s.isValidSudoku(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_36, Case_2)
    {
        Solution s;
        vector<vector<char>> input = {
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        bool result = s.isValidSudoku(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p36

#include "66.cpp"

namespace p66
{
    using Solution = Solution;

    TEST(test_66, Case_1)
    {
        Solution s;
        vector<int> input = {1,2,3};
        vector<int> result = s.plusOne(input);
        vector<int> expect = {1,2,4};
        ASSERT_EQ(result, expect);
    }

    TEST(test_66, Case_2)
    {
        Solution s;
        vector<int> input = {4,3,2,1};
        vector<int> result = s.plusOne(input);
        vector<int> expect = {4,3,2,2};
        ASSERT_EQ(result, expect);
    }

    TEST(test_66, Case_3)
    {
        Solution s;
        vector<int> input = {0};
        vector<int> result = s.plusOne(input);
        vector<int> expect = {1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_66, Case_Customer_1)
    {
        Solution s;
        vector<int> input = {9,9};
        vector<int> result = s.plusOne(input);
        vector<int> expect = {1,0,0};
        ASSERT_EQ(result, expect);
    }

    TEST(test_66, Case_Customer_2)
    {
        Solution s;
        vector<int> input = {1,0,9};
        vector<int> result = s.plusOne(input);
        vector<int> expect = {1,1,0};
        ASSERT_EQ(result, expect);
    }
} // namespace p66

#include "696_daily.cpp"

namespace p696_daily
{
    using Solution = Solution;

    TEST(test_696_daily, Case_1)
    {
        Solution s;
        string input = "00110011";
        int result = s.countBinarySubstrings(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_696_daily, Case_2)
    {
        Solution s;
        string input = "10101";
        int result = s.countBinarySubstrings(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_696_daily, Case_Customer_1)
    {
        Solution s;
        string input = "";
        int result = s.countBinarySubstrings(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_696_daily, Case_Customer_2)
    {
        Solution s;
        string input = "111111";
        int result = s.countBinarySubstrings(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_696_daily, Case_Customer_3)
    {
        Solution s;
        string input = "00001111";
        int result = s.countBinarySubstrings(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }
} // namespace p696_daily

#include "763.cpp"

namespace p763
{
    TEST(test_763, Case_1)
    {
        Solution s;
        string input = "ababcbacadefegdehijhklij";
        auto result = s.partitionLabels(input);
        vector<int> expect = {9, 7, 8};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_sigle)
    {
        Solution s;
        string input = "a";
        auto result = s.partitionLabels(input);
        vector<int> expect = {1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_the_same)
    {
        Solution s;
        string input = "aaaaa";
        auto result = s.partitionLabels(input);
        vector<int> expect = {5};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_1)
    {
        Solution s;
        string input = "aaabbbccc";
        auto result = s.partitionLabels(input);
        vector<int> expect = {3, 3, 3};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_2)
    {
        Solution s;
        string input = "aaabbbccca";
        auto result = s.partitionLabels(input);
        vector<int> expect = {10};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_3)
    {
        Solution s;
        string input = "aaabbbcccabgkgge";
        auto result = s.partitionLabels(input);
        vector<int> expect = {11, 4, 1};
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_wrong_1)
    {
        Solution s;
        string input = "caedbdedda";
        auto result = s.partitionLabels(input);
        vector<int> expect = {1, 9};
        ASSERT_EQ(result, expect);
    }
} // namespace p763

#include "637_daily.cpp"

namespace p637_daily
{
    using Solution = Solution;

    TEST(test_637_daily, Case_1)
    {
        Solution s;
        TreeNode* input = TreeNode::makeTree({3, 9, 20, -1, -1, 15, 7}, {true, true, true, false, false, true, true}, 3);
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {3, 14.5, 11};
        ASSERT_EQ(result, expect);

        TreeNode::freeTree(input);
    }

    TEST(test_637_daily, Case_2)
    {
        Solution s;
        TreeNode* input = TreeNode::makeTree({3, 9, 20, 15, 7, -1, -1}, {true, true, true, true, true, false, false}, 3);
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {3, 14.5, 11};
        ASSERT_EQ(result, expect);

        TreeNode::freeTree(input);
    }

    TEST(test_637_daily, Case_3)
    {
        Solution s;
        TreeNode* input = TreeNode::makeTree({1, -1, 1}, {true, false, true}, 2);
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {1, 1};
        ASSERT_EQ(result, expect);

        TreeNode::freeTree(input);
    }

    TEST(test_637_daily, Case_4)
    {
        Solution s;
        TreeNode* input = TreeNode::makeTree({57, 46, 89, -36, -1, -1, -1}, {true, true, true, true, false, false, false}, 3);
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {57, 67.5, -36};
        ASSERT_EQ(result, expect);

        TreeNode::freeTree(input);
    }

    TEST(test_637_daily, Case_5)
    {
        Solution s;
        TreeNode* input = TreeNode::makeTree({0, 1, -1}, {true, true, false}, 2);
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {0, 1};
        ASSERT_EQ(result, expect);

        TreeNode::freeTree(input);
    }
} // namespace p637_daily

#include "820_daily.cpp"

namespace p820_daily
{
    using Solution = Solution;

    TEST(test_820_daily, Case_1)
    {
        Solution s;
        vector<string> input = {"time", "me", "bell"};
        int result = s.minimumLengthEncoding(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_2)
    {
        Solution s;
        vector<string> input = {"t"};
        int result = s.minimumLengthEncoding(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Customer_1)
    {
        Solution s;
        vector<string> input = {"me", "time", "bell"};
        int result = s.minimumLengthEncoding(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Customer_2)
    {
        Solution s;
        vector<string> input = {"me", "time", "ime", "bell"};
        int result = s.minimumLengthEncoding(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Customer_3)
    {
        Solution s;
        vector<string> input = {"ctime", "atime", "time", "bell"};
        int result = s.minimumLengthEncoding(input);
        int expect = 17;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Customer_4)
    {
        Solution s;
        vector<string> input = {"ab", "ab"};
        int result = s.minimumLengthEncoding(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Customer_5)
    {
        Solution s;
        vector<string> input = {"aaaaa", "aaa", "aa"};
        int result = s.minimumLengthEncoding(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_820_daily, Case_Fail_1)
    {
        Solution s;
        vector<string> input = {"aaa", "abc", "aaa", "asd", "fdg", "abc", "kld"};
        int result = s.minimumLengthEncoding(input);
        int expect = 20;
        ASSERT_EQ(result, expect);
    }
} // namespace p820_daily

#include "1209_daily.cpp"

namespace p1209_daily
{
    using Solution = Solution;

    TEST(test_1209_daily, Case_Customer_1)
    {
        Solution s;
        string input_s = "abcddd";
        int input_k = 2;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "abcd";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_Customer_2)
    {
        Solution s;
        string input_s = "dddcc";
        int input_k = 3;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "cc";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_Customer_3)
    {
        Solution s;
        string input_s = "caabbbacd";
        int input_k = 3;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "ccd";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_Customer_4)
    {
        Solution s;
        string input_s = "caabbbacc";
        int input_k = 3;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_1)
    {
        Solution s;
        string input_s = "abcd";
        int input_k = 2;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "abcd";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_2)
    {
        Solution s;
        string input_s = "deeedbbcccbdaa";
        int input_k = 3;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "aa";
        ASSERT_EQ(result, expect);
    }

    TEST(test_1209_daily, Case_3)
    {
        Solution s;
        string input_s = "pbbcggttciiippooaais";
        int input_k = 2;
        auto result = s.removeDuplicates(input_s, input_k);
        string expect = "ps";
        ASSERT_EQ(result, expect);
    }
} // namespace p1209_daily

#include "1837_weekly_contest.cpp"

namespace p1837_weekly_contest
{
    using Solution = Solution;

    TEST(test_1837_weekly_contest, Case_1)
    {
        Solution s;
        int input_n = 34;
        int input_k = 6;
        int result = s.sumBase(input_n, input_k);
        int expect = 9;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1837_weekly_contest, Case_2)
    {
        Solution s;
        int input_n = 10;
        int input_k = 10;
        int result = s.sumBase(input_n, input_k);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1837_weekly_contest, Case_Customer_1)
    {
        Solution s;
        int input_n = 10;
        int input_k = 2;
        int result = s.sumBase(input_n, input_k);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
} // namespace p1837_weekly_contest

#include "1838_weekly_contest.cpp"

namespace p1838_weekly_contest
{
    using Solution = Solution;

    TEST(test_1838_weekly_contest, Case_1)
    {
        Solution s;
        vector<int> input_nums = {1, 2, 4};
        int input_k = 5;
        int result = s.maxFrequency(input_nums, input_k);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1838_weekly_contest, Case_2)
    {
        Solution s;
        vector<int> input_nums = {1,4,8,13};
        int input_k = 5;
        int result = s.maxFrequency(input_nums, input_k);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1838_weekly_contest, Case_3)
    {
        Solution s;
        vector<int> input_nums = {3,9,6};
        int input_k = 2;
        int result = s.maxFrequency(input_nums, input_k);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1838_weekly_contest, Case_Customer_1)
    {
        Solution s;
        vector<int> input_nums = {1,4,8,11};
        int input_k = 10;
        int result = s.maxFrequency(input_nums, input_k);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1838_weekly_contest, Case_Fail_1)
    {
        Solution s;
        vector<int> input_nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
        int input_k = 3056;
        int result = s.maxFrequency(input_nums, input_k);
        int expect = 73;
        ASSERT_EQ(result, expect);
    }
} // namespace p1838_weekly_contest

#include "rekuten210221_1.cpp"

namespace p_rekuten210221_1
{
    using Solution = Solution;

    TEST(test_rekuten210221_1, Case_1)
    {
        Solution s;
        vector<int> input = {1, 0, 2, 0, 0, 2};
        int result = s.solution(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_rekuten210221_1, Case_2)
    {
        Solution s;
        vector<int> input = {3, 1, 0, 2, 0, 0, 2};
        int result = s.solution(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_rekuten210221_1, Case_3)
    {
        Solution s;
        vector<int> input = {33};
        int result = s.solution(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_rekuten210221_1, Case_4)
    {
        Solution s;
        vector<int> input = {10000, 10000};
        int result = s.solution(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_rekuten210221_1, Case_5)
    {
        Solution s;
        vector<int> input = {10000, 10000, 10000, 10000};
        int result = s.solution(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_rekuten210221_1, Case_6)
    {
        Solution s;
        vector<int> input = {10000, 10000, 10000};
        int result = s.solution(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
} // namespace p_rekuten210221_1