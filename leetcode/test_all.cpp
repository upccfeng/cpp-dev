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