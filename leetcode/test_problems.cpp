#include <iostream>
#include <limits.h>
#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

#include "curated_array_1_twosum.cpp"

namespace p_curated_array_1_twosum
{
    using Solution = Solution;

    TEST(test_curated_array_1_twosum, Case_1)
    {
        Solution s;
        std::vector<int> input_nums = { 2,7,11,15 };
        int input_target = 9;
        std::vector<int> result = s.twoSum(input_nums, input_target);
        std::vector<int> expect = { 0, 1 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_1_twosum, Case_2)
    {
        Solution s;
        std::vector<int> input_nums = { 3,2,4 };
        int input_target = 6;
        std::vector<int> result = s.twoSum(input_nums, input_target);
        std::vector<int> expect = { 1, 2 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_1_twosum, Case_3)
    {
        Solution s;
        std::vector<int> input_nums = { 3,3 };
        int input_target = 6;
        std::vector<int> result = s.twoSum(input_nums, input_target);
        std::vector<int> expect = { 0, 1 };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_1_twosum

#include "curated_string_3_longest_substring_without_repeating_characters.cpp"

namespace p_curated_string_3_longest_substring_without_repeating_characters
{
    using Solution = Solution;

    TEST(test__curated_string_3_longest_substring_without_repeating_characters, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "abcabcbb";
        RetsultType result = s.lengthOfLongestSubstring(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_3_longest_substring_without_repeating_characters, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "bbbbb";
        RetsultType result = s.lengthOfLongestSubstring(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_3_longest_substring_without_repeating_characters, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "pwwkew";
        RetsultType result = s.lengthOfLongestSubstring(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_3_longest_substring_without_repeating_characters, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "abba";
        RetsultType result = s.lengthOfLongestSubstring(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_3_longest_substring_without_repeating_characters

#include "curated_string_5_longest_palindromic_substring.cpp"

namespace p_curated_string_5_longest_palindromic_substring
{
    using Solution = Solution;

    TEST(test__curated_string_5_longest_palindromic_substring, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input = "babad";
        RetsultType result = s.longestPalindrome(input);
        RetsultType expect = "bab";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_5_longest_palindromic_substring, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input = "cbbd";
        RetsultType result = s.longestPalindrome(input);
        RetsultType expect = "bb";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_5_longest_palindromic_substring, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input = "ac";
        RetsultType result = s.longestPalindrome(input);
        RetsultType expect = "a";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_5_longest_palindromic_substring, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input = "abb";
        RetsultType result = s.longestPalindrome(input);
        RetsultType expect = "bb";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_5_longest_palindromic_substring

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

#include "10.cpp"

namespace p_10
{
    using Solution = Solution;

    TEST(test__10, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aa";
        std::string input_p = "a";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aa";
        std::string input_p = "a*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "ab";
        std::string input_p = ".*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aab";
        std::string input_p = ".*a*b";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "a";
        std::string input_p = "ab";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aaa";
        std::string input_p = "a.a";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "a";
        std::string input_p = "ab*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__10, Case_Failure_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "bbbba";
        std::string input_p = ".*a*a";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_10

#include "curated_array_11_most_water_in_container.cpp"

namespace p_curated_array_11_most_water_in_container
{
    using Solution = Solution;
    TEST(test__curated_array_11_most_water_in_container, Case_1)
    {
        Solution s;
        std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8 ,3 ,7 };
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_2)
    {
        Solution s;
        std::vector<int> height = { 1, 1 };
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_3)
    {
        Solution s;
        std::vector<int> height = { 4, 3, 2, 1, 4 };
        int result = s.maxArea(height);
        int expect = 16;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_4)
    {
        Solution s;
        std::vector<int> height = { 1, 2, 1 };
        int result = s.maxArea(height);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_customize_1)
    {
        Solution s;
        std::vector<int> height = { 5, 4, 3, 2, 1, 1 };
        int result = s.maxArea(height);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_wrong_case_1)
    {
        Solution s;
        std::vector<int> height = { 2, 3, 10, 5, 7, 8, 9 };
        int result = s.maxArea(height);
        int expect = 36;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_wrong_case_2)
    {
        Solution s;
        std::vector<int> height = { 0, 2 };
        int result = s.maxArea(height);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_wrong_case_3)
    {
        Solution s;
        std::vector<int> height = { 1, 2 };
        int result = s.maxArea(height);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_wrong_case_4)
    {
        Solution s;
        std::vector<int> height = { 1, 2, 4, 3 };
        int result = s.maxArea(height);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_11_most_water_in_container, Case_wrong_case_5)
    {
        Solution s;
        std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 25, 7 };
        int result = s.maxArea(height);
        int expect = 49;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_11_most_water_in_container

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

#include "curated_array_15_3sum.cpp"

namespace p_curated_array_15_3sum
{
    using Solution = Solution;

    TEST(test_curated_array_15_3sum, Case_1)
    {
        Solution s;
        std::vector<int> input = { -1,0,1,2,-1,-4 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = { {-1,-1,2} ,{-1,0,1} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_2)
    {
        Solution s;
        std::vector<int> input = {};
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = {};
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_3)
    {
        Solution s;
        std::vector<int> input = { 0 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = {};
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { -1, -1, 0, 1 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = { {-1, 0, 1} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { -2, 0, 1, 1, 2 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = { {-2,0,2},{-2,1,1} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_Failure_2)
    {
        Solution s;
        std::vector<int> input = { 0, 0, 0 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = { {0, 0, 0} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_15_3sum, Case_Failure_3)
    {
        Solution s;
        std::vector<int> input = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
        std::vector<std::vector<int>> result = s.threeSum(input);
        std::vector<std::vector<int>> expect = { {-5, 1, 4}, {-4, 0, 4}, {-4, 1, 3}, {-2, -2, 4}, {-2, 1, 1}, {0, 0, 0} };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_15_3sum

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

#include "18.cpp"

namespace p_18
{
    using Solution = Solution;

    TEST(test__18, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input_nums = { 1,0,-1,0,-2,2 };
        int input_target = 0;
        RetsultType result = s.fourSum(input_nums, input_target);
        RetsultType expect = { {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__18, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input_nums = { 2,2,2,2,2 };
        int input_target = 8;
        RetsultType result = s.fourSum(input_nums, input_target);
        RetsultType expect = { {2, 2, 2, 2} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_18

#include "curated_linkedlist_19_remove_nth_node_from_end_of_list.cpp"

namespace p_curated_linkedlist_19_remove_nth_node_from_end_of_list
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_19_remove_nth_node_from_end_of_list, Case_1)
    {
        Solution s;
        using InputType_1 = ListNode*;
        using InputType_2 = int;
        using RetsultType = ListNode*;

        InputType_1 input_head = ListHelper::create({ 1,2,3,4,5 });
        InputType_2 input_n = 2;
        RetsultType result = s.removeNthFromEnd(input_head, input_n);
        RetsultType expect = ListHelper::create({ 1,2,3,5 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }

    TEST(test__curated_linkedlist_19_remove_nth_node_from_end_of_list, Case_2)
    {
        Solution s;
        using InputType_1 = ListNode*;
        using InputType_2 = int;
        using RetsultType = ListNode*;

        InputType_1 input_head = ListHelper::create({ 1 });
        InputType_2 input_n = 1;
        RetsultType result = s.removeNthFromEnd(input_head, input_n);
        RetsultType expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }

    TEST(test__curated_linkedlist_19_remove_nth_node_from_end_of_list, Case_3)
    {
        Solution s;
        using InputType_1 = ListNode*;
        using InputType_2 = int;
        using RetsultType = ListNode*;

        InputType_1 input_head = ListHelper::create({ 1, 2 });
        InputType_2 input_n = 1;
        RetsultType result = s.removeNthFromEnd(input_head, input_n);
        RetsultType expect = ListHelper::create({ 1 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }

    TEST(test__curated_linkedlist_19_remove_nth_node_from_end_of_list, Case_Failure_1)
    {
        Solution s;
        using InputType_1 = ListNode*;
        using InputType_2 = int;
        using RetsultType = ListNode*;

        InputType_1 input_head = ListHelper::create({ 1, 2 });
        InputType_2 input_n = 2;
        RetsultType result = s.removeNthFromEnd(input_head, input_n);
        RetsultType expect = ListHelper::create({ 2 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }
} // namespace p_curated_linkedlist_19_remove_nth_node_from_end_of_list

#include "curated_string_20_valid_parantheses.cpp"

namespace p_curated_string_20_valid_parantheses
{
    using Solution = Solution;

    TEST(test__curated_string_20_valid_parantheses, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "()";
        RetsultType result = s.isValid(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_20_valid_parantheses, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "()[]{}";
        RetsultType result = s.isValid(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_20_valid_parantheses, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "(]";
        RetsultType result = s.isValid(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_20_valid_parantheses, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "(}}}}}}";
        RetsultType result = s.isValid(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_20_valid_parantheses, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "()))))";
        RetsultType result = s.isValid(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_20_valid_parantheses

#include "curated_linkedlist_21_sorted_lists.cpp"

namespace p_curated_linkedlist_21_sorted_lists
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_21_sorted_lists, Case_1)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2,4 });
        auto input_2 = ListHelper::create({ 1,3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,1,2,3,4,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_2)
    {
        Solution s;
        auto input_1 = ListHelper::create({});
        auto input_2 = ListHelper::create({});
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_3)
    {
        Solution s;
        auto input_1 = ListHelper::create({});
        auto input_2 = ListHelper::create({ 0 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 0 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_Customer_1)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2 });
        auto input_2 = ListHelper::create({});
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_Customer_2)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2 });
        auto input_2 = ListHelper::create({ 3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_Customer_3)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2,3 });
        auto input_2 = ListHelper::create({ 4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test__curated_linkedlist_21_sorted_lists, Case_Customer_4)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1 });
        auto input_2 = ListHelper::create({ 2,3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }
} // namespace p_curated_linkedlist_21_sorted_lists

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

#include "curated_linkedlist_23_merge_k_sorted_lists.cpp"

namespace p_curated_linkedlist_23_merge_k_sorted_lists
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_23_merge_k_sorted_lists, Case_1)
    {
        Solution s;
        using InputType = std::vector<ListNode*>;
        using RetsultType = ListNode*;

        InputType input = { ListHelper::create({1, 4, 5}) ,ListHelper::create({1, 3, 4}), ListHelper::create({2, 6}) };
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({ 1, 1, 2, 3, 4, 4, 5, 6 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_linkedlist_23_merge_k_sorted_lists, Case_2)
    {
        Solution s;
        using InputType = std::vector<ListNode*>;
        using RetsultType = ListNode*;

        InputType input = {  };
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_linkedlist_23_merge_k_sorted_lists, Case_3)
    {
        Solution s;
        using InputType = std::vector<ListNode*>;
        using RetsultType = ListNode*;

        InputType input = { ListHelper::create({}) };
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }
} // namespace p_curated_linkedlist_23_merge_k_sorted_lists

#include "curated_heap_23_merge_k_sorted_lists.cpp"

namespace p_curated_heap_23_merge_k_sorted_lists
{
    using Solution = Solution;

    TEST(test__curated_heap_23_merge_k_sorted_lists, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        std::vector<ListNode*> input = { ListHelper::create({1, 4, 5}), ListHelper::create({1, 3, 4}), ListHelper::create({2, 6}) };
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({ 1,1,2,3,4,4,5,6 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // TODO: Due to the implement of mergeKlists, all node in result are copies of input.
        for (auto l : input)
        {
            ListHelper::remove(l);
        }

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_heap_23_merge_k_sorted_lists, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        std::vector<ListNode*> input = {};
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // TODO: Due to the implement of mergeKlists, all node in result are copies of input.
        for (auto l : input)
        {
            ListHelper::remove(l);
        }

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_heap_23_merge_k_sorted_lists, Case_3)
    {
        Solution s;
        using RetsultType = ListNode*;

        std::vector<ListNode*> input = { {} };
        RetsultType result = s.mergeKLists(input);
        RetsultType expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // TODO: Due to the implement of mergeKlists, all node in result are copies of input.
        for (auto l : input)
        {
            ListHelper::remove(l);
        }

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }
} // namespace p_curated_heap_23_merge_k_sorted_lists

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

#include "curated_array_33_search_in_rotated_sorted_array.cpp"

namespace p_curated_array_33_search_in_rotated_sorted_array
{
    using Solution = Solution;

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_1)
    {
        Solution s;
        std::vector<int> input_nums = { 4,5,6,7,0,1,2 };
        int input_target = 0;
        int result = s.search(input_nums, input_target);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_2)
    {
        Solution s;
        std::vector<int> input_nums = { 4,5,6,7,0,1,2 };
        int input_target = 3;
        int result = s.search(input_nums, input_target);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_3)
    {
        Solution s;
        std::vector<int> input_nums = { 1 };
        int input_target = 0;
        int result = s.search(input_nums, input_target);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1 };
        int input_target = 1;
        int result = s.search(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input_nums = { 5, 1, 2, 3, 4 };
        int input_target = 4;
        int result = s.search(input_nums, input_target);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_33_search_in_rotated_sorted_array, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3 };
        int input_target = 3;
        int result = s.search(input_nums, input_target);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_33_search_in_rotated_sorted_array

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

#include "35_daily.cpp"

namespace p35_daily
{
    using Solution = Solution;

    TEST(test_35_daily, Case_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3,5,6 };
        int input_target = 5;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_2)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3,5,6 };
        int input_target = 2;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_3)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3,5,6 };
        int input_target = 7;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_4)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3,5,6 };
        int input_target = 0;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_5)
    {
        Solution s;
        std::vector<int> input_nums = { 1 };
        int input_target = 0;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_Wrong_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1 };
        int input_target = 1;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_35_daily, Case_RunTime_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1,3 };
        int input_target = 0;
        int result = s.searchInsert(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p35_daily


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

#include "38.cpp"

namespace p_38
{
    using Solution = Solution;

    TEST(test__38, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input = 1;
        RetsultType result = s.countAndSay(input);
        RetsultType expect = "1";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__38, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        int input = 4;
        RetsultType result = s.countAndSay(input);
        RetsultType expect = "1211";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__38, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input = 5;
        RetsultType result = s.countAndSay(input);
        RetsultType expect = "111221";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__38, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input = 6;
        RetsultType result = s.countAndSay(input);
        RetsultType expect = "312211";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_38

#include "41.cpp"

namespace p_41
{
    using Solution = Solution;

    TEST(test__41, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,2,0 };
        RetsultType result = s.firstMissingPositive(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__41, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 3,4,-1,1 };
        RetsultType result = s.firstMissingPositive(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__41, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 7,8,9,11,12 };
        RetsultType result = s.firstMissingPositive(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__41, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 0,1,2 };
        RetsultType result = s.firstMissingPositive(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_41

#include "42.cpp"

namespace p_42
{
    using Solution = Solution;

    TEST(test__42, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };
        RetsultType result = s.trap(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__42, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 4,2,0,3,2,5 };
        RetsultType result = s.trap(input);
        RetsultType expect = 9;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_42

#include "44.cpp"

namespace p_44
{
    using Solution = Solution;

    TEST(test__44, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aa";
        std::string input_p = "a";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aa";
        std::string input_p = "*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "cb";
        std::string input_p = "?a";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "cb";
        std::string input_p = "?b";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "acccb";
        std::string input_p = "a*b";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "acccd";
        std::string input_p = "a*b";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_4)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "abc";
        std::string input_p = "abc*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_5)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "abc";
        std::string input_p = "abc*b";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_6)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "abc";
        std::string input_p = "abcbbbbb";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_7)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "acccbe";
        std::string input_p = "a*be";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Customize_8)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "acccbe";
        std::string input_p = "a*bc";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__44, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba";
        std::string input_p = "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*";
        RetsultType result = s.isMatch(input_s, input_p);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    //TEST(test__44, Case_Runtime_2)
    //{
    //    Solution s;
    //    using RetsultType = bool;

    //    std::string input_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //    std::string input_p = "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*";
    //    RetsultType result = s.isMatch(input_s, input_p);
    //    RetsultType expect = false;
    //    ASSERT_THAT(result == expect, Eq(true));
    //}
} // namespace p_44

#include "46.cpp"

namespace p46
{
    using Solution = Solution;

    TEST(test_46, Case_1)
    {
        Solution s;
        vector<int> input = { 1, 2, 3 };
        vector<vector<int>> result = s.permute(input);
        vector<vector<int>> expect = { {1, 2, 3} ,{1, 3, 2},{2, 1, 3},{2, 3, 1},{3, 2, 1},{3, 1, 2} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_46, Case_2)
    {
        Solution s;
        vector<int> input = { 0, 1 };
        vector<vector<int>> result = s.permute(input);
        vector<vector<int>> expect = { {0, 1} ,{1, 0} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_46, Case_3)
    {
        Solution s;
        vector<int> input = { 1 };
        vector<vector<int>> result = s.permute(input);
        vector<vector<int>> expect = { {1} };
        ASSERT_EQ(result, expect);
    }
} // namespace p46

#include "47.cpp"

namespace p47
{
    using Solution = Solution;

    TEST(test_47, Case_1)
    {
        Solution s;
        vector<int> input = { 1,1,2 };
        vector<vector<int>> result = s.permuteUnique(input);
        vector<vector<int>> expect = { {1, 1, 2}, {1, 2, 1}, {2, 1, 1} };
        ASSERT_EQ(result, expect);
    }

    TEST(test_47, Case_2)
    {
        Solution s;
        vector<int> input = { 1,2,3 };
        vector<vector<int>> result = s.permuteUnique(input);
        vector<vector<int>> expect = { {1,2,3} ,{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
        ASSERT_EQ(result, expect);
    }
} // namespace p47

#include "curated_matrix_48_rotate_image.cpp"

namespace p_curated_matrix_48_rotate_image
{
    using Solution = Solution;

    TEST(test__curated_matrix_48_rotate_image, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        RetsultType input = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        s.rotate(input);
        RetsultType& result = input;
        RetsultType expect = { {7, 4, 1}, {8, 5, 2}, {9, 6, 3} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_48_rotate_image, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        RetsultType input = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
        s.rotate(input);
        RetsultType& result = input;
        RetsultType expect = { {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_matrix_48_rotate_image

#include "curated_string_49_group_anagrams.cpp"

namespace p_curated_string_49_group_anagrams
{
    using Solution = Solution;

    TEST(test__curated_string_49_group_anagrams, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::vector<std::string> input = { "eat","tea","tan","ate","nat","bat" };
        std::vector<std::vector<std::string>> result = s.groupAnagrams(input);
        RetsultType expect = { {"tan", "nat"}, {"eat", "tea", "ate"}, {"bat"} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_49_group_anagrams, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::vector<std::string> input = { "" };
        std::vector<std::vector<std::string>> result = s.groupAnagrams(input);
        RetsultType expect = { {""} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_49_group_anagrams, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::vector<std::string> input = { "a" };
        std::vector<std::vector<std::string>> result = s.groupAnagrams(input);
        RetsultType expect = { {"a"} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_49_group_anagrams

#include "50.cpp"

namespace p_50
{
    using Solution = Solution;

    TEST(test__50, Case_1)
    {
        Solution s;
        using RetsultType = double;

        double input_x = 2.0;
        int input_n = 10;
        RetsultType result = s.myPow(input_x, input_n);
        RetsultType expect = 1024.0;
        ASSERT_THAT(result - expect < 0.000001 && result - expect > -0.000001, Eq(true));
    }

    TEST(test__50, Case_2)
    {
        Solution s;
        using RetsultType = double;

        double input_x = 2.1;
        int input_n = 3;
        RetsultType result = s.myPow(input_x, input_n);
        RetsultType expect = 9.261;
        ASSERT_THAT(result - expect < 0.000001 && result - expect > -0.000001, Eq(true));
    }

    TEST(test__50, Case_3)
    {
        Solution s;
        using RetsultType = double;

        double input_x = 2.0;
        int input_n = -2;
        RetsultType result = s.myPow(input_x, input_n);
        RetsultType expect = 0.25;
        ASSERT_THAT(result - expect < 0.000001 && result - expect > -0.000001, Eq(true));
    }
} // namespace p_50

#include "52_daily.cpp"

namespace p52_daily
{
    using Solution = Solution;

    TEST(test_52_daily, Case_1)
    {
        Solution s;
        int input = 4;
        int result = s.totalNQueens(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_52_daily, Case_2)
    {
        Solution s;
        int input = 1;
        int result = s.totalNQueens(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p52_daily

#include "curated_array_53_max_sub_array.cpp"

namespace p_curated_array_53_max_sub_array
{
    using Solution = Solution;

    TEST(test_curated_array_53_max_sub_array, Case_1)
    {
        Solution s;
        std::vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };
        int result = s.maxSubArray(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_53_max_sub_array, Case_2)
    {
        Solution s;
        std::vector<int> input = { 1 };
        int result = s.maxSubArray(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_53_max_sub_array, Case_3)
    {
        Solution s;
        std::vector<int> input = { 5,4,-1,7,8 };
        int result = s.maxSubArray(input);
        int expect = 23;
        ASSERT_EQ(result, expect);
    }

    using Solution_dac = Solution_divide_and_conquer;

    TEST(test_curated_array_53_max_sub_array_divide_and_conquer, Case_1)
    {
        Solution_dac s;
        std::vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };
        int result = s.maxSubArray(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_53_max_sub_array_divide_and_conquer, Case_2)
    {
        Solution_dac s;
        std::vector<int> input = { 1 };
        int result = s.maxSubArray(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_53_max_sub_array_divide_and_conquer, Case_3)
    {
        Solution_dac s;
        std::vector<int> input = { 5,4,-1,7,8 };
        int result = s.maxSubArray(input);
        int expect = 23;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_53_max_sub_array

#include "curated_matrix_54_spiral_matrix.cpp"

namespace p_curated_matrix_54_spiral_matrix
{
    using Solution = Solution;

    TEST(test__curated_matrix_54_spiral_matrix, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<std::vector<int>> input = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        RetsultType result = s.spiralOrder(input);
        RetsultType expect = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_54_spiral_matrix, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<std::vector<int>> input = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
        RetsultType result = s.spiralOrder(input);
        RetsultType expect = { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_54_spiral_matrix, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<std::vector<int>> input = { {1, 2, 3, 4} };
        RetsultType result = s.spiralOrder(input);
        RetsultType expect = { 1, 2, 3, 4 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_54_spiral_matrix, Case_Customize_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<std::vector<int>> input = { {1}, {2}, {3}, {4} };
        RetsultType result = s.spiralOrder(input);
        RetsultType expect = { 1, 2, 3, 4 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_matrix_54_spiral_matrix

#include "curated_dp_55_jump_game.cpp"

namespace p_curated_dp_55_jump_game
{
    using Solution = Solution;

    TEST(test__curated_dp_55_jump_game, Case_1)
    {
        Solution s;
        using result_type = bool;
        std::vector<int> input = { 2,3,1,1,4 };
        result_type result = s.canJump(input);
        result_type expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_55_jump_game, Case_2)
    {
        Solution s;
        using result_type = bool;
        std::vector<int> input = { 3,2,1,0,4 };
        result_type result = s.canJump(input);
        result_type expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_55_jump_game, Case_Customize_1)
    {
        Solution s;
        using result_type = bool;
        std::vector<int> input = { 1 };
        result_type result = s.canJump(input);
        result_type expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_55_jump_game, Case_Failure_1)
    {
        Solution s;
        using result_type = bool;
        std::vector<int> input = { 2, 0 };
        result_type result = s.canJump(input);
        result_type expect = true;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_55_jump_game

#include "curated_interval_56_merge_intervals.cpp"

namespace p_curated_interval_56_merge_intervals
{
    using Solution = Solution;

    TEST(test__curated_interval_56_merge_intervals, Case_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
        RetsultType result = s.merge(input);
        RetsultType expect = { {1, 6}, {8, 10}, {15, 18} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_56_merge_intervals, Case_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {1, 4}, {4, 5} };
        RetsultType result = s.merge(input);
        RetsultType expect = { {1, 5} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_56_merge_intervals, Case_Failure_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {1, 4}, {2, 3} };
        RetsultType result = s.merge(input);
        RetsultType expect = { {1, 4} };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_interval_56_merge_intervals


#include "curated_interval_57_insert_interval.cpp"

namespace p_curated_interval_57_insert_interval
{
    using Solution = Solution;

    TEST(test__curated_interval_57_insert_interval, Case_1)
    {
        Solution s;
        using InputType_1 = std::vector<std::vector<int>>;
        using InputType_2 = std::vector<int>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType_1 input_intervals = { {1, 3}, {6, 9} };
        InputType_2 input_newInterval = { 2, 5 };
        RetsultType result = s.insert(input_intervals, input_newInterval);
        RetsultType expect = { {1, 5}, {6, 9} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_57_insert_interval, Case_2)
    {
        Solution s;
        using InputType_1 = std::vector<std::vector<int>>;
        using InputType_2 = std::vector<int>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType_1 input_intervals = { {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
        InputType_2 input_newInterval = { 4, 8 };
        RetsultType result = s.insert(input_intervals, input_newInterval);
        RetsultType expect = { {1, 2}, {3, 10}, {12, 16} };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_interval_57_insert_interval

#include "61.cpp"

namespace p_61
{
    using Solution = Solution;

    TEST(test__61, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input_head = ListHelper::create({ 1,2,3,4,5 });
        int input_k = 2;
        RetsultType result = s.rotateRight(input_head, input_k);
        RetsultType expect = ListHelper::create({ 4,5,1,2,3 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }

    TEST(test__61, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input_head = ListHelper::create({ 0,1,2 });
        int input_k = 4;
        RetsultType result = s.rotateRight(input_head, input_k);
        RetsultType expect = ListHelper::create({ 2,0,1 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));
    }
} // namespace p_61

#include "curated_dp_62_unique_paths.cpp"

namespace p_curated_dp_62_unique_paths
{
    using Solution = Solution;

    TEST(test__curated_dp_62_unique_paths, Case_1)
    {
        Solution s;
        int input_m = 3;
        int input_n = 7;
        int result = s.uniquePaths(input_m, input_n);
        int expect = 28;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_62_unique_paths, Case_2)
    {
        Solution s;
        int input_m = 3;
        int input_n = 2;
        int result = s.uniquePaths(input_m, input_n);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_62_unique_paths, Case_Customize_1)
    {
        Solution s;
        int input_m = 1;
        int input_n = 1;
        int result = s.uniquePaths(input_m, input_n);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_62_unique_paths, Case_Customize_2)
    {
        Solution s;
        int input_m = 1;
        int input_n = 2;
        int result = s.uniquePaths(input_m, input_n);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_62_unique_paths

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

#include "68.cpp"

namespace p_68
{
    using Solution = Solution;

    TEST(test__68, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<std::string> input_words = { "This", "is", "an", "example", "of", "text", "justification." };
        int input_maxWidth = 16;
        RetsultType result = s.fullJustify(input_words, input_maxWidth);
        RetsultType expect = { "This    is    an", "example  of text", "justification.  " };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__68, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<std::string> input_words = { "What","must","be","acknowledgment","shall","be" };
        int input_maxWidth = 16;
        RetsultType result = s.fullJustify(input_words, input_maxWidth);
        RetsultType expect = { "What   must   be", "acknowledgment  ", "shall be        " };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__68, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<std::string> input_words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
        int input_maxWidth = 20;
        RetsultType result = s.fullJustify(input_words, input_maxWidth);
        RetsultType expect = { "Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  " };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_68

#include "69.cpp"

namespace p_69
{
    using Solution = Solution;

    TEST(test__69, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 4;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 8;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 9;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_Customize_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 0;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_Customize_3)
    {
        Solution s;
        using RetsultType = int;

        int input = 1;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_Customize_4)
    {
        Solution s;
        using RetsultType = int;

        int input = 2;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__69, Case_Customize_5)
    {
        Solution s;
        using RetsultType = int;

        int input = 3;
        RetsultType result = s.mySqrt(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_69

#include "curated_dp_70_climbing_stairts.cpp"

namespace p_curated_dp_70_climbing_stairts
{
    using Solution = Solution;

    TEST(test__curated_dp_70_climbing_stairts, Case_1)
    {
        Solution s;
        int input = 2;
        int result = s.climbStairs(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_70_climbing_stairts, Case_2)
    {
        Solution s;
        int input = 3;
        int result = s.climbStairs(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_70_climbing_stairts, Case_Customize_1)
    {
        Solution s;
        int input = 4;
        int result = s.climbStairs(input);
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_70_climbing_stairts, Case_Customize_2)
    {
        Solution s;
        int input = 1;
        int result = s.climbStairs(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_70_climbing_stairts, Case_Customize_3)
    {
        Solution s;
        int input = 5;
        int result = s.climbStairs(input);
        int expect = 8;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_70_climbing_stairts

#include "curated_matrix_73_set_matrix_zeros.cpp"

namespace p_curated_matrix_73_set_matrix_zeros
{
    using Solution = Solution;

    TEST(test__curated_matrix_73_set_matrix_zeros, Case_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>&;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {1, 1, 1}, { 1, 0, 1 }, { 1, 1, 1 } };
        s.setZeroes(input);
        InputType result = input;
        RetsultType expect = { {1, 0, 1}, {0, 0, 0}, {1, 0, 1} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_73_set_matrix_zeros, Case_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>&;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
        s.setZeroes(input);
        InputType result = input;
        RetsultType expect = { {0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_matrix_73_set_matrix_zeros

#include "75.cpp"

namespace p_75
{
    using Solution = Solution;

    TEST(test__75, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 2,0,2,1,1,0 };
        s.sortColors(input);
        RetsultType expect = { 0,0,1,1,2,2 };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__75, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 2,0,1 };
        s.sortColors(input);
        RetsultType expect = { 0,1,2 };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_75

#include "curated_string_76_minimum_window_substring.cpp"

namespace p_curated_string_76_minimum_window_substring
{
    using Solution = Solution;

    TEST(test__curated_string_76_minimum_window_substring, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input_s = "ADOBECODEBANC";
        std::string input_t = "ACB";
        RetsultType result = s.minWindow(input_s, input_t);
        RetsultType expect = "BANC";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_76_minimum_window_substring, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input_s = "a";
        std::string input_t = "a";
        RetsultType result = s.minWindow(input_s, input_t);
        RetsultType expect = "a";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_76_minimum_window_substring, Case_3)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input_s = "a";
        std::string input_t = "aa";
        RetsultType result = s.minWindow(input_s, input_t);
        RetsultType expect = "";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_76_minimum_window_substring, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::string input_s = "aaabbaaba";
        std::string input_t = "abbb";
        RetsultType result = s.minWindow(input_s, input_t);
        RetsultType expect = "bbaab";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_76_minimum_window_substring

#include "78.cpp"

namespace p_78
{
    using Solution = Solution;

    TEST(test__78, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input = { 1,2,3 };
        RetsultType result = s.subsets(input);
        RetsultType expect = { {1, 2, 3}, {1, 2}, {1, 3}, {1}, {2, 3}, {2}, {3}, {} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__78, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input = { 0 };
        RetsultType result = s.subsets(input);
        RetsultType expect = { {0}, {} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_78

#include "curated_matrix_79_word_search.cpp"

namespace p_curated_matrix_79_word_search
{
    using Solution = Solution;

    TEST(test__curated_matrix_79_word_search, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
        std::string input_word = "ABCCED";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_79_word_search, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
        std::string input_word = "SEE";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_79_word_search, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
        std::string input_word = "ABCB";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_79_word_search, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A'} };
        std::string input_word = "A";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_79_word_search, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A'} };
        std::string input_word = "B";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_matrix_79_word_search, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<char>> input_board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'} };
        std::string input_word = "ABCESEEEFS";
        RetsultType result = s.exist(input_board, input_word);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_matrix_79_word_search

#include "82.cpp"

namespace p_82
{
    using Solution = Solution;

    TEST(test__82, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 1,2,3,3,4,4,5 });
        RetsultType result = s.deleteDuplicates(input);
        RetsultType expect = ListHelper::create({ 1,2,5 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
    }

    TEST(test__82, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 1,1,1,2,3 });
        RetsultType result = s.deleteDuplicates(input);
        RetsultType expect = ListHelper::create({ 2,3 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
    }
} // namespace p_82

#include "84.cpp"

namespace p_84
{
    using Solution = Solution;

    TEST(test__84, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,1,5,6,2,3 };
        RetsultType result = s.largestRectangleArea(input);
        RetsultType expect = 10;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__84, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,4 };
        RetsultType result = s.largestRectangleArea(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_84

#include "88.cpp"

namespace p_88
{
    using Solution = Solution;

    TEST(test__88, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums1 = { 1,2,3,0,0,0 };
        int input_m = 3;
        std::vector<int> input_nums2 = { 2,5,6 };
        int input_n = 3;
        s.merge(input_nums1, input_m, input_nums2, input_n);
        RetsultType expect = { 1, 2, 2, 3, 5, 6 };
        ASSERT_THAT(input_nums1 == expect, Eq(true));
    }

    TEST(test__88, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums1 = { 1 };
        int input_m = 1;
        std::vector<int> input_nums2 = { };
        int input_n = 0;
        s.merge(input_nums1, input_m, input_nums2, input_n);
        RetsultType expect = { 1 };
        ASSERT_THAT(input_nums1 == expect, Eq(true));
    }

    TEST(test__88, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums1 = { 0 };
        int input_m = 0;
        std::vector<int> input_nums2 = { 1 };
        int input_n = 1;
        s.merge(input_nums1, input_m, input_nums2, input_n);
        RetsultType expect = { 1 };
        ASSERT_THAT(input_nums1 == expect, Eq(true));
    }
} // namespace p_88

#include "curated_dp_91_decode_ways.cpp"

namespace p_curated_dp_91_decode_ways
{
    using Solution = Solution;

    TEST(test__curated_dp_91_decode_ways, Case_1)
    {
        Solution s;
        std::string input = "12";
        int result = s.numDecodings(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_91_decode_ways, Case_2)
    {
        Solution s;
        std::string input = "226";
        int result = s.numDecodings(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_91_decode_ways, Case_3)
    {
        Solution s;
        std::string input = "06";
        int result = s.numDecodings(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_91_decode_ways

#include "94.cpp"

namespace p_94
{
    using Solution = Solution;

    TEST(test__94, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        TreeNode* input = TreeHelper::create("1,null,2,3");
        RetsultType result = s.inorderTraversal(input);
        RetsultType expect = { 1,3,2 };
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }

    TEST(test__94, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        TreeNode* input = TreeHelper::create("");
        RetsultType result = s.inorderTraversal(input);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }

    TEST(test__94, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        TreeNode* input = TreeHelper::create("1");
        RetsultType result = s.inorderTraversal(input);
        RetsultType expect = { 1 };
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }
} // namespace p_94


#include "curated_tree_98_validate_bindary_search_tree.cpp"

namespace p_curated_tree_98_validate_bindary_search_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ 2,1,3 }, {});
        RetsultType result = s.isValidBST(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ 5,1,4,-1,-1,3,6 }, { true,true,true,false,false,true,true });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ 1 }, { });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ INT_MAX }, { });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Customize_3)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ INT_MIN }, { });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ 2,2,2 }, { });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ 5, 4, 6, -1, -1, 3, 7 }, { true,true,true,false,false,true,true });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_98_validate_bindary_search_tree, Case_Failure_3)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create({ INT_MIN, -1, INT_MAX }, { true,false,true });
        RetsultType result = s.isValidBST(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_tree_98_validate_bindary_search_tree


#include "curated_tree_100_same_tree.cpp"

namespace p_curated_tree_100_same_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_100_same_tree, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_p = TreeHelper::create({ 1,2,3 }, { true, true, true });
        TreeNode* input_q = TreeHelper::create({ 1,2,3 }, { true, true, true });
        RetsultType result = s.isSameTree(input_p, input_q);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
    }

    TEST(test__curated_tree_100_same_tree, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_p = TreeHelper::create({ 1,2 }, { true, true });
        TreeNode* input_q = TreeHelper::create({ 1,-1,2 }, { true, false, true });
        RetsultType result = s.isSameTree(input_p, input_q);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
    }

    TEST(test__curated_tree_100_same_tree, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_p = TreeHelper::create({ 1,2,1 }, { true, true, true });
        TreeNode* input_q = TreeHelper::create({ 1,1,2 }, { true, true, true });
        RetsultType result = s.isSameTree(input_p, input_q);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
    }
} // namespace p_curated_tree_100_same_tree

#include "101.cpp"

namespace p_101
{
    using Solution = Solution;

    TEST(test__101, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create("1,2,2,3,4,4,3");
        RetsultType result = s.isSymmetric(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }

    TEST(test__101, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input = TreeHelper::create("1,2,2,null,3,null,3");
        RetsultType result = s.isSymmetric(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }
} // namespace p_101

#include "curated_tree_102_binary_tree_level_order_traversal.cpp"

namespace p_curated_tree_102_binary_tree_level_order_traversal
{
    using Solution = Solution;

    TEST(test__curated_tree_102_binary_tree_level_order_traversal, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create({ 3,9,20,-1,-1,15,7 }, { true,true,true,false,false,true,true });
        RetsultType result = s.levelOrder(input);
        RetsultType expect = { {3}, {9, 20}, {15, 7} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_102_binary_tree_level_order_traversal, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create({ 1 }, { true });
        RetsultType result = s.levelOrder(input);
        RetsultType expect = { {1} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_102_binary_tree_level_order_traversal, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create({ }, { });
        RetsultType result = s.levelOrder(input);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_tree_102_binary_tree_level_order_traversal

#include "103.cpp"

namespace p_103
{
    using Solution = Solution;

    TEST(test__103, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create("3,9,20,null,null,15,7");
        RetsultType result = s.zigzagLevelOrder(input);
        RetsultType expect = { {3}, {20, 9}, {15, 7} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__103, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create("1");
        RetsultType result = s.zigzagLevelOrder(input);
        RetsultType expect = { {1} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__103, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        TreeNode* input = TreeHelper::create("");
        RetsultType result = s.zigzagLevelOrder(input);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_103

#include "curated_tree_104_maximum_depth_of_binary_tree.cpp"

namespace p_curated_tree_104_maximum_depth_of_binary_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_104_maximum_depth_of_binary_tree, Case_1)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ 3, 9, 20, -1, -1, 15, 7 }, { true, true, true, false, false, true, true });
        RetsultType result = s.maxDepth(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }

    TEST(test__curated_tree_104_maximum_depth_of_binary_tree, Case_2)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ 1, -1, 2 }, { true, true, true, false, false, true, true });
        RetsultType result = s.maxDepth(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input);
    }
} // namespace p_curated_tree_104_maximum_depth_of_binary_tree

#include "curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp"

namespace p_curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal
{
    using Solution = Solution;

    TEST(test__curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<int> input_preorder = { 3,9,20,15,7 };
        std::vector<int> input_inorder = { 9,3,15,20,7 };
        RetsultType result = s.buildTree(input_preorder, input_inorder);
        RetsultType expect = TreeHelper::create({ 3,9,20,-1,-1,15,7 }, { true,true,true,false,false,true,true });
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<int> input_preorder = { -1 };
        std::vector<int> input_inorder = { -1 };
        RetsultType result = s.buildTree(input_preorder, input_inorder);
        RetsultType expect = TreeHelper::create({ -1 }, {});
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<int> input_preorder = { 1, 2 };
        std::vector<int> input_inorder = { 1, 2 };
        RetsultType result = s.buildTree(input_preorder, input_inorder);
        RetsultType expect = TreeHelper::create({ 1, -1, 2 }, { true,false,true });
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }
} // namespace p_curated_tree_105_construct_binary_tree_from_preorder_and_inorder_traversal

#include "108.cpp"

namespace p_108
{
    using Solution = Solution;

    TEST(test__108, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<int> input = { -10,-3,0,5,9 };
        RetsultType result = s.sortedArrayToBST(input);
        RetsultType expect_1 = TreeHelper::create("0,-3,9,-10,null,5");
        RetsultType expect_2 = TreeHelper::create("0,-10,5,null,-3,null,9");
        ASSERT_THAT(TreeHelper::compare(result, expect_1) || TreeHelper::compare(result, expect_2), Eq(true));
    }

    TEST(test__108, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<int> input = { 1,3 };
        RetsultType result = s.sortedArrayToBST(input);
        RetsultType expect_1 = TreeHelper::create("3,1");
        RetsultType expect_2 = TreeHelper::create("1,null,3");
        ASSERT_THAT(TreeHelper::compare(result, expect_1) || TreeHelper::compare(result, expect_2), Eq(true));
    }
} // namespace p_108

#include "116.cpp"

namespace p_116
{
    using Solution = Solution;

    TEST(test__116, Case_1)
    {
        Solution s;
        using RetsultType = Node*;

        // FIXME: There is no implementation for verify this data structure
        Node* input = nullptr; // NodeHelper::create("1,2,3,4,5,6,7");
        RetsultType result = s.connect(input);
        RetsultType expect = nullptr; // NodeHelper:;create("1,#,2,3,#,4,5,6,7,#");
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__116, Case_2)
    {
        Solution s;
        using RetsultType = Node*;

        // FIXME: There is no implementation for verify this data structure
        Node* input = nullptr; // NodeHelper::create("");
        RetsultType result = s.connect(input);
        RetsultType expect = nullptr; // NodeHelper:;create("");
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_116

#include "118.cpp"

namespace p_118
{
    using Solution = Solution;

    TEST(test__118, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        int input = 5;
        RetsultType result = s.generate(input);
        RetsultType expect = { {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__118, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        int input = 1;
        RetsultType result = s.generate(input);
        RetsultType expect = { {1} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_118

#include "curated_array_121_bestprofit.cpp"

namespace p_curated_array_121_bestprofit
{
    using Solution = Solution;

    TEST(test_curated_array_121_besttime, Case_1)
    {
        Solution s;
        std::vector<int> input = { 7,1,5,3,6,4 };
        int result = s.maxProfit(input);
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_121_besttime, Case_2)
    {
        Solution s;
        std::vector<int> input = { 7,6,4,3,1 };
        int result = s.maxProfit(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_121_besttime, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 2,4,1 };
        int result = s.maxProfit(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_121_bestprofit

#include "122.cpp"

namespace p_122
{
    using Solution = Solution;

    TEST(test__122, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 7,1,5,3,6,4 };
        RetsultType result = s.maxProfit(input);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__122, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,2,3,4,5 };
        RetsultType result = s.maxProfit(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__122, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 7,6,4,3,1 };
        RetsultType result = s.maxProfit(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_122

#include "curated_tree_124_binary_tree_maximum_path_sum.cpp"

namespace p_curated_tree_124_binary_tree_maximum_path_sum
{
    using Solution = Solution;

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_1)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ 1,2,3 }, {});
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_2)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ -10,9,20,-1,-1,15,7 }, { true, true, true, false, false, true, true });
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = 42;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ 99, -1, -2 }, {});
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = 99;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_Customize_2)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ 3 }, {});
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ -3 }, {});
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = -3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_124_binary_tree_maximum_path_sum, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input = TreeHelper::create({ -1,-2,10,-6,-1,-3,-6 }, { true,true,true,true,false,true,true });
        RetsultType result = s.maxPathSum(input);
        RetsultType expect = 10;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_tree_124_binary_tree_maximum_path_sum

#include "curated_string_125_valid_palindrome.cpp"

namespace p_curated_string_125_valid_palindrome
{
    using Solution = Solution;

    TEST(test__curated_string_125_valid_palindrome, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "A man, a plan, a canal: Panama";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "race a car";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "aa";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_Customize_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "ab";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "a";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_125_valid_palindrome, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input = "Marge, let's \"[went].\" I await {news} telegram.";
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_125_valid_palindrome

#include "127.cpp"

namespace p_127
{
    using Solution = Solution;

    TEST(test__127, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_beginWord = "hit";
        std::string input_endWord = "cog";
        std::vector<std::string> input_wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
        RetsultType result = s.ladderLength(input_beginWord, input_endWord, input_wordList);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__127, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_beginWord = "hit";
        std::string input_endWord = "cog";
        std::vector<std::string> input_wordList = { "hot", "dot", "dog", "lot", "log" };
        RetsultType result = s.ladderLength(input_beginWord, input_endWord, input_wordList);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__127, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input_beginWord = "red";
        std::string input_endWord = "tax";
        std::vector<std::string> input_wordList = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };
        RetsultType result = s.ladderLength(input_beginWord, input_endWord, input_wordList);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_127

#include "curated_graph_128_longest_consecutive_sequence.cpp"

namespace p_curated_graph_128_longest_consecutive_sequence
{
    using Solution = Solution;

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 100,4,200,1,3,2 };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_2)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 0,3,7,2,5,8,4,6,0,1 };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 9;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_Custimize_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_Custimize_2)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1, 2, 3 };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_Custimize_3)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 3, 2, 1 };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_128_longest_consecutive_sequence, Case_Failure_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1,0,-1 };
        RetsultType result = s.longestConsecutive(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_graph_128_longest_consecutive_sequence

#include "130.cpp"

namespace p_130
{
    using Solution = Solution;

    TEST(test__130, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'} };
        s.solve(input);
        RetsultType expect = { {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'X'} };
        s.solve(input);
        RetsultType expect = { {'X'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'O'} };
        s.solve(input);
        RetsultType expect = { {'O'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Customize_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'X', 'X', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'} };
        s.solve(input);
        RetsultType expect = { {'X', 'X', 'X'}, {'X', 'X', 'X'}, {'X', 'X', 'X'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Customize_3)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'O', 'X', 'O'}, {'X', 'O', 'X'}, {'O', 'X', 'O'} };
        s.solve(input);
        RetsultType expect = { {'O', 'X', 'O'}, {'X', 'X', 'X'}, {'O', 'X', 'O'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Customize_4)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'X', 'O', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'} };
        s.solve(input);
        RetsultType expect = { {'X', 'O', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Customize_5)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} };
        s.solve(input);
        RetsultType expect = { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', 'X'} };
        s.solve(input);
        RetsultType expect = { {'X', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', 'X'} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__130, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<char>>;

        std::vector<std::vector<char>> input = { {'O', 'X', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'O', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'O'}, {'X', 'X', 'O', 'X', 'O'} };
        s.solve(input);
        RetsultType expect = { {'O', 'X', 'X', 'O', 'X'}, {'X', 'X', 'X', 'X', 'O'}, {'X', 'X', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'O'}, {'X', 'X', 'O', 'X', 'O'} };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_130

#include "131.cpp"

namespace p_131
{
    using Solution = Solution;

    TEST(test__131, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::string input = "aab";
        RetsultType result = s.partition(input);
        RetsultType expect = { {"a", "a", "b"}, {"aa", "b"} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__131, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::string input = "a";
        RetsultType result = s.partition(input);
        RetsultType expect = { {"a"} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__131, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::string input = "efe";
        RetsultType result = s.partition(input);
        RetsultType expect = { {"e", "f", "e"}, {"efe"} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__131, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<std::string>>;

        std::string input = "abbab";
        RetsultType result = s.partition(input);
        RetsultType expect = { {"a", "b", "b", "a", "b"}, {"a", "b", "bab"}, {"a", "bb", "a", "b"}, {"abba", "b"} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_131

#include "curated_graph_133_clone_graph.cpp"

namespace p_curated_graph_133_clone_graph
{
    using Solution = Solution;

    TEST(test__curated_graph_133_clone_graph, Case_1)
    {
        Solution s;
        using InputType = Node*;
        using RetsultType = Node*;

        InputType input = GraphHelper::create({ {2,4},{1,3},{2,4},{1,3} });
        RetsultType result = s.cloneGraph(input);
        RetsultType expect = GraphHelper::create({ {2,4},{1,3},{2,4},{1,3} });
        ASSERT_THAT(GraphHelper::compare(result, expect), Eq(true));
    }

    TEST(test__curated_graph_133_clone_graph, Case_2)
    {
        Solution s;
        using InputType = Node*;
        using RetsultType = Node*;

        InputType input = GraphHelper::create({ {} });
        RetsultType result = s.cloneGraph(input);
        RetsultType expect = GraphHelper::create({ {} });
        ASSERT_THAT(GraphHelper::compare(result, expect), Eq(true));
    }

    TEST(test__curated_graph_133_clone_graph, Case_3)
    {
        Solution s;
        using InputType = Node*;
        using RetsultType = Node*;

        InputType input = GraphHelper::create({ });
        RetsultType result = s.cloneGraph(input);
        RetsultType expect = GraphHelper::create({ });
        ASSERT_THAT(GraphHelper::compare(result, expect), Eq(true));
    }
} // namespace p_curated_graph_133_clone_graph

#include "134.cpp"

namespace p_134
{
    using Solution = Solution;

    TEST(test__134, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_gas = { 1,2,3,4,5 };
        std::vector<int> input_cost = { 3,4,5,1,2 };
        RetsultType result = s.canCompleteCircuit(input_gas, input_cost);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__134, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_gas = { 2,3,4 };
        std::vector<int> input_cost = { 3,4,3 };
        RetsultType result = s.canCompleteCircuit(input_gas, input_cost);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__134, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_gas = { 11, 1, 0 };
        std::vector<int> input_cost = { 1, 11, 0 };
        RetsultType result = s.canCompleteCircuit(input_gas, input_cost);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__134, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_gas = { 2 };
        std::vector<int> input_cost = { 2 };
        RetsultType result = s.canCompleteCircuit(input_gas, input_cost);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_134

#include "136.cpp"

namespace p_136
{
    using Solution = Solution;

    TEST(test__136, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,2,1 };
        RetsultType result = s.singleNumber(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__136, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 4,1,2,1,2 };
        RetsultType result = s.singleNumber(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__136, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1 };
        RetsultType result = s.singleNumber(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_136

#include "137.cpp"

namespace p_137
{
    using Solution = Solution;

    TEST(test__137, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,2,3,2 };
        RetsultType result = s.singleNumber(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__137, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 0,1,0,1,0,1,99 };
        RetsultType result = s.singleNumber(input);
        RetsultType expect = 99;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_137

#include "138.cpp"

namespace p_138
{
    using Solution = Solution;

    TEST(test__138, Case_1)
    {
        Solution s;
        using RetsultType = Node*;

        Node* input = nullptr; // NodeHelper::create({{7,null],{13,0},{11,4},{10,2},{1,0}});
        RetsultType result = s.copyRandomList(input);
        RetsultType expect = nullptr; // NodeHelper::create({{7,null],{13,0},{11,4},{10,2},{1,0}});

        // FIXME: Mock comparison due to lack of NodeHelper
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__138, Case_2)
    {
        Solution s;
        using RetsultType = Node*;

        Node* input = nullptr; // NodeHelper::create({{1,1},{2,1}});
        RetsultType result = s.copyRandomList(input);
        RetsultType expect = nullptr; // NodeHelper::create({{1,1},{2,1}});

        // FIXME: Mock comparison due to lack of NodeHelper
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__138, Case_3)
    {
        Solution s;
        using RetsultType = Node*;

        Node* input = nullptr; // NodeHelper::create({{3,null},{3,0},{3,null}});
        RetsultType result = s.copyRandomList(input);
        RetsultType expect = nullptr; // NodeHelper::create({{3,null},{3,0},{3,null}});

        // FIXME: Mock comparison due to lack of NodeHelper
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_138

#include "curated_dp_139_word_break.cpp"

namespace p_curated_dp_139_word_break
{
    using Solution = Solution;

    TEST(test__curated_dp_139_word_break, Case_1)
    {
        Solution s;
        std::string input_s = "leetcode";
        std::vector<std::string> input_wordDict = { "leet","code" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_139_word_break, Case_2)
    {
        Solution s;
        std::string input_s = "applepenapple";
        std::vector<std::string> input_wordDict = { "apple","pen" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_139_word_break, Case_3)
    {
        Solution s;
        std::string input_s = "catsandog";
        std::vector<std::string> input_wordDict = { "cats","dog","sand","and","cat" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_139_word_break, Case_Customize_1)
    {
        Solution s;
        std::string input_s = "s";
        std::vector<std::string> input_wordDict = { "ss" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_139_word_break, Case_Customize_2)
    {
        Solution s;
        std::string input_s = "ssssss";
        std::vector<std::string> input_wordDict = { "ss" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_139_word_break, Case_Customize_3)
    {
        Solution s;
        std::string input_s = "a";
        std::vector<std::string> input_wordDict = { "a" };
        bool result = s.wordBreak(input_s, input_wordDict);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_139_word_break

#include "140.cpp"

namespace p_140
{
    using Solution = Solution;

    TEST(test__140, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input_s = "catsanddog";
        std::vector<std::string> input_wordDict = { "cat", "cats", "and", "sand", "dog" };
        RetsultType result = s.wordBreak(input_s, input_wordDict);
        RetsultType expect = { "cat sand dog", "cats and dog" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__140, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input_s = "pineapplepenapple";
        std::vector<std::string> input_wordDict = { "apple","pen","applepen","pine","pineapple" };
        RetsultType result = s.wordBreak(input_s, input_wordDict);
        RetsultType expect = { "pine apple pen apple","pine applepen apple","pineapple pen apple" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__140, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input_s = "catsandog";
        std::vector<std::string> input_wordDict = { "cats","dog","sand","and","cat" };
        RetsultType result = s.wordBreak(input_s, input_wordDict);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_140

#include "curated_linkedlist_141_linked_list_cycle.cpp"

namespace p_curated_linkedlist_141_linked_list_cycle
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_141_linked_list_cycle, Case_1)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = bool;

        InputType head = ListHelper::create({ 3,2,0,-4 });
        InputType tail = ListHelper::get_tail(head);
        InputType input = ListHelper::add_loop(head, tail, 1);

        RetsultType result = s.hasCycle(input);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);

        // FIXME: Can not remove a list with loop so far.
        // ListHelper::remove(head);
    }

    TEST(test__curated_linkedlist_141_linked_list_cycle, Case_2)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = bool;

        InputType head = ListHelper::create({ 1, 2 });
        InputType tail = ListHelper::get_tail(head);
        InputType input = ListHelper::add_loop(head, tail, 0);

        RetsultType result = s.hasCycle(input);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);

        // FIXME: Can not remove a list with loop so far.
        // ListHelper::remove(head);
    }

    TEST(test__curated_linkedlist_141_linked_list_cycle, Case_3)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = bool;

        InputType head = ListHelper::create({ 1 });
        InputType tail = ListHelper::get_tail(head);
        InputType input = ListHelper::add_loop(head, tail, -1);

        RetsultType result = s.hasCycle(input);
        RetsultType expect = false;
        ASSERT_EQ(result, expect);

        // FIXME: Can not remove a list with loop so far.
        // ListHelper::remove(head);
    }
} // namespace p_curated_linkedlist_141_linked_list_cycle

#include "curated_linkedlist_143_reorder_list.cpp"

namespace p_curated_linkedlist_143_reorder_list
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_143_reorder_list, Case_1)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = ListNode*;

        InputType input = ListHelper::create({ 1,2,3,4 });
        s.reorderList(input);
        RetsultType expect = ListHelper::create({ 1,4,2,3 });
        ASSERT_THAT(ListHelper::compare(input, expect), Eq(true));

        ListHelper::remove(input);
        ListHelper::remove(expect);
    }

    TEST(test__curated_linkedlist_143_reorder_list, Case_2)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = ListNode*;

        InputType input = ListHelper::create({ 1,2,3,4,5 });
        s.reorderList(input);
        RetsultType expect = ListHelper::create({ 1,5,2,4,3 });
        ASSERT_THAT(ListHelper::compare(input, expect), Eq(true));

        ListHelper::remove(input);
        ListHelper::remove(expect);
    }
} // namespace p_curated_linkedlist_143_reorder_list

#include "146.cpp"

namespace p_146
{
    TEST(test__146, Case_1)
    {
        LRUCache lru(2);

        int ret;

        lru.put(1, 1);
        lru.put(2, 2);
        ret = lru.get(1);
        ASSERT_THAT(ret == 1, Eq(true));
        lru.put(3, 3);
        ret = lru.get(2);
        ASSERT_THAT(ret == -1, Eq(true));
        lru.put(4, 4);
        ret = lru.get(1);
        ASSERT_THAT(ret == -1, Eq(true));
        ret = lru.get(3);
        ASSERT_THAT(ret == 3, Eq(true));
        ret = lru.get(4);
        ASSERT_THAT(ret == 4, Eq(true));
    }

    TEST(test__146, Case_Runtime_1)
    {
        LRUCache lru(2);

        int ret;

        lru.put(2, 1);
        ret = lru.get(2);
        ASSERT_THAT(ret == 1, Eq(true));
    }

    TEST(test__146, Case_Runtime_2)
    {
        LRUCache lru(1);

        int ret;

        lru.put(2, 1);
        ret = lru.get(2);
        ASSERT_THAT(ret == 1, Eq(true));
        lru.put(3, 2);
        ret = lru.get(2);
        ASSERT_THAT(ret == -1, Eq(true));
        ret = lru.get(3);
        ASSERT_THAT(ret == 2, Eq(true));
    }

    TEST(test__146, Case_Runtime_3)
    {
        LRUCache lru(3);

        int ret;

        lru.put(1, 1);
        lru.put(2, 2);
        lru.put(3, 3);
        lru.put(4, 4);
        ASSERT_THAT(lru.get(4) == 4, Eq(true));
        ASSERT_THAT(lru.get(3) == 3, Eq(true));
        ASSERT_THAT(lru.get(2) == 2, Eq(true));
        ASSERT_THAT(lru.get(1) == -1, Eq(true));
        lru.put(5, 5);
        ASSERT_THAT(lru.get(1) == -1, Eq(true));
        ASSERT_THAT(lru.get(2) == 2, Eq(true));
        ASSERT_THAT(lru.get(3) == 3, Eq(true));
        ASSERT_THAT(lru.get(4) == -1, Eq(true));
        ASSERT_THAT(lru.get(5) == 5, Eq(true));

    }
} // namespace p_146

#include "148.cpp"

namespace p_148
{
    using Solution = Solution;

    TEST(test__148, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 4,2,1,3 });
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({ 1,2,3,4 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__148, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ -1,5,3,4,0 });
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({ -1,0,3,4,5 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__148, Case_3)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({});
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({});;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__148, Case_Customize_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 1,2,3,4 });
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({ 1,2,3,4 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__148, Case_Customize_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 4,3,2,1 });
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({ 1,2,3,4 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__148, Case_Failure_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input = ListHelper::create({ 4, 19, 14, 5, -3, 1, 8, 5, 11, 15 });
        RetsultType result = s.sortList(input);
        RetsultType expect = ListHelper::create({ -3, 1, 4, 5, 5, 8, 11, 14, 15, 19 });;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }
} // namespace p_148

#include "149.cpp"

namespace p_149
{
    using Solution = Solution;

    TEST(test__149, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {1, 1}, {2, 2}, {3, 3} };
        RetsultType result = s.maxPoints(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__149, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4} };
        RetsultType result = s.maxPoints(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__149, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {0, 1}, {0, 0}, {0, 4}, {0, -2}, {0, -1}, {0, 3}, {0, -4} };
        RetsultType result = s.maxPoints(input);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_149

#include "150.cpp"

namespace p_150
{
    using Solution = Solution;

    TEST(test__150, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::string> input = { "2","1","+","3","*" };
        RetsultType result = s.evalRPN(input);
        RetsultType expect = 9;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__150, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::string> input = { "4","13","5","/","+" };
        RetsultType result = s.evalRPN(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__150, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::string> input = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
        RetsultType result = s.evalRPN(input);
        RetsultType expect = 22;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_150

#include "curated_array_152_max_product_subarray.cpp"

namespace p_curated_array_152_max_product_subarray
{
    using Solution = Solution;

    TEST(test__curated_array_152_max_product_subarray, Case_1)
    {
        Solution s;
        std::vector<int> input = { 2,3,-2,4 };
        int result = s.maxProduct(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_2)
    {
        Solution s;
        std::vector<int> input = { -2,0,-1 };
        int result = s.maxProduct(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { -2,-1, -1, -1, 5 };
        int result = s.maxProduct(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { -2,-1, 1, 1, 5 };
        int result = s.maxProduct(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Customize_3)
    {
        Solution s;
        std::vector<int> input = { -2, 1, 1, 1, 5 };
        int result = s.maxProduct(input);
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Customize_4)
    {
        Solution s;
        std::vector<int> input = { 2, 1, 1, 1, -5 };
        int result = s.maxProduct(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Customize_5)
    {
        Solution s;
        std::vector<int> input = { 2, 1, 1, -1, -5 };
        int result = s.maxProduct(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 2,-5,-2,-4,3 };
        int result = s.maxProduct(input);
        int expect = 24;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_152_max_product_subarray, Case_Failure_2)
    {
        Solution s;
        std::vector<int> input = { 0, 2 };
        int result = s.maxProduct(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
    TEST(test__curated_array_152_max_product_subarray, Case_Failure_3)
    {
        Solution s;
        std::vector<int> input = { -1, -2, -3, 0 };
        int result = s.maxProduct(input);
        int expect = 6;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_152_max_product_subarray

#include "curated_array_153_min_in_rotated_sorted_array.cpp"

namespace p_curated_array_153_min_in_rotated_sorted_array
{
    using Solution = Solution;

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_1)
    {
        Solution s;
        std::vector<int> input = { 3,4,5,1,2 };
        int result = s.findMin(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_2)
    {
        Solution s;
        std::vector<int> input = { 4,5,6,7,0,1,2 };
        int result = s.findMin(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_3)
    {
        Solution s;
        std::vector<int> input = { 11,13,15,17 };
        int result = s.findMin(input);
        int expect = 11;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 2,3,4,5,1 };
        int result = s.findMin(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { 5,1,2,3,4 };
        int result = s.findMin(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_array_153_min_in_rotated_sorted_array, Case_Rumtime_1)
    {
        Solution s;
        std::vector<int> input = { 1 };
        int result = s.findMin(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_153_min_in_rotated_sorted_array

#include "155.cpp"

namespace p_155
{
    TEST(test__155, Case_1)
    {
        MinStack ms;
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        ASSERT_THAT(ms.getMin() == -3, Eq(true));
        ms.pop();
        ASSERT_THAT(ms.top() == 0, Eq(true));
        ASSERT_THAT(ms.getMin() == -2, Eq(true));
    }
} // namespace p_155

#include "160.cpp"

namespace p_160
{
    using Solution = Solution;

    TEST(test__160, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input_headA = ListHelper::create({ 4,1 });
        ListNode* input_headB = ListHelper::create({ 5,6,1 });
        ListNode* part_common = ListHelper::create({ 8,4,5 });
        ListNode* partA_tail = ListHelper::get_tail(input_headA);
        ListNode* partB_tail = ListHelper::get_tail(input_headB);
        partA_tail->next = part_common;
        partB_tail->next = part_common;

        RetsultType result = s.getIntersectionNode(input_headA, input_headB);
        RetsultType expect = part_common;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // FIXME: No way to free two head list
        // ListHelper::remove(input_headA);
        // ListHelper::remove(input_headB);
    }

    TEST(test__160, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input_headA = ListHelper::create({ 1,9,1 });
        ListNode* input_headB = ListHelper::create({ 3 });
        ListNode* part_common = ListHelper::create({ 2,4 });
        ListNode* partA_tail = ListHelper::get_tail(input_headA);
        ListNode* partB_tail = ListHelper::get_tail(input_headB);
        partA_tail->next = part_common;
        partB_tail->next = part_common;

        RetsultType result = s.getIntersectionNode(input_headA, input_headB);
        RetsultType expect = part_common;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // FIXME: No way to free two head list
        // ListHelper::remove(input_headA);
        // ListHelper::remove(input_headB);
    }

    TEST(test__160, Case_3)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* input_headA = ListHelper::create({ 2,6,4 });
        ListNode* input_headB = ListHelper::create({ 1,5 });
        ListNode* part_common = ListHelper::create({});
        ListNode* partA_tail = ListHelper::get_tail(input_headA);
        ListNode* partB_tail = ListHelper::get_tail(input_headB);
        partA_tail->next = part_common;
        partB_tail->next = part_common;

        RetsultType result = s.getIntersectionNode(input_headA, input_headB);
        RetsultType expect = part_common;
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        // FIXME: No way to free two head list
        // ListHelper::remove(input_headA);
        // ListHelper::remove(input_headB);
    }
} // namespace p_160

#include "162.cpp"

namespace p_162
{
    using Solution = Solution;

    TEST(test__162, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,2,3,1 };
        RetsultType result = s.findPeakElement(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__162, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,2,1,3,5,6,4 };
        RetsultType result = s.findPeakElement(input);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_162

#include "163.cpp"

namespace p_163
{
    using Solution = Solution;

    TEST(test__163, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<int> input_nums = { 0,1,3,50,75 };
        int input_lower = 0;
        int input_upper = 99;
        RetsultType result = s.findMissingRanges(input_nums, input_lower, input_upper);
        RetsultType expect = { "2","4->49","51->74","76->99" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__163, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<int> input_nums = { -1 };
        int input_lower = -1;
        int input_upper = -1;
        RetsultType result = s.findMissingRanges(input_nums, input_lower, input_upper);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_163

#include "166.cpp"

namespace p_166
{
    using Solution = Solution;

    TEST(test__166, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 1;
        int input_denominator = 2;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "0.5";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 2;
        int input_denominator = 1;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "2";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_3)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 4;
        int input_denominator = 333;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "0.(012)";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 1;
        int input_denominator = -2;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "-0.5";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 1;
        int input_denominator = 6;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "0.1(6)";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = -50;
        int input_denominator = 8;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "-6.25";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_Failure_3)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = 0;
        int input_denominator = -5;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "0";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__166, Case_Failure_4)
    {
        Solution s;
        using RetsultType = std::string;

        int input_numerator = -2147483648;
        int input_denominator = 1;
        RetsultType result = s.fractionToDecimal(input_numerator, input_denominator);
        RetsultType expect = "-2147483648";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_166

#include "169.cpp"

namespace p_169
{
    using Solution = Solution;

    TEST(test__169, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 3,2,3 };
        RetsultType result = s.majorityElement(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__169, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,2,1,1,1,2,2 };
        RetsultType result = s.majorityElement(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_169

#include "171.cpp"

namespace p_171
{
    using Solution = Solution;

    TEST(test__171, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "A";
        RetsultType result = s.titleToNumber(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__171, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "AB";
        RetsultType result = s.titleToNumber(input);
        RetsultType expect = 28;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__171, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "ZY";
        RetsultType result = s.titleToNumber(input);
        RetsultType expect = 701;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__171, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "FXSHRXW";
        RetsultType result = s.titleToNumber(input);
        RetsultType expect = 2147483647;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_171

#include "172.cpp"

namespace p_172
{
    using Solution = Solution;

    TEST(test__172, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 3;
        RetsultType result = s.trailingZeroes(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__172, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 5;
        RetsultType result = s.trailingZeroes(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__172, Case_3)
    {
        Solution s;
        using RetsultType = int;

        int input = 0;
        RetsultType result = s.trailingZeroes(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__172, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 5000;
        RetsultType result = s.trailingZeroes(input);
        RetsultType expect = 1249;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__172, Case_Customize_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 10000;
        RetsultType result = s.trailingZeroes(input);
        RetsultType expect = 2499;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_172

#include "179.cpp"

namespace p_179
{
    using Solution = Solution;

    TEST(test__179, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 10,2 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "210";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__179, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 3,30,34,5,9 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "9534330";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__179, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 3,30,32,5,9 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "9533230";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__179, Case_Customize_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 12,12 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "1212";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__179, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 34323, 3432 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "343234323";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__179, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<int> input = { 0, 0 };
        RetsultType result = s.largestNumber(input);
        RetsultType expect = "0";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_179

#include "189.cpp"

namespace p_189
{
    using Solution = Solution;

    TEST(test__189, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 1,2,3,4,5,6,7 };
        int input_k = 3;
        s.rotate(input_nums, input_k);
        RetsultType expect = { 5,6,7,1,2,3,4 };
        ASSERT_THAT(input_nums == expect, Eq(true));
    }

    TEST(test__189, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { -1,-100,3,99 };
        int input_k = 2;
        s.rotate(input_nums, input_k);
        RetsultType expect = { 3,99,-1,-100 };
        ASSERT_THAT(input_nums == expect, Eq(true));
    }
} // namespace p_189

#include "curated_binary_190_reverse_bits.cpp"

namespace p_curated_binary_190_reverse_bits
{
    using Solution = Solution;

    TEST(test__curated_binary_190_reverse_bits, Case_1)
    {
        Solution s;
        uint32_t input = 0b00000010100101000001111010011100;
        uint32_t result = s.reverseBits(input);
        uint32_t expect = 0b00111001011110000010100101000000;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_190_reverse_bits, Case_2)
    {
        Solution s;
        uint32_t input = 0b11111111111111111111111111111101;
        uint32_t result = s.reverseBits(input);
        uint32_t expect = 0b10111111111111111111111111111111;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_binary_190_reverse_bits

#include "curated_binary_191_numbers_of_1_bits.cpp"

namespace p_curated_binary_191_numbers_of_1_bits
{
    using Solution = Solution;

    TEST(test__curated_binary_191_numbers_of_1_bits, Case_1)
    {
        Solution s;
        uint32_t input = 0b00000000000000000000000000001011;
        int result = s.hammingWeight(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_191_numbers_of_1_bits, Case_2)
    {
        Solution s;
        uint32_t input = 0b00000000000000000000000010000000;
        int result = s.hammingWeight(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_191_numbers_of_1_bits, Case_3)
    {
        Solution s;
        uint32_t input = 0b11111111111111111111111111111101;
        int result = s.hammingWeight(input);
        int expect = 31;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_191_numbers_of_1_bits, Case_Customize_1)
    {
        Solution s;
        uint32_t input = 0b00000000000000000000000000000000;
        int result = s.hammingWeight(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_191_numbers_of_1_bits, Case_Customize_2)
    {
        Solution s;
        uint32_t input = 0b11111111111111111111111111111111;
        int result = s.hammingWeight(input);
        int expect = 32;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_binary_191_numbers_of_1_bits

#include "curated_dp_198_house_robber.cpp"

namespace p_curated_dp_198_house_robber
{
    using Solution = Solution;

    TEST(test__curated_dp_198_house_robber, Case_1)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,1 };
        int result = s.rob(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_2)
    {
        Solution s;
        std::vector<int> input = { 2,7,9,3,1 };
        int result = s.rob(input);
        int expect = 12;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,4,100 };
        int result = s.rob(input);
        int expect = 104;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,100,4 };
        int result = s.rob(input);
        int expect = 102;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Customize_3)
    {
        Solution s;
        std::vector<int> input = { 101,2,3,100,4 };
        int result = s.rob(input);
        int expect = 201;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Customize_4)
    {
        Solution s;
        std::vector<int> input = { 101,2,3,4,100 };
        int result = s.rob(input);
        int expect = 204;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Customize_5)
    {
        Solution s;
        std::vector<int> input = { 1 };
        int result = s.rob(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_198_house_robber, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 2, 1 };
        int result = s.rob(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_198_house_robber

#include "curated_graph_200_number_of_islands.cpp"

namespace p_curated_graph_200_number_of_islands
{
    using Solution = Solution;

    TEST(test__curated_graph_200_number_of_islands, Case_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_200_number_of_islands, Case_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'1','1','0','0','0'} ,
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_200_number_of_islands, Case_Customize_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'1','1','0'} ,
            {'1','1','0'},
            {'0','0','1'},
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_200_number_of_islands, Case_Customize_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'1','0','0'} ,
            {'0','1','0'},
            {'0','0','1'},
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_200_number_of_islands, Case_Customize_3)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'1','1','1'} ,
            {'1','1','1'},
            {'1','1','1'},
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_200_number_of_islands, Case_Customize_4)
    {
        Solution s;
        using InputType = std::vector<std::vector<char>>;
        using RetsultType = int;

        InputType input = {
            {'0','0','0'} ,
            {'0','0','0'},
            {'0','0','0'},
        };
        RetsultType result = s.numIslands(input);
        RetsultType expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_graph_200_number_of_islands

#include "202.cpp"

namespace p_202
{
    using Solution = Solution;

    TEST(test__202, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        int input = 19;
        RetsultType result = s.isHappy(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__202, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        int input = 2;
        RetsultType result = s.isHappy(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_202

#include "204.cpp"

namespace p_204
{
    using Solution = Solution;

    TEST(test__204, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 10;
        RetsultType result = s.countPrimes(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__204, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 0;
        RetsultType result = s.countPrimes(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__204, Case_3)
    {
        Solution s;
        using RetsultType = int;

        int input = 1;
        RetsultType result = s.countPrimes(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    //TEST(test__204, Case_Customize_1)
    //{
    //    Solution s;
    //    using RetsultType = int;
    //
    //    int input = 5000000;
    //    RetsultType result = s.countPrimes(input);
    //    RetsultType expect = 348513;
    //    ASSERT_THAT(result == expect, Eq(true));
    //}
} // namespace p_204

#include "curated_linkedlist_206_reverse_linked_list.cpp"

namespace p_curated_linkedlist_206_reverse_linked_list
{
    using Solution = Solution;

    TEST(test__curated_linkedlist_206_reverse_linked_list, Case_1)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = ListNode*;

        InputType input = ListHelper::create({ 1,2,3,4,5 });
        RetsultType result = s.reverseList(input);
        RetsultType expect = ListHelper::create({ 5,4,3,2,1 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_linkedlist_206_reverse_linked_list, Case_2)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = ListNode*;

        InputType input = ListHelper::create({ 1,2 });
        RetsultType result = s.reverseList(input);
        RetsultType expect = ListHelper::create({ 2, 1 });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }

    TEST(test__curated_linkedlist_206_reverse_linked_list, Case_3)
    {
        Solution s;
        using InputType = ListNode*;
        using RetsultType = ListNode*;

        InputType input = ListHelper::create({ });
        RetsultType result = s.reverseList(input);
        RetsultType expect = ListHelper::create({ });
        ASSERT_THAT(ListHelper::compare(result, expect), Eq(true));

        ListHelper::remove(result);
        ListHelper::remove(expect);
    }
} // namespace p_curated_linkedlist_206_reverse_linked_list

#include "curated_graph_207_course_schedule.cpp"

namespace p_curated_graph_207_course_schedule
{
    using Solution = Solution;

    TEST(test__curated_graph_207_course_schedule, Case_1)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 2;
        InputType_2 input_prerequisites = { { 1,0 } };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_2)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 2;
        InputType_2 input_prerequisites = { {1,0} ,{0,1} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_1)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 2;
        InputType_2 input_prerequisites = { {0,1} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_2)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 1;
        InputType_2 input_prerequisites = { };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_3)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 3;
        InputType_2 input_prerequisites = { };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_4)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 3;
        InputType_2 input_prerequisites = { {1, 0}, {2, 1} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_5)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 3;
        InputType_2 input_prerequisites = { {1, 0}, {1, 2}, {0, 2}, {2, 0} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Customize_6)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;

        InputType_1 input_numCourses = 3;
        InputType_2 input_prerequisites = { {0, 1}, {1, 2} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Failure_1)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;
        InputType_1 input_numCourses = 20;
        InputType_2 input_prerequisites = { {0, 10},{3, 18},{5, 5},{6, 11},{11, 14},{13, 1},{15, 1},{17, 4} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_207_course_schedule, Case_Failure_2)
    {
        Solution s;
        using InputType_1 = int;
        using InputType_2 = std::vector<std::vector<int>>;
        using RetsultType = bool;
        InputType_1 input_numCourses = 3;
        InputType_2 input_prerequisites = { {0, 2} ,{1, 2},{2, 0} };
        RetsultType result = s.canFinish(input_numCourses, input_prerequisites);
        RetsultType expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_graph_207_course_schedule

#include "curated_tree_208_implement_trie_or_prefix_tree.cpp"

namespace p_curated_tree_208_implement_trie_or_prefix_tree
{
    using Solution = Trie;

    TEST(test__curated_tree_208_implement_trie_or_prefix_tree, Case_1)
    {
        Solution trie;
        trie.insert("apple");
        ASSERT_THAT(trie.search("apple"), Eq(true));
        ASSERT_THAT(trie.search("app"), Eq(false));
        ASSERT_THAT(trie.startsWith("app"), Eq(true));
        trie.insert("app");
        ASSERT_THAT(trie.search("app"), Eq(true));
    }

    TEST(test__curated_tree_208_implement_trie_or_prefix_tree, Case_Failure_1)
    {
        Solution trie;
        trie.insert("hello");
        ASSERT_THAT(trie.search("hell"), Eq(false));
        ASSERT_THAT(trie.search("helloa"), Eq(false));
        ASSERT_THAT(trie.search("hello"), Eq(true));
        ASSERT_THAT(trie.startsWith("hell"), Eq(true));
        ASSERT_THAT(trie.startsWith("helloa"), Eq(false));
        ASSERT_THAT(trie.startsWith("hello"), Eq(true));
    }
} // namespace p_curated_tree_208_implement_trie_or_prefix_tree

#include "210.cpp"

namespace p_210
{
    using Solution = Solution;

    TEST(test__210, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numCourses = 2;
        std::vector<std::vector<int>> input_prerequisites = { {1, 0} };
        RetsultType result = s.findOrder(input_numCourses, input_prerequisites);
        RetsultType expect = { 0,1 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__210, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numCourses = 4;
        std::vector<std::vector<int>> input_prerequisites = { {1,0},{2,0},{3,1},{3,2} };
        RetsultType result = s.findOrder(input_numCourses, input_prerequisites);
        RetsultType expect = { 0,1,2,3 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__210, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numCourses = 1;
        std::vector<std::vector<int>> input_prerequisites = { };
        RetsultType result = s.findOrder(input_numCourses, input_prerequisites);
        RetsultType expect = { 0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__210, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numCourses = 4;
        std::vector<std::vector<int>> input_prerequisites = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3} };
        RetsultType result = s.findOrder(input_numCourses, input_prerequisites);
        RetsultType expect = { 3, 2, 1, 0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__210, Case_Customize_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numCourses = 4;
        std::vector<std::vector<int>> input_prerequisites = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {3, 0} };
        RetsultType result = s.findOrder(input_numCourses, input_prerequisites);
        RetsultType expect = {};
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_210


#include "curated_tree_211_design_add_and_search_words_data_structure.cpp"

namespace p_curated_tree_211_design_add_and_search_words_data_structure
{
    using Solution = WordDictionary;

    TEST(test__curated_tree_211_design_add_and_search_words_data_structure, Case_1)
    {
        Solution word_dictionary;
        word_dictionary.addWord("bad");
        word_dictionary.addWord("dad");
        word_dictionary.addWord("mad");
        word_dictionary.addWord("madddd");
        ASSERT_THAT(word_dictionary.search("pad"), Eq(false));
        ASSERT_THAT(word_dictionary.search("bad"), Eq(true));
        ASSERT_THAT(word_dictionary.search(".ad"), Eq(true));
        ASSERT_THAT(word_dictionary.search("b.."), Eq(true));
        ASSERT_THAT(word_dictionary.search("m.."), Eq(true));
    }

    TEST(test__curated_tree_211_design_add_and_search_words_data_structure, Case_2)
    {
        Solution word_dictionary;
        word_dictionary.addWord("a");
        word_dictionary.addWord("a");
        ASSERT_THAT(word_dictionary.search("."), Eq(true));
        ASSERT_THAT(word_dictionary.search("a"), Eq(true));
        ASSERT_THAT(word_dictionary.search("aa"), Eq(false));
        ASSERT_THAT(word_dictionary.search("a"), Eq(true));
        ASSERT_THAT(word_dictionary.search(".a"), Eq(false));
        ASSERT_THAT(word_dictionary.search("a."), Eq(false));
    }
} // namespace p_curated_tree_211_design_add_and_search_words_data_structure

#include "curated_tree_212_word_search_ii.cpp"

namespace p_curated_tree_212_word_search_ii
{
    using Solution = Solution;

    TEST(test__curated_tree_212_word_search_ii, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<std::vector<char>> input_board = { {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'} };
        std::vector<std::string> input_words = { "oath", "pea", "eat", "rain" };
        RetsultType result = s.findWords(input_board, input_words);
        RetsultType expect = { "oath", "eat" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_212_word_search_ii, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::vector<std::vector<char>> input_board = { {'a', 'b'}, {'c', 'd'} };
        std::vector<std::string> input_words = { "abcb" };
        RetsultType result = s.findWords(input_board, input_words);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_tree_212_word_search_ii

#include "curated_dp_213_house_robber_ii.cpp"

namespace p_curated_dp_213_house_robber_ii
{
    using Solution = Solution;

    TEST(test__curated_dp_213_house_robber_ii, Case_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 2,3,2 };
        RetsultType result = s.rob(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_213_house_robber_ii, Case_2)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1,2,3,1 };
        RetsultType result = s.rob(input);
        RetsultType expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_213_house_robber_ii, Case_3)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1,2,3 };
        RetsultType result = s.rob(input);
        RetsultType expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_213_house_robber_ii, Case_Failure_1)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 200,3,140,20,10 };
        RetsultType result = s.rob(input);
        RetsultType expect = 340;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_213_house_robber_ii, Case_Failure_2)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1 };
        RetsultType result = s.rob(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_213_house_robber_ii, Case_Failure_3)
    {
        Solution s;
        using InputType = std::vector<int>;
        using RetsultType = int;

        InputType input = { 1, 2 };
        RetsultType result = s.rob(input);
        RetsultType expect = 2;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_213_house_robber_ii

#include "215.cpp"

namespace p_215
{
    using Solution = Solution;

    TEST(test__215, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 3,2,1,5,6,4 };
        int input_k = 2;
        RetsultType result = s.findKthLargest(input_nums, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__215, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 3,2,3,1,2,4,5,5,6 };
        int input_k = 4;
        RetsultType result = s.findKthLargest(input_nums, input_k);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_215

#include "curated_array_217_containduplicate.cpp"

namespace p_curated_array_217_containduplicate
{
    using Solution = Solution;

    TEST(test_curated_array_217_containduplicate, Case_1)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,1 };
        bool result = s.containsDuplicate(input);
        int expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_217_containduplicate, Case_2)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,4 };
        bool result = s.containsDuplicate(input);
        int expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_217_containduplicate, Case_3)
    {
        Solution s;
        std::vector<int> input = { 1,1,1,3,3,4,3,2,4,2 };
        bool result = s.containsDuplicate(input);
        int expect = true;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_217_containduplicate

#include "218.cpp"

namespace p_218
{
    using Solution = Solution;

    TEST(test__218, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
        RetsultType result = s.getSkyline(input);
        RetsultType expect = { {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__218, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {0, 2, 3}, {2, 5, 3} };
        RetsultType result = s.getSkyline(input);
        RetsultType expect = { {0, 3}, {5, 0} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__218, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {2, 9, 10}, {9, 12, 15} };
        RetsultType result = s.getSkyline(input);
        RetsultType expect = { {2, 10}, {9, 15}, {12, 0} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__218, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {2, 9, 10}, {9, 12, 5} };
        RetsultType result = s.getSkyline(input);
        RetsultType expect = { {2, 10}, {9, 5}, {12, 0} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_218

#include "curated_tree_226_invert_binary_tree.cpp"

namespace p_curated_tree_226_invert_binary_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_226_invert_binary_tree, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input = TreeHelper::create({ 4,2,7,1,3,6,9 }, {});
        RetsultType result = s.invertTree(input);
        RetsultType expect = TreeHelper::create({ 4,7,2,9,6,3,1 }, {});
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_226_invert_binary_tree, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input = TreeHelper::create({ 2,1,3 }, {});
        RetsultType result = s.invertTree(input);
        RetsultType expect = TreeHelper::create({ 2,3,1 }, {});
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_226_invert_binary_tree, Case_3)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input = TreeHelper::create({ }, {});
        RetsultType result = s.invertTree(input);
        RetsultType expect = TreeHelper::create({}, {});
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }
} // namespace p_curated_tree_226_invert_binary_tree

#include "227.cpp"

namespace p_227
{
    using Solution = Solution;

    TEST(test__227, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "3+2*2";
        RetsultType result = s.calculate(input);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__227, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "3/2";
        RetsultType result = s.calculate(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__227, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "3+5 / 2 ";
        RetsultType result = s.calculate(input);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__227, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "1-1+1";
        RetsultType result = s.calculate(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__227, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "0-2147483647";
        RetsultType result = s.calculate(input);
        RetsultType expect = -2147483647;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_227

#include "curated_tree_230_kth_smallest_element_in_a_bst.cpp"

namespace p_curated_tree_230_kth_smallest_element_in_a_bst
{
    using Solution = Solution;

    TEST(test__curated_tree_230_kth_smallest_element_in_a_bst, Case_1)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input_root = TreeHelper::create({ 3,1,4,-1,2 }, { true,true,true,false,true });
        int input_k = 1;
        RetsultType result = s.kthSmallest(input_root, input_k);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_root);
    }

    TEST(test__curated_tree_230_kth_smallest_element_in_a_bst, Case_2)
    {
        Solution s;
        using RetsultType = int;

        TreeNode* input_root = TreeHelper::create({ 5,3,6,2,4,-1,-1,1 }, { true,true,true,true,true,false,false,true });
        int input_k = 3;
        RetsultType result = s.kthSmallest(input_root, input_k);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_root);
    }
} // namespace p_curated_tree_230_kth_smallest_element_in_a_bst

#include "234.cpp"

namespace p_234
{
    using Solution = Solution;

    TEST(test__234, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        ListNode* input = ListHelper::create({ 1,2,2,1 });
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__234, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        ListNode* input = ListHelper::create({ 1,2 });
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__234, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        ListNode* input = ListHelper::create({ 1,2,3,2,1 });
        RetsultType result = s.isPalindrome(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_234

#include "curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree.cpp"

namespace p_curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create({ 6,2,8,0,4,7,9,-1,-1,3,5 }, { true,true,true,true,true,true,true,false,false,true,true });
        TreeNode* input_p = TreeHelper::create({ 2 }, {});
        TreeNode* input_q = TreeHelper::create({ 8 }, {});
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        RetsultType expect = TreeHelper::create({ 6 }, {});;
        ASSERT_THAT(result->val == expect->val, Eq(true));

        TreeHelper::remove(input_root);
        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create({ 6,2,8,0,4,7,9,-1,-1,3,5 }, { true,true,true,true,true,true,true,false,false,true,true });
        TreeNode* input_p = TreeHelper::create({ 2 }, {});
        TreeNode* input_q = TreeHelper::create({ 4 }, {});
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        RetsultType expect = TreeHelper::create({ 2 }, {});;
        ASSERT_THAT(result->val == expect->val, Eq(true));

        TreeHelper::remove(input_root);
        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
        TreeHelper::remove(expect);
    }

    TEST(test__curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree, Case_3)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create({ 2,1 }, { });
        TreeNode* input_p = TreeHelper::create({ 2 }, {});
        TreeNode* input_q = TreeHelper::create({ 1 }, {});
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        RetsultType expect = TreeHelper::create({ 2 }, {});;
        ASSERT_THAT(result->val == expect->val, Eq(true));

        TreeHelper::remove(input_root);
        TreeHelper::remove(input_p);
        TreeHelper::remove(input_q);
        TreeHelper::remove(expect);
    }
} // namespace p_curated_tree_235_lowest_common_ancestor_of_a_binary_search_tree

#include "236.cpp"

namespace p_236
{
    using Solution = Solution;

    TEST(test__236, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("3,5,1,6,2,0,8,null,null,7,4");
        std::vector<TreeNode*> elements_p = TreeHelper::findElements(input_root, 5);
        TreeNode* input_p = elements_p[0];
        std::vector<TreeNode*> elements_q = TreeHelper::findElements(input_root, 1);
        TreeNode* input_q = elements_q[0];
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        std::vector<TreeNode*> elements_expect = TreeHelper::findElements(input_root, 3);
        RetsultType expect = elements_expect[0];
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__236, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("3,5,1,6,2,0,8,null,null,7,4");
        std::vector<TreeNode*> elements_p = TreeHelper::findElements(input_root, 5);
        TreeNode* input_p = elements_p[0];
        std::vector<TreeNode*> elements_q = TreeHelper::findElements(input_root, 4);
        TreeNode* input_q = elements_q[0];
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        std::vector<TreeNode*> elements_expect = TreeHelper::findElements(input_root, 5);
        RetsultType expect = elements_expect[0];
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__236, Case_3)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("1,2");
        std::vector<TreeNode*> elements_p = TreeHelper::findElements(input_root, 1);
        TreeNode* input_p = elements_p[0];
        std::vector<TreeNode*> elements_q = TreeHelper::findElements(input_root, 2);
        TreeNode* input_q = elements_q[0];
        RetsultType result = s.lowestCommonAncestor(input_root, input_p, input_q);
        std::vector<TreeNode*> elements_expect = TreeHelper::findElements(input_root, 1);
        RetsultType expect = elements_expect[0];
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_236

#include "237.cpp"

namespace p_237
{
    using Solution = Solution;

    TEST(test__237, Case_1)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* head = ListHelper::create({ 4,5,1,9 });
        auto elements_input = ListHelper::getElements(head, 5);
        ListNode* input = elements_input[0];
        s.deleteNode(input);
        RetsultType expect = ListHelper::create({ 4,1,9 });
        ASSERT_THAT(ListHelper::compare(head, expect), Eq(true));

        ListHelper::remove(head);
        ListHelper::remove(expect);
    }

    TEST(test__237, Case_2)
    {
        Solution s;
        using RetsultType = ListNode*;

        ListNode* head = ListHelper::create({ 4,5,1,9 });
        auto elements_input = ListHelper::getElements(head, 1);
        ListNode* input = elements_input[0];
        s.deleteNode(input);
        RetsultType expect = ListHelper::create({ 4,5,9 });
        ASSERT_THAT(ListHelper::compare(head, expect), Eq(true));

        ListHelper::remove(head);
        ListHelper::remove(expect);
    }
} // namespace p_237

#include "curated_array_238_product_of_array_except_self.cpp"

namespace p_curated_array_238_product_of_array_except_self
{
    using Solution = Solution;

    TEST(test_curated_array_238_product_of_array_except_self, Case_1)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,4 };
        std::vector<int> result = s.productExceptSelf(input);
        std::vector<int> expect = { 24,12,8,6 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_238_product_of_array_except_self, Case_2)
    {
        Solution s;
        std::vector<int> input = { -1,1,0,-3,3 };
        std::vector<int> result = s.productExceptSelf(input);
        std::vector<int> expect = { 0,0,9,0,0 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_curated_array_238_product_of_array_except_self, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { -1,1,0,-3,0 };
        std::vector<int> result = s.productExceptSelf(input);
        std::vector<int> expect = { 0,0,0,0,0 };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_array_238_product_of_array_except_self

#include "239.cpp"

namespace p_239
{
    using Solution = Solution;

    TEST(test__239, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 1,3,-1,-3,5,3,6,7 };
        int input_k = 3;
        RetsultType result = s.maxSlidingWindow(input_nums, input_k);
        RetsultType expect = { 3,3,5,5,6,7 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__239, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 1 };
        int input_k = 1;
        RetsultType result = s.maxSlidingWindow(input_nums, input_k);
        RetsultType expect = { 1 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__239, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { -5769, -7887, -5709, 4600, -7919, 9807, 1303, -2644, 1144, -6410, -7159, -2041, 9059, -663, 4612, -257, 2870, -6646, 8161, 3380, 6823, 1871, -4030, -1758, 4834, -5317, 6218, -4105, 6869, 8595, 8718, -4141, -3893, -4259, -3440, -5426, 9766, -5396, -7824, -3941, 4600, -1485, -1486, -4530, -1636, -2088, -5295, -5383, 5786, -9489, 3180, -4575, -7043, -2153, 1123, 1750, -1347, -4299, -4401, -7772, 5872, 6144, -4953, -9934, 8507, 951, -8828, -5942, -3499, -174, 7629, 5877, 3338, 8899, 4223, -8068, 3775, 7954, 8740, 4567, 6280, -7687, -4811, -8094, 2209, -4476, -8328, 2385, -2156, 7028, -3864, 7272, -1199, -1397, 1581, -9635, 9087, -6262, -3061, -6083, -2825, -8574, 5534, 4006, -2691, 6699, 7558, -453, 3492, 3416, 2218, 7537, 8854, -3321, -5489, -945, 1302, -7176, -9201, -9588, -140, 1369, 3322, -7320, -8426, -8446, -2475, 8243, -3324, 8993, 8315, 2863, -7580, -7949, 4400 };
        int input_k = 6;
        RetsultType result = s.maxSlidingWindow(input_nums, input_k);
        RetsultType expect = { 9807,9807,9807,9807,9807,9807,1303,9059,9059,9059,9059,9059,9059,8161,8161,8161,8161,8161,8161,6823,6823,6218,6218,6869,8595,8718,8718,8718,8718,8718,8718,9766,9766,9766,9766,9766,9766,4600,4600,4600,4600,-1485,-1486,5786,5786,5786,5786,5786,5786,3180,3180,1750,1750,1750,1750,5872,6144,6144,6144,8507,8507,8507,8507,8507,8507,7629,7629,7629,8899,8899,8899,8899,8899,8899,8740,8740,8740,8740,8740,6280,6280,2209,2385,2385,7028,7028,7272,7272,7272,7272,7272,9087,9087,9087,9087,9087,9087,5534,5534,5534,6699,7558,7558,7558,7558,7558,7558,8854,8854,8854,8854,8854,8854,1302,1302,1302,1369,3322,3322,3322,3322,3322,8243,8243,8993,8993,8993,8993,8993,8993 };

        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_239

#include "240.cpp"

namespace p_240
{
    using Solution = Solution;

    TEST(test__240, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input_matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
        int input_target = 5;
        RetsultType result = s.searchMatrix(input_matrix, input_target);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__240, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input_matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
        int input_target = 20;
        RetsultType result = s.searchMatrix(input_matrix, input_target);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__240, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input_matrix = { {1} };
        int input_target = 1;
        RetsultType result = s.searchMatrix(input_matrix, input_target);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__240, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input_matrix = { {-1, 1} };
        int input_target = 0;
        RetsultType result = s.searchMatrix(input_matrix, input_target);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_240

#include "curated_string_242_valid_anagram.cpp"

namespace p_curated_string_242_valid_anagram
{
    using Solution = Solution;

    TEST(test__curated_string_242_valid_anagram, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "anagram";
        std::string input_t = "nagaram";
        RetsultType result = s.isAnagram(input_s, input_t);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_242_valid_anagram, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "rat";
        std::string input_t = "car";
        RetsultType result = s.isAnagram(input_s, input_t);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_242_valid_anagram, Case_Customize_1)
    {
        Solution s;
        using RetsultType = bool;

        std::string input_s = "ra";
        std::string input_t = "car";
        RetsultType result = s.isAnagram(input_s, input_t);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_242_valid_anagram

#include "251.cpp"

namespace p_251
{
    TEST(test__251, Case_1)
    {
        std::vector<std::vector<int>> vec({ {1, 2}, {3}, {4} });
        Vector2D v2d(vec);

        ASSERT_THAT(v2d.next() == 1, Eq(true));
        ASSERT_THAT(v2d.next() == 2, Eq(true));
        ASSERT_THAT(v2d.next() == 3, Eq(true));
        ASSERT_THAT(v2d.hasNext(), Eq(true));
        ASSERT_THAT(v2d.hasNext(), Eq(true));
        ASSERT_THAT(v2d.next() == 4, Eq(true));
        ASSERT_THAT(v2d.hasNext(), Eq(false));
    }
} // namespace p_251

#include "curated_interval_252_meeting_rooms.cpp"

namespace p_curated_interval_252_meeting_rooms
{
    using Solution = Solution;

    TEST(test__curated_interval_252_meeting_rooms, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input = { {0, 30}, {5, 10}, {15, 20} };
        RetsultType result = s.canAttendMeetings(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_interval_252_meeting_rooms, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input = { {7, 10}, {2, 4} };
        RetsultType result = s.canAttendMeetings(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_interval_252_meeting_rooms, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<std::vector<int>> input = { {9, 10}, { 4, 9 }, { 4, 17 } };
        RetsultType result = s.canAttendMeetings(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_interval_252_meeting_rooms

#include "curated_interval_253_meeting_rooms_ii.cpp"

namespace p_curated_interval_253_meeting_rooms_ii
{
    using Solution = Solution;

    TEST(test__curated_interval_253_meeting_rooms_ii, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {0, 30}, {5, 10}, {15, 20} };
        RetsultType result = s.minMeetingRooms(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_interval_253_meeting_rooms_ii, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {7, 10}, {2, 4} };
        RetsultType result = s.minMeetingRooms(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_interval_253_meeting_rooms_ii

#include "curated_graph_261_graph_valid_tree.cpp"

namespace p_curated_graph_261_graph_valid_tree
{
    using Solution = Solution;

    TEST(test__curated_graph_261_graph_valid_tree, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {0, 2}, {0, 3}, {1, 4} };
        RetsultType result = s.validTree(input_n, input_edges);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_261_graph_valid_tree, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
        RetsultType result = s.validTree(input_n, input_edges);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_261_graph_valid_tree, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        int input_n = 4;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {2, 3} };
        RetsultType result = s.validTree(input_n, input_edges);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_graph_261_graph_valid_tree

#include "curated_binary_268_missing_number.cpp"

namespace p_curated_binary_268_missing_number
{
    using Solution = Solution;

    TEST(test__curated_binary_268_missing_number, Case_1)
    {
        Solution s;
        std::vector<int> input = { 3,0,1 };
        int result = s.missingNumber(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_268_missing_number, Case_2)
    {
        Solution s;
        std::vector<int> input = { 0,1 };
        int result = s.missingNumber(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_268_missing_number, Case_3)
    {
        Solution s;
        std::vector<int> input = { 9,6,4,2,3,5,7,0,1 };
        int result = s.missingNumber(input);
        int expect = 8;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_binary_268_missing_number

#include "curated_graph_269_alien_dictionary.cpp"

namespace p_curated_graph_269_alien_dictionary
{
    using Solution = Solution;

    TEST(test__curated_graph_269_alien_dictionary, Case_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "wrt","wrf","er","ett","rftt" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "wertf";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "z","x" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "zx";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_3)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "z", "x", "z" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "z", "z" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "z";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "zy","zx" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "yxz";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Failure_3)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "ac","ab","zc","zb" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "cbaz";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Failure_4)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "aac","aabb","aaba" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "cba";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Failure_5)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "abc","ab" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "";
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_269_alien_dictionary, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = std::string;

        std::vector<std::string> input = { "ze","yf","xd","wd","vd","ua","tt","sz","rd","qd","pz","op","nw","mt","ln","ko","jm","il","ho","gk","fa","ed","dg","ct","bb","ba" };
        RetsultType result = s.alienOrder(input);
        RetsultType expect = "zyxwvutsrqponmlkjihgfedcba";
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_graph_269_alien_dictionary

#include "curated_string_271_encode_and_decode_strings.cpp"

namespace p_curated_string_271_encode_and_decode_strings
{
    TEST(test__curated_string_271_encode_and_decode_strings, Case_1)
    {
        Codec cc;

        std::vector<std::string> data({ "Hello","World" });
        ASSERT_THAT(cc.decode(cc.encode(data)) == data, Eq(true));
    }

    TEST(test__curated_string_271_encode_and_decode_strings, Case_Failure_1)
    {
        Codec cc;

        std::vector<std::string> data({ "" });
        ASSERT_THAT(cc.decode(cc.encode(data)) == data, Eq(true));
    }
} // namespace p_curated_string_271_encode_and_decode_strings

#include "277.cpp"

namespace p_277
{
    using Solution = Solution;

    TEST(test__277, Case_1)
    {
        std::vector<std::vector<int>> data = { {1, 1, 0}, { 0, 1, 0 }, { 1, 1, 1 } };
        knows = [&data](int a, int b) -> bool {
            return data[a][b];
        };

        Solution s;
        using RetsultType = int;

        int input = 3;
        RetsultType result = s.findCelebrity(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__277, Case_2)
    {
        std::vector<std::vector<int>> data = { {1, 0, 1}, {1, 1, 0}, {0, 1, 1} };
        knows = [&data](int a, int b) -> bool {
            return data[a][b];
        };

        Solution s;
        using RetsultType = int;

        int input = 3;
        RetsultType result = s.findCelebrity(input);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__277, Case_Failure_1)
    {
        std::vector<std::vector<int>> data = { {1, 0}, {0, 1} };
        knows = [&data](int a, int b) -> bool {
            return data[a][b];
        };

        Solution s;
        using RetsultType = int;

        int input = 2;
        RetsultType result = s.findCelebrity(input);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_277

#include "279.cpp"

namespace p_279
{
    using Solution = Solution;

    TEST(test__279, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 12;
        RetsultType result = s.numSquares(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__279, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input = 13;
        RetsultType result = s.numSquares(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__279, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = int;

        int input = 8935;
        RetsultType result = s.numSquares(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_279

#include "283.cpp"

namespace p_283
{
    using Solution = Solution;

    TEST(test__283, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 0,1,0,3,12 };
        s.moveZeroes(input);
        RetsultType expect = { 1,3,12,0,0 };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__283, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 0 };
        s.moveZeroes(input);
        RetsultType expect = { 0 };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__283, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 1,0,1 };
        s.moveZeroes(input);
        RetsultType expect = { 1,1,0 };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__283, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 2,1 };
        s.moveZeroes(input);
        RetsultType expect = { 2,1 };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_283

#include "285.cpp"

namespace p_285
{
    using Solution = Solution;

    TEST(test__285, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("2,1,3");
        TreeNode* input_p = TreeHelper::findElements(input_root, 1)[0];
        RetsultType result = s.inorderSuccessor(input_root, input_p);
        RetsultType expect = TreeHelper::findElements(input_root, 2)[0];
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_root);
    }

    TEST(test__285, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("5,3,6,2,4,null,null,1");
        TreeNode* input_p = TreeHelper::findElements(input_root, 6)[0];
        RetsultType result = s.inorderSuccessor(input_root, input_p);
        RetsultType expect = nullptr;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_root);
    }

    TEST(test__285, Case_Failure_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        TreeNode* input_root = TreeHelper::create("5,3,6,1,4,null,null,null,2");
        TreeNode* input_p = TreeHelper::findElements(input_root, 4)[0];
        RetsultType result = s.inorderSuccessor(input_root, input_p);
        RetsultType expect = TreeHelper::findElements(input_root, 5)[0];;
        ASSERT_THAT(result == expect, Eq(true));

        TreeHelper::remove(input_root);
    }
} // namespace p_285

#include "287.cpp"

namespace p_287
{
    using Solution = Solution;

    TEST(test__287, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,3,4,2,2 };
        RetsultType result = s.findDuplicate(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__287, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 3,1,3,4,2 };
        RetsultType result = s.findDuplicate(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_287

#include "289.cpp"

namespace p_289
{
    using Solution = Solution;

    TEST(test__289, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0} };
        s.gameOfLife(input);
        RetsultType expect = { {0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0} };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__289, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {1, 1}, {1, 0} };
        s.gameOfLife(input);
        RetsultType expect = { {1, 1}, {1, 1} };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_289

#include "curated_heap_295_find_median_from_data_stream.cpp"

namespace p_curated_heap_295_find_median_from_data_stream
{

    TEST(test__curated_heap_295_find_median_from_data_stream, Case_1)
    {
        MedianFinder mf;

        mf.addNum(1);
        mf.addNum(2);
        ASSERT_THAT(mf.findMedian() == 1.5, Eq(true));
        mf.addNum(3);
        ASSERT_THAT(mf.findMedian() == 2.0, Eq(true));
    }

    TEST(test__curated_heap_295_find_median_from_data_stream, Case_Customize_1)
    {
        MedianFinder mf;

        mf.addNum(3);
        mf.addNum(2);
        mf.addNum(7);
        mf.addNum(4);
        ASSERT_THAT(mf.findMedian() == 3.5, Eq(true));
    }
} // namespace p_curated_heap_295_find_median_from_data_stream

#include "curated_tree_297_serialize_and_deserialize_binary_tree.cpp"

namespace p_curated_tree_297_serialize_and_deserialize_binary_tree
{
    using Solution = Codec;

    TEST(test__curated_tree_297_serialize_and_deserialize_binary_tree, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        RetsultType input = TreeHelper::create({ 1,2,3,-1,-1,4,5 }, { true,true,true,false,false,true,true });
        std::string result_str = s.serialize(input);
        RetsultType result_tree = s.deserialize(result_str);
        ASSERT_THAT(TreeHelper::compare(input, result_tree), Eq(true));

        TreeHelper::remove(input);
        TreeHelper::remove(result_tree);
    }

    TEST(test__curated_tree_297_serialize_and_deserialize_binary_tree, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        RetsultType input = TreeHelper::create({ }, { });
        std::string result_str = s.serialize(input);
        RetsultType result_tree = s.deserialize(result_str);
        ASSERT_THAT(TreeHelper::compare(input, result_tree), Eq(true));

        TreeHelper::remove(input);
        TreeHelper::remove(result_tree);
    }

    TEST(test__curated_tree_297_serialize_and_deserialize_binary_tree, Case_Failure_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        RetsultType input = TreeHelper::create({ 4,-7,-3,-1,-1,-9,-3,9,-7,-4,-1,6,-1,-6,-6,-1,-1,0,6,5,-1,9,-1,-1,-1,-4,-1,-1,-1,-2 }, { true,true,true,false,false,true,true,true,true,true,false,true,false,true,true,false,false,true,true,true,false,true,false,false,true,true,false,false,false,true });
        std::string result_str = s.serialize(input);
        RetsultType result_tree = s.deserialize(result_str);
        ASSERT_THAT(TreeHelper::compare(input, result_tree), Eq(true));

        TreeHelper::remove(input);
        TreeHelper::remove(result_tree);
    }

    TEST(test__curated_tree_297_serialize_and_deserialize_binary_tree, Case_Failure_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        RetsultType input = TreeHelper::create({ 1,2,-13,-1,-1,4,5 }, { true,true,true,false,false,true,true });
        std::string result_str = s.serialize(input);
        RetsultType result_tree = s.deserialize(result_str);
        ASSERT_THAT(TreeHelper::compare(input, result_tree), Eq(true));

        TreeHelper::remove(input);
        TreeHelper::remove(result_tree);
    }
} // namespace p_curated_tree_297_serialize_and_deserialize_binary_tree

#include "curated_dp_300_longest_increasing_subsequence.cpp"

namespace p_curated_dp_300_longest_increasing_subsequence
{
    using Solution = Solution;

    TEST(test__curated_dp_300_longest_increasing_subsequence, Case_1)
    {
        Solution s;
        std::vector<int> input = { 10,9,2,5,3,7,101,18 };
        int result = s.lengthOfLIS(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_300_longest_increasing_subsequence, Case_2)
    {
        Solution s;
        std::vector<int> input = { 0,1,0,3,2,3 };
        int result = s.lengthOfLIS(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_300_longest_increasing_subsequence, Case_3)
    {
        Solution s;
        std::vector<int> input = { 7,7,7,7,7,7,7 };
        int result = s.lengthOfLIS(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_300_longest_increasing_subsequence, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 0 };
        int result = s.lengthOfLIS(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_300_longest_increasing_subsequence

#include "307.cpp"

namespace p307
{
    TEST(test_p307, Case_1)
    {
        vector<int> nums = { 1, 3, 5 };
        int result;

        NumArray* obj = new NumArray(nums);

        result = obj->sumRange(0, 2);
        ASSERT_EQ(result, 9);

        obj->update(1, 2);

        result = obj->sumRange(0, 2);
        ASSERT_EQ(result, 8);
    }

    TEST(test_p307, Case_fail_1)
    {
        vector<int> nums = { 9, -8 };
        int result;

        NumArray* obj = new NumArray(nums);

        obj->update(0, 3);

        result = obj->sumRange(1, 1);
        ASSERT_EQ(result, -8);

        result = obj->sumRange(0, 1);
        ASSERT_EQ(result, -5);

        obj->update(1, -3);

        result = obj->sumRange(0, 1);
        ASSERT_EQ(result, 0);
    }

} // namespace p307

#include "308.cpp"

namespace p_308
{
    TEST(test__308, Case_1)
    {
        std::vector<std::vector<int>> data = { {3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5} };
        NumMatrix nmx(data);

        ASSERT_THAT(nmx.sumRegion(2, 1, 4, 3) == 8, Eq(true));
        nmx.update(3, 2, 2);
        ASSERT_THAT(nmx.sumRegion(2, 1, 4, 3) == 10, Eq(true));
    }
} // namespace p_308

#include "315.cpp"

namespace p_315
{
    using Solution = Solution;

    TEST(test__315, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 5,2,6,1 };
        RetsultType result = s.countSmaller(input);
        RetsultType expect = { 2,1,1,0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__315, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { -1 };
        RetsultType result = s.countSmaller(input);
        RetsultType expect = { 0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__315, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 1,2,0 };
        RetsultType result = s.countSmaller(input);
        RetsultType expect = { 1,1,0 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_315

#include "curated_dp_322_coin_change.cpp"

namespace p_curated_dp_322_coin_change
{
    using Solution = Solution;

    TEST(test__curated_dp_322_coin_change, Case_1)
    {
        Solution s;
        std::vector<int> input_coins = { 1, 2, 5 };
        int input_amount = 11;
        int result = s.coinChange(input_coins, input_amount);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_322_coin_change, Case_2)
    {
        Solution s;
        std::vector<int> input_coins = { 2 };
        int input_amount = 3;
        int result = s.coinChange(input_coins, input_amount);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_322_coin_change, Case_3)
    {
        Solution s;
        std::vector<int> input_coins = { 1 };
        int input_amount = 0;
        int result = s.coinChange(input_coins, input_amount);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_322_coin_change, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input_coins = { 1, 2, 2, 2, 5 };
        int input_amount = 11;
        int result = s.coinChange(input_coins, input_amount);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_322_coin_change, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input_coins = { 1,2147483647 };
        int input_amount = 2;
        int result = s.coinChange(input_coins, input_amount);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_322_coin_change, Case_Rumtime_1)
    {
        Solution s;
        std::vector<int> input_coins = { 186,419,83,408 };
        int input_amount = 6249;
        int result = s.coinChange(input_coins, input_amount);
        int expect = 20;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_322_coin_change

#include "curated_graph_323_number_of_connected_components_in_an_undirected_graph.cpp"

namespace p_curated_graph_323_number_of_connected_components_in_an_undirected_graph
{
    using Solution = Solution;

    TEST(test__curated_graph_323_number_of_connected_components_in_an_undirected_graph, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {1, 2}, {3, 4} };
        RetsultType result = s.countComponents(input_n, input_edges);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_323_number_of_connected_components_in_an_undirected_graph, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4} };
        RetsultType result = s.countComponents(input_n, input_edges);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_323_number_of_connected_components_in_an_undirected_graph, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 6;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {0, 2}, {2, 5}, {3, 4}, {3, 5} };
        RetsultType result = s.countComponents(input_n, input_edges);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_323_number_of_connected_components_in_an_undirected_graph, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {0, 2}, {2, 3}, {2, 4} };
        RetsultType result = s.countComponents(input_n, input_edges);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_graph_323_number_of_connected_components_in_an_undirected_graph, Case_Failure_3)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 10;
        std::vector<std::vector<int>> input_edges = { {5, 6}, {0, 2}, {1, 7}, {5, 9}, {1, 8}, {3, 4}, {0, 6}, {0, 7}, {0, 3}, {8, 9} };
        RetsultType result = s.countComponents(input_n, input_edges);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_graph_323_number_of_connected_components_in_an_undirected_graph

#include "324.cpp"

namespace p_324
{
    using Solution = Solution;

    TEST(test__324, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 1,5,1,1,6,4 };
        s.wiggleSort(input);
        RetsultType expect = { 1,6,1,5,1,4 };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__324, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input = { 1,3,2,2,3,1 };
        s.wiggleSort(input);
        RetsultType expect = { 2,3,1,3,1,2 };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_324

#include "326.cpp"

namespace p_326
{
    using Solution = Solution;

    TEST(test__326, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        int input = 27;
        RetsultType result = s.isPowerOfThree(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__326, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        int input = 0;
        RetsultType result = s.isPowerOfThree(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__326, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        int input = 9;
        RetsultType result = s.isPowerOfThree(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__326, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        int input = 1;
        RetsultType result = s.isPowerOfThree(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_326

#include "328.cpp"

namespace p328
{
    using Solution = Solution;

    TEST(test_328, Case_1)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 1,2,3,4,5 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 1,3,5,2,4 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_2)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 2,1,3,5,6,4,7 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 2,3,6,7,1,5,4 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_Customize_1)
    {
        Solution s;
        ListNode* input = ListHelper::create({ });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_Customize_2)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 2 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 2 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_Customize_3)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 1, 2 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 1, 2 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_Customize_4)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 1, 2, 10, 20, 100, 200, 1000, 2000, 10000, 20000 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 1, 10, 100, 1000, 10000, 2, 20, 200, 2000, 20000 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test_328, Case_RunTime_1)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 1, 2, 3 });
        auto result = std::shared_ptr<ListNode>(s.oddEvenList(input), ListHelper::remove);
        std::vector<int> expect = { 1, 3, 2 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }
} // namespace p328

#include "329.cpp"

namespace p_329
{
    using Solution = Solution;

    TEST(test__329, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1} };
        RetsultType result = s.longestIncreasingPath(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__329, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {3, 4, 5}, {3, 2, 6}, {2, 2, 1} };
        RetsultType result = s.longestIncreasingPath(input);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__329, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input = { {1} };
        RetsultType result = s.longestIncreasingPath(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_329

#include "334.cpp"

namespace p_334
{
    using Solution = Solution;

    TEST(test__334, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 1,2,3,4,5 };
        RetsultType result = s.increasingTriplet(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__334, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 5,4,3,2,1 };
        RetsultType result = s.increasingTriplet(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__334, Case_3)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 2,1,5,0,4,6 };
        RetsultType result = s.increasingTriplet(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__334, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 20, 100, 10, 12, 5, 13 };
        RetsultType result = s.increasingTriplet(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__334, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 4,5,2147483647,1,2 };
        RetsultType result = s.increasingTriplet(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_334

#include "curated_binary_338_counting_bits.cpp"

namespace p_curated_binary_338_counting_bits
{
    using Solution = Solution;

    TEST(test__curated_binary_338_counting_bits, Case_1)
    {
        Solution s;
        int input = 2;
        auto result = s.countBits(input);
        std::vector<int> expect = { 0,1,1 };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_338_counting_bits, Case_2)
    {
        Solution s;
        int input = 5;
        auto result = s.countBits(input);
        std::vector<int> expect = { 0,1,1,2,1,2 };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_binary_338_counting_bits

#include "340.cpp"

namespace p_340
{
    using Solution = Solution;

    TEST(test__340, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "eceba";
        int input_k = 2;
        RetsultType result = s.lengthOfLongestSubstringKDistinct(input_s, input_k);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__340, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "aa";
        int input_k = 1;
        RetsultType result = s.lengthOfLongestSubstringKDistinct(input_s, input_k);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_340

#include "341.cpp"

namespace p_341
{
    TEST(test__341, Case_1)
    {
        std::vector<NestedInteger> input = { NestedInteger({NestedInteger(1), NestedInteger(1)}), NestedInteger(2), NestedInteger({NestedInteger(1), NestedInteger(1)}) };
        NestedIterator nested_iter(input);

        std::vector<int> result;

        while (nested_iter.hasNext())
        {
            result.push_back(nested_iter.next());
        }

        std::vector<int> expected = { 1,1,2,1,1 };

        ASSERT_THAT(result == expected, Eq(true));
    }

    TEST(test__341, Case_2)
    {
        std::vector<NestedInteger> input = { NestedInteger(1), NestedInteger({NestedInteger(4), NestedInteger({NestedInteger(6)})}) };
        NestedIterator nested_iter(input);

        std::vector<int> result;

        while (nested_iter.hasNext())
        {
            result.push_back(nested_iter.next());
        }

        std::vector<int> expected = { 1,4,6 };

        ASSERT_THAT(result == expected, Eq(true));
    }
} // namespace p_341

#include "344.cpp"

namespace p_344
{
    using Solution = Solution;

    TEST(test__344, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<char>;

        std::vector<char> input = { 'h','e','l','l','o' };
        s.reverseString(input);
        RetsultType expect = { 'o','l','l','e','h' };
        ASSERT_THAT(input == expect, Eq(true));
    }

    TEST(test__344, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<char>;

        std::vector<char> input = { 'H','a','n','n','a','h' };
        s.reverseString(input);
        RetsultType expect = { 'h','a','n','n','a','H' };
        ASSERT_THAT(input == expect, Eq(true));
    }
} // namespace p_344

#include "curated_heap_347_top_k_frequent_elements.cpp"

namespace p_curated_heap_347_top_k_frequent_elements
{
    using Solution = Solution;

    TEST(test__curated_heap_347_top_k_frequent_elements, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 1,1,1,2,2,3 };
        int input_k = 2;
        RetsultType result = s.topKFrequent(input_nums, input_k);
        RetsultType expect = { 1,2 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_heap_347_top_k_frequent_elements, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 1 };
        int input_k = 1;
        RetsultType result = s.topKFrequent(input_nums, input_k);
        RetsultType expect = { 1 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_heap_347_top_k_frequent_elements, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;
        std::vector<int> input_nums = { 3, 0, 1, 0 };
        int input_k = 1;
        RetsultType result = s.topKFrequent(input_nums, input_k);
        RetsultType expect = { 0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_heap_347_top_k_frequent_elements, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;
        std::vector<int> input_nums = { 4, 1, -1, 2, -1, 2, 3 };
        int input_k = 2;
        RetsultType result = s.topKFrequent(input_nums, input_k);
        RetsultType expect = { -1, 2 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_heap_347_top_k_frequent_elements

#include "348.cpp"

namespace p_348
{
    TEST(test__348, Case_1)
    {
        TicTacToe ttt(3);
        ASSERT_THAT(ttt.move(0, 0, 1) == 0, Eq(true));
        ASSERT_THAT(ttt.move(0, 2, 2) == 0, Eq(true));
        ASSERT_THAT(ttt.move(2, 2, 1) == 0, Eq(true));
        ASSERT_THAT(ttt.move(1, 1, 2) == 0, Eq(true));
        ASSERT_THAT(ttt.move(2, 0, 1) == 0, Eq(true));
        ASSERT_THAT(ttt.move(1, 0, 2) == 0, Eq(true));
        ASSERT_THAT(ttt.move(2, 1, 1) == 1, Eq(true));
    }
} // namespace p_348

#include "350.cpp"

namespace p_350
{
    using Solution = Solution;

    TEST(test__350, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums1 = { 1,2,2,1 };
        std::vector<int> input_nums2 = { 2,2 };
        RetsultType result = s.intersect(input_nums1, input_nums2);
        RetsultType expect = { 2,2 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__350, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums1 = { 4,9,5 };
        std::vector<int> input_nums2 = { 9,4,9,8,4 };
        RetsultType result = s.intersect(input_nums1, input_nums2);
        RetsultType expect = { 9, 4 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_350

#include "curated_binary_371_sum_of_two.cpp"

namespace p_curated_binary_371_sum_of_two
{
    using Solution = Solution;

    TEST(test__curated_binary_371_sum_of_two, Case_1)
    {
        Solution s;
        int input_a = 1;
        int input_b = 2;
        int result = s.getSum(input_a, input_b);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_2)
    {
        Solution s;
        int input_a = 2;
        int input_b = 3;
        int result = s.getSum(input_a, input_b);
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_Customize_1)
    {
        Solution s;
        int input_a = -1000;
        int input_b = 1000;
        int result = s.getSum(input_a, input_b);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_Customize_2)
    {
        Solution s;
        int input_a = -1000;
        int input_b = 999;
        int result = s.getSum(input_a, input_b);
        int expect = -1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_Customize_3)
    {
        Solution s;
        int input_a = 0;
        int input_b = 999;
        int result = s.getSum(input_a, input_b);
        int expect = 999;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_Customize_4)
    {
        Solution s;
        int input_a = 1000;
        int input_b = 1000;
        int result = s.getSum(input_a, input_b);
        int expect = 2000;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_binary_371_sum_of_two, Case_Customize_5)
    {
        Solution s;
        int input_a = -1000;
        int input_b = -1000;
        int result = s.getSum(input_a, input_b);
        int expect = -2000;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_binary_371_sum_of_two

#include "curated_dp_377_combination_sum_iv.cpp"

namespace p_curated_dp_377_combination_sum_iv
{
    using Solution = Solution;

    TEST(test__curated_dp_377_combination_sum_iv, Case_1)
    {
        Solution s;
        std::vector<int> input_nums = { 1,2,3 };
        int input_target = 4;
        int result = s.combinationSum4(input_nums, input_target);
        int expect = 7;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_377_combination_sum_iv, Case_2)
    {
        Solution s;
        std::vector<int> input_nums = { 9 };
        int input_target = 3;
        int result = s.combinationSum4(input_nums, input_target);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_377_combination_sum_iv, Case_Rumtime_1)
    {
        Solution s;
        std::vector<int> input_nums = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111 };
        int input_target = 999;
        int result = s.combinationSum4(input_nums, input_target);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_377_combination_sum_iv

#include "378.cpp"

namespace p_378
{
    using Solution = Solution;

    TEST(test__378, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 5, 9}, {10, 11, 13}, {12, 13, 15} };
        int input_k = 8;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 13;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {-5} };
        int input_k = 1;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = -5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 1, 1}, {1,1,1}, {1,1,1} };
        int input_k = 9;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Customize_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 1, 1}, {1,1,1}, {1,1,999} };
        int input_k = 9;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 999;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Customize_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 1, 1}, {1,1,1}, {1,1,999} };
        int input_k = 8;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 2}, {1, 3} };
        int input_k = 2;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 3, 5}, {6, 7, 12}, {11, 14, 14} };
        int input_k = 6;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 11;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__378, Case_Failure_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::vector<int>> input_matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
        int input_k = 5;
        RetsultType result = s.kthSmallest(input_matrix, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_378

#include "380.cpp"

namespace p_380
{
    TEST(test__380, Case_1)
    {
        RandomizedSet rs;

        ASSERT_THAT(rs.insert(1), Eq(true));
        ASSERT_THAT(rs.remove(2), Eq(false));
        ASSERT_THAT(rs.insert(2), Eq(true));
        int a = rs.getRandom();
        ASSERT_THAT(rs.remove(1), Eq(true));
        ASSERT_THAT(rs.insert(2), Eq(false));
        a = rs.getRandom();
    }

    TEST(test__380, Case_Customize_1)
    {
        RandomizedSet rs;

        ASSERT_THAT(rs.insert(1), Eq(true));
        ASSERT_THAT(rs.insert(2), Eq(true));
        ASSERT_THAT(rs.insert(3), Eq(true));
        ASSERT_THAT(rs.insert(4), Eq(true));
        ASSERT_THAT(rs.insert(5), Eq(true));
        ASSERT_THAT(rs.remove(3), Eq(true));

    }
} // namespace p_380

#include "384.cpp"

namespace p_384
{
    TEST(test__384, Case_1)
    {
        std::vector<int> input = { 1, 2, 3 };
        std::vector<int> output = { 1, 2, 3 };
        Solution s(input);

        s.shuffle();
        ASSERT_THAT(s.reset() == output, Eq(true));
        s.shuffle();
    }
} // namespace p_384

#include "387.cpp"

namespace p_387
{
    using Solution = Solution;

    TEST(test__387, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "leetcode";
        RetsultType result = s.firstUniqChar(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__387, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "loveleetcode";
        RetsultType result = s.firstUniqChar(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__387, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "aabb";
        RetsultType result = s.firstUniqChar(input);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_387

#include "395.cpp"

namespace p_395
{
    using Solution = Solution;

    TEST(test__395, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "aaabb";
        int input_k = 3;
        RetsultType result = s.longestSubstring(input_s, input_k);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__395, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "ababbc";
        int input_k = 2;
        RetsultType result = s.longestSubstring(input_s, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__395, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "bbaaacbd";
        int input_k = 3;
        RetsultType result = s.longestSubstring(input_s, input_k);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_395

#include "412.cpp"

namespace p_412
{
    using Solution = Solution;

    TEST(test__412, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        int input = 3;
        RetsultType result = s.fizzBuzz(input);
        RetsultType expect = { "1","2","Fizz" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__412, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        int input = 5;
        RetsultType result = s.fizzBuzz(input);
        RetsultType expect = { "1","2","Fizz","4","Buzz" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__412, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        int input = 15;
        RetsultType result = s.fizzBuzz(input);
        RetsultType expect = { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz" };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_412

#include "416.cpp"

namespace p416
{
    using Solution = Solution;

    TEST(test_416, Case_1)
    {
        Solution s;
        std::vector<int> input = { 1,5,11,5 };
        bool result = s.canPartition(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_2)
    {
        Solution s;
        std::vector<int> input = { 1,2,3,5 };
        bool result = s.canPartition(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 1 };
        bool result = s.canPartition(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { 1, 1 };
        bool result = s.canPartition(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_3)
    {
        Solution s;
        std::vector<int> input = { 1, 4, 1 };
        bool result = s.canPartition(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_4)
    {
        Solution s;
        std::vector<int> input = { 1, 4, 1, 8 };
        bool result = s.canPartition(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_5)
    {
        Solution s;
        std::vector<int> input = { 100, 1, 100, 100, 100, 1 };
        bool result = s.canPartition(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_Customize_6)
    {
        Solution s;
        std::vector<int> input = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 95, 93, 99, 97 };
        bool result = s.canPartition(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_416, Case_TimeLimit_1)
    {
        Solution s;
        std::vector<int> input = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 97 };
        bool result = s.canPartition(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p416

#include "curated_graph_417_pacific_atlantic_water_flow.cpp"

namespace p_curated_graph_417_pacific_atlantic_water_flow
{
    using Solution = Solution;

    TEST(test__curated_graph_417_pacific_atlantic_water_flow, Case_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {1,2,2,3,5} ,{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
        RetsultType result = s.pacificAtlantic(input);
        RetsultType expect = { {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_417_pacific_atlantic_water_flow, Case_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {2,1} ,{1,2} };
        RetsultType result = s.pacificAtlantic(input);
        RetsultType expect = { {0,0} ,{0,1},{1,0},{1,1} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_417_pacific_atlantic_water_flow, Case_Failure_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {1,2,3},{8,9,4},{7,6,5} };
        RetsultType result = s.pacificAtlantic(input);
        RetsultType expect = { {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_417_pacific_atlantic_water_flow, Case_Failure_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = { {10, 10, 10}, {10, 1, 10}, {10, 10, 10} };
        RetsultType result = s.pacificAtlantic(input);
        RetsultType expect = { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_graph_417_pacific_atlantic_water_flow, Case_Failure_3)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = std::vector<std::vector<int>>;

        InputType input = {
            {11,2,11,0,15,12,4,15,0,14,11,3,19,11,5,11,18,19,4,3,11,1,9,17,5,2,15,18,11,15},
            {12,10,8,15,4,7,4,5,7,8,5,12,3,3,10,12,16,15,17,13,13,16,0,0,17,17,11,3,14,0},
            {8,18,1,6,15,16,14,11,9,11,3,4,17,7,2,16,18,2,0,0,16,18,10,15,14,18,10,19,17,6},
            {14,17,4,13,13,6,16,1,3,18,18,18,4,1,15,4,0,9,19,3,6,7,19,13,11,11,10,19,3,15},
            {16,6,19,17,19,17,5,12,6,3,1,0,3,10,13,18,4,3,9,0,1,18,9,15,18,3,4,6,1,15},
            {1,2,12,9,9,7,17,0,1,14,18,1,5,3,0,7,2,19,7,19,1,11,1,3,2,4,0,3,16,18},
            {18,10,10,3,12,11,7,8,3,16,7,11,11,12,15,1,13,9,8,17,1,9,7,19,1,14,8,10,18,14},
            {5,19,9,4,10,14,1,5,11,16,11,3,5,4,19,8,11,16,19,12,6,3,18,16,17,8,11,19,7,14},
            {0,15,17,11,10,13,19,0,10,3,15,19,3,3,3,4,3,12,17,10,5,16,12,5,5,17,5,17,6,6},
            {8,19,9,3,13,8,13,17,4,12,13,8,13,12,10,10,16,7,2,8,17,3,7,1,7,16,11,19,13,19},
            {6,19,6,13,10,5,14,7,3,1,10,6,4,8,15,0,0,2,12,13,14,14,7,5,1,16,15,15,4,7},
            {7,7,11,14,2,4,14,2,2,0,6,11,15,14,11,13,2,3,14,9,16,3,8,15,2,18,15,15,2,2},
            {7,5,12,10,14,3,6,9,2,1,2,15,0,4,7,9,7,12,15,9,2,13,7,8,7,9,4,3,5,19},
            {11,9,1,8,0,15,1,6,5,11,14,19,6,11,0,12,1,6,8,7,0,1,2,9,14,4,5,8,3,16},
            {8,0,11,5,14,4,19,0,6,8,1,10,13,8,18,6,6,4,5,9,10,14,14,13,12,16,4,3,3,11},
            {0,9,6,19,16,4,5,10,13,19,8,15,14,7,13,11,17,18,14,18,19,11,0,4,12,11,2,8,17,14},
            {16,19,16,9,9,14,5,13,7,10,18,6,15,12,12,1,11,16,1,8,1,7,16,7,19,6,12,0,15,0},
            {2,4,18,15,13,9,4,18,19,5,16,7,10,1,7,7,4,4,10,8,13,15,9,4,16,13,6,3,13,7},
            {3,11,10,13,6,4,0,13,11,4,5,6,19,13,8,10,8,9,2,4,4,11,12,8,12,15,6,1,10,12},
            {7,6,19,3,2,14,15,6,9,1,6,14,4,15,13,9,14,7,10,12,17,18,6,4,12,4,1,6,6,12},
            {15,17,9,15,9,15,9,10,10,11,12,17,2,18,11,0,6,11,14,17,2,13,9,13,3,4,3,1,8,11},
            {17,13,12,17,4,19,19,7,7,13,19,10,4,16,1,18,14,2,9,18,2,8,3,1,10,9,12,6,2,11},
            {17,12,6,8,3,16,5,2,16,3,13,3,13,9,11,11,5,12,14,16,3,19,16,16,1,14,5,3,17,19},
            {1,4,0,3,1,17,5,15,2,19,12,7,18,13,1,0,7,2,9,18,10,18,8,9,13,13,8,10,14,14},
            {9,14,4,18,10,18,3,9,9,17,16,4,19,7,3,18,7,0,10,13,9,10,11,16,3,5,1,2,16,19},
            {8,10,13,8,7,2,9,4,16,15,5,4,15,7,9,7,15,2,6,17,14,3,13,3,4,15,13,10,8,16},
            {17,7,19,19,13,12,6,0,11,4,10,4,1,9,15,9,7,7,14,6,7,18,9,13,6,16,5,2,17,1},
            {2,7,0,4,8,18,4,11,13,4,11,12,3,18,11,2,4,18,3,3,17,9,18,11,9,15,14,19,7,17},
            {13,1,15,18,4,12,18,18,15,16,7,17,9,15,11,3,9,7,18,13,3,11,7,19,10,10,7,13,7,19},
            {17,17,14,3,19,7,1,13,9,3,6,16,10,8,14,8,17,18,12,11,4,11,10,15,9,0,4,12,7,15},
            {4,4,8,1,7,11,13,4,11,5,18,2,16,11,16,13,0,13,13,12,11,15,8,4,0,3,2,9,8,15},
            {17,4,13,5,3,17,14,4,7,6,6,11,16,18,2,0,3,12,1,5,12,16,3,14,4,16,5,8,15,9},
            {5,3,17,17,6,4,19,5,4,6,11,4,14,18,4,19,16,15,1,17,3,8,13,14,16,13,18,19,6,4},
            {15,0,8,15,6,6,11,8,18,2,4,10,18,16,15,8,1,5,9,13,7,19,12,2,9,18,1,15,12,8},
            {5,0,18,14,1,8,18,15,5,13,15,7,8,8,9,0,14,12,4,17,2,10,9,7,19,7,19,9,7,1},
            {7,4,16,16,13,4,3,6,15,11,14,7,3,0,5,15,10,13,18,18,11,6,7,9,19,13,4,2,7,9},
            {9,14,15,11,14,5,15,1,19,15,3,4,0,10,4,1,2,15,18,15,15,2,9,0,3,10,9,16,4,1},
            {14,13,17,19,0,13,15,9,16,18,5,6,16,16,6,10,14,15,17,5,9,2,5,11,19,19,11,6,15,14},
            {17,7,19,6,5,19,10,2,11,17,17,13,16,13,19,4,12,3,4,13,7,9,19,9,12,3,16,8,18,13}
        };
        RetsultType result = s.pacificAtlantic(input);
        RetsultType expect = { {0, 29}, {1, 28}, {2, 27}, {2, 28}, {3, 27}, {34, 2}, {35, 2}, {35, 3}, {36, 1}, {36, 2}, {37, 0}, {37, 2}, {37, 3}, {38, 0}, {38, 2} };
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_graph_417_pacific_atlantic_water_flow

#include "curated_string_424_longest_repeating_character_replacement.cpp"

namespace p_curated_string_424_longest_repeating_character_replacement
{
    using Solution = Solution;

    TEST(test__curated_string_424_longest_repeating_character_replacement, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "ABAB";
        int input_k = 2;
        RetsultType result = s.characterReplacement(input_s, input_k);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_424_longest_repeating_character_replacement, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "AABABBA";
        int input_k = 1;
        RetsultType result = s.characterReplacement(input_s, input_k);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_424_longest_repeating_character_replacement, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "BAAA";
        int input_k = 0;
        RetsultType result = s.characterReplacement(input_s, input_k);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_424_longest_repeating_character_replacement, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "ABCDE";
        int input_k = 1;
        RetsultType result = s.characterReplacement(input_s, input_k);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_424_longest_repeating_character_replacement, Case_Failure_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
        int input_k = 4;
        RetsultType result = s.characterReplacement(input_s, input_k);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_424_longest_repeating_character_replacement

#include "curated_interval_435_non_overlapping_intervals.cpp"

namespace p_curated_interval_435_non_overlapping_intervals
{
    using Solution = Solution;

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 2}, {1, 2}, {1, 2} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_3)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 2}, {2, 3} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_Customize_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 2}, {3, 10}, {3, 5}, {6, 9}, {11, 15} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_Customize_2)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 2}, {3, 5}, {3, 10}, {6, 9}, {11, 15} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_Customize_3)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {1, 10}, {3, 5}, {3, 10}, {6, 9}, {11, 15} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_Customize_4)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {-50, 12}, {8, 50}, {25, 70}, {80, 90} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_interval_435_non_overlapping_intervals, Case_Failure_1)
    {
        Solution s;
        using InputType = std::vector<std::vector<int>>;
        using RetsultType = int;

        InputType input = { {-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26} };
        RetsultType result = s.eraseOverlapIntervals(input);
        RetsultType expect = 7;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_interval_435_non_overlapping_intervals

#include "454.cpp"

namespace p_454
{
    using Solution = Solution;

    TEST(test__454, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums1 = { 1,2 };
        std::vector<int> input_nums2 = { -2,-1 };
        std::vector<int> input_nums3 = { -1,2 };
        std::vector<int> input_nums4 = { 0,2 };
        RetsultType result = s.fourSumCount(input_nums1, input_nums2, input_nums3, input_nums4);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__454, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums1 = { 0 };
        std::vector<int> input_nums2 = { 0 };
        std::vector<int> input_nums3 = { 0 };
        std::vector<int> input_nums4 = { 0 };
        RetsultType result = s.fourSumCount(input_nums1, input_nums2, input_nums3, input_nums4);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_454

#include "461_daily.cpp"

namespace p461
{
    using Solution = Solution;

    TEST(test_461, Case_1)
    {
        Solution s;
        int input_a = 1;
        int input_b = 4;
        int result = s.hammingDistance(input_a, input_b);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_461, Case_2)
    {
        Solution s;
        int input_a = 3;
        int input_b = 1;
        int result = s.hammingDistance(input_a, input_b);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_461, Case_Custmize_1)
    {
        Solution s;
        int input_a = 12;
        int input_b = 3;
        int result = s.hammingDistance(input_a, input_b);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_461, Case_Custmize_2)
    {
        Solution s;
        int input_a = 3;
        int input_b = 3;
        int result = s.hammingDistance(input_a, input_b);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_461, Case_Custmize_3)
    {
        Solution s;
        int input_a = 0;
        int input_b = 8;
        int result = s.hammingDistance(input_a, input_b);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p461

#include "540_daily.cpp"

namespace p540
{
    using Solution = Solution;

    TEST(test_540, Case_1)
    {
        Solution s;
        std::vector<int> input = { 1,1,2,3,3,4,4,8,8 };
        int result = s.singleNonDuplicate(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_2)
    {
        Solution s;
        std::vector<int> input = { 3,3,7,7,10,11,11 };
        int result = s.singleNonDuplicate(input);
        int expect = 10;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 1,1,2,2,3,4,4,8,8 };
        int result = s.singleNonDuplicate(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { 1,1,2,2,3,3,4,8,8 };
        int result = s.singleNonDuplicate(input);
        int expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_Customize_3)
    {
        Solution s;
        std::vector<int> input = { 3 };
        int result = s.singleNonDuplicate(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_Customize_4)
    {
        Solution s;
        std::vector<int> input = { 1,1,3 };
        int result = s.singleNonDuplicate(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_540, Case_Runtime_error_1)
    {
        Solution s;
        std::vector<int> input = { 1,1,2,2,3 };
        int result = s.singleNonDuplicate(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }
} // namespace p540

#include "curated_tree_572_subtree_of_another_tree.cpp"

namespace p_curated_tree_572_subtree_of_another_tree
{
    using Solution = Solution;

    TEST(test__curated_tree_572_subtree_of_another_tree, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_root = TreeHelper::create({ 3,4,5,1,2 }, {});
        TreeNode* input_subRoot = TreeHelper::create({ 4,1,2 }, {});
        RetsultType result = s.isSubtree(input_root, input_subRoot);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_572_subtree_of_another_tree, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_root = TreeHelper::create({ 3,4,5,1,2,-1,-1,-1,-1,0 }, { true, true,true,true,true,false,false,false,false,true });
        TreeNode* input_subRoot = TreeHelper::create({ 4,1,2 }, {});
        RetsultType result = s.isSubtree(input_root, input_subRoot);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_572_subtree_of_another_tree, Case_Failure_1)
    {
        Solution s;
        using RetsultType = bool;

        TreeNode* input_root = TreeHelper::create({ 1, 1 }, {});
        TreeNode* input_subRoot = TreeHelper::create({ 1 }, {});
        RetsultType result = s.isSubtree(input_root, input_subRoot);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_tree_572_subtree_of_another_tree, Case_Failure_2)
    {
        Solution s;
        using RetsultType = bool;
        TreeNode* input_root = TreeHelper::create({ 3, 4, 5, 1, -1, 2 }, { true,true,true,true,false,true });
        TreeNode* input_subRoot = TreeHelper::create({ 3, 1, 2 }, {});
        RetsultType result = s.isSubtree(input_root, input_subRoot);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_tree_572_subtree_of_another_tree

#include "637_daily.cpp"

namespace p637_daily
{
    using Solution = Solution;

    TEST(test_637_daily, Case_1)
    {
        Solution s;
        TreeNode* input = TreeHelper::create({3, 9, 20, -1, -1, 15, 7}, {true, true, true, false, false, true, true});
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {3, 14.5, 11};
        ASSERT_EQ(result, expect);

        TreeHelper::remove(input);
    }

    TEST(test_637_daily, Case_2)
    {
        Solution s;
        TreeNode* input = TreeHelper::create({3, 9, 20, 15, 7, -1, -1}, {true, true, true, true, true, false, false});
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {3, 14.5, 11};
        ASSERT_EQ(result, expect);

        TreeHelper::remove(input);
    }

    TEST(test_637_daily, Case_3)
    {
        Solution s;
        TreeNode* input = TreeHelper::create({1, -1, 1}, {true, false, true});
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {1, 1};
        ASSERT_EQ(result, expect);

        TreeHelper::remove(input);
    }

    TEST(test_637_daily, Case_4)
    {
        Solution s;
        TreeNode* input = TreeHelper::create({57, 46, 89, -36, -1, -1, -1}, {true, true, true, true, false, false, false});
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {57, 67.5, -36};
        ASSERT_EQ(result, expect);

        TreeHelper::remove(input);
    }

    TEST(test_637_daily, Case_5)
    {
        Solution s;
        TreeNode* input = TreeHelper::create({0, 1, -1}, {true, true, false});
        vector<double> result = s.averageOfLevels(input);
        vector<double> expect = {0, 1};
        ASSERT_EQ(result, expect);

        TreeHelper::remove(input);
    }
} // namespace p637_daily

#include "curated_string_647_palindromic_substrings.cpp"

namespace p_curated_string_647_palindromic_substrings
{
    using Solution = Solution;

    TEST(test__curated_string_647_palindromic_substrings, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "abc";
        RetsultType result = s.countSubstrings(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_647_palindromic_substrings, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "aaa";
        RetsultType result = s.countSubstrings(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__curated_string_647_palindromic_substrings, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "a";
        RetsultType result = s.countSubstrings(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_curated_string_647_palindromic_substrings

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

#include "740.cpp"

namespace p_740
{
    using Solution = Solution;

    TEST(test__740, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 3,4,2 };
        RetsultType result = s.deleteAndEarn(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__740, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,2,3,3,3,4 };
        RetsultType result = s.deleteAndEarn(input);
        RetsultType expect = 9;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__740, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 8, 7, 3, 8, 1, 4, 10, 10, 10, 2 };
        RetsultType result = s.deleteAndEarn(input);
        RetsultType expect = 52;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__740, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1, 8, 5, 9, 6, 9, 4, 1, 7, 3, 3, 6, 3, 3, 8, 2, 6, 3, 2, 2, 1, 2, 9, 8, 7, 1, 1, 10, 6, 7, 3, 9, 6, 10, 5, 4, 10, 1, 6, 7, 4, 7, 4, 1, 9, 5, 1, 5, 7, 5 };
        RetsultType result = s.deleteAndEarn(input);
        RetsultType expect = 138;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_740

#include "763.cpp"

namespace p763
{
    TEST(test_763, Case_1)
    {
        Solution s;
        string input = "ababcbacadefegdehijhklij";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 9, 7, 8 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_sigle)
    {
        Solution s;
        string input = "a";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 1 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_the_same)
    {
        Solution s;
        string input = "aaaaa";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 5 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_1)
    {
        Solution s;
        string input = "aaabbbccc";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 3, 3, 3 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_2)
    {
        Solution s;
        string input = "aaabbbccca";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 10 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_usecase_3)
    {
        Solution s;
        string input = "aaabbbcccabgkgge";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 11, 4, 1 };
        ASSERT_EQ(result, expect);
    }

    TEST(test_763, Case_wrong_1)
    {
        Solution s;
        string input = "caedbdedda";
        auto result = s.partitionLabels(input);
        vector<int> expect = { 1, 9 };
        ASSERT_EQ(result, expect);
    }
} // namespace p763

#include "799.cpp"

namespace p_799
{
    using Solution = Solution;

    TEST(test__799, Case_1)
    {
        Solution s;
        using RetsultType = double;

        int input_poured = 1;
        int input_query_row = 1;
        int input_query_galss = 1;
        RetsultType result = s.champagneTower(input_poured, input_query_row, input_query_galss);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__799, Case_2)
    {
        Solution s;
        using RetsultType = double;

        int input_poured = 2;
        int input_query_row = 1;
        int input_query_galss = 1;
        RetsultType result = s.champagneTower(input_poured, input_query_row, input_query_galss);
        RetsultType expect = 0.5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__799, Case_Customize_1)
    {
        Solution s;
        using RetsultType = double;

        int input_poured = 5;
        int input_query_row = 2;
        int input_query_galss = 2;
        RetsultType result = s.champagneTower(input_poured, input_query_row, input_query_galss);
        RetsultType expect = 0.5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__799, Case_3)
    {
        Solution s;
        using RetsultType = double;

        int input_poured = 100000009;
        int input_query_row = 33;
        int input_query_galss = 17;
        RetsultType result = s.champagneTower(input_poured, input_query_row, input_query_galss);
        RetsultType expect = 1.0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_799

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

#include "curated_dp_1143_longest_common_subsequence.cpp"

namespace p_curated_dp_1143_longest_common_subsequence
{
    using Solution = Solution;

    TEST(test__curated_dp_1143_longest_common_subsequence, Case_1)
    {
        Solution s;
        std::string input_text1 = "abcde";
        std::string input_text2 = "ace";
        int result = s.longestCommonSubsequence(input_text1, input_text2);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_1143_longest_common_subsequence, Case_2)
    {
        Solution s;
        std::string input_text1 = "abc";
        std::string input_text2 = "abc";
        int result = s.longestCommonSubsequence(input_text1, input_text2);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_1143_longest_common_subsequence, Case_3)
    {
        Solution s;
        std::string input_text1 = "abc";
        std::string input_text2 = "def";
        int result = s.longestCommonSubsequence(input_text1, input_text2);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_1143_longest_common_subsequence, Case_Customize_1)
    {
        Solution s;
        std::string input_text1 = "a";
        std::string input_text2 = "ab";
        int result = s.longestCommonSubsequence(input_text1, input_text2);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test__curated_dp_1143_longest_common_subsequence, Case_Customize_2)
    {
        Solution s;
        std::string input_text1 = "aaaaa";
        std::string input_text2 = "a";
        int result = s.longestCommonSubsequence(input_text1, input_text2);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_curated_dp_1143_longest_common_subsequence

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

#include "1290_daily.cpp"

namespace p1290_daily
{
    using Solution = Solution;

    TEST(test_1290_daily, Case_1)
    {
        Solution s;
        auto input = std::shared_ptr<ListNode>(ListHelper::create({ 1,0,1 }), ListHelper::remove);
        int result = s.getDecimalValue(input.get());
        int expect = 5;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1290_daily, Case_2)
    {
        Solution s;
        auto input = std::shared_ptr<ListNode>(ListHelper::create({ 0 }), ListHelper::remove);
        int result = s.getDecimalValue(input.get());
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1290_daily, Case_3)
    {
        Solution s;
        auto input = std::shared_ptr<ListNode>(ListHelper::create({ 1 }), ListHelper::remove);
        int result = s.getDecimalValue(input.get());
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1290_daily, Case_4)
    {
        Solution s;
        auto input = std::shared_ptr<ListNode>(ListHelper::create({ 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 }), ListHelper::remove);
        int result = s.getDecimalValue(input.get());
        int expect = 18880;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1290_daily, Case_5)
    {
        Solution s;
        auto input = std::shared_ptr<ListNode>(ListHelper::create({ 0, 0 }), ListHelper::remove);
        int result = s.getDecimalValue(input.get());
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p1290_daily

#include "1306.cpp"

namespace p1306
{
    using Solution = Solution;

    TEST(test_1306, Case_1)
    {
        Solution s;
        std::vector<int> input_arr = { 4,2,3,0,3,1,2 };
        int input_start = 5;
        bool result = s.canReach(input_arr, input_start);
        int expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1306, Case_2)
    {
        Solution s;
        std::vector<int> input_arr = { 4,2,3,0,3,1,2 };
        int input_start = 0;
        bool result = s.canReach(input_arr, input_start);
        int expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_1306, Case_3)
    {
        Solution s;
        std::vector<int> input_arr = { 3,0,2,1,2 };
        int input_start = 2;
        bool result = s.canReach(input_arr, input_start);
        int expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p1306

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

#include "2133_weekly_contest.cpp"

namespace p_2133_weekly_contest
{
    using Solution = Solution;

    TEST(test_2133_weekly_contest, Case_1)
    {
        Solution s;
        std::vector<std::vector<int>> input = { {1,2,3} ,{3,1,2},{2,3,1} };
        bool result = s.checkValid(input);
        bool expect = true;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2133_weekly_contest, Case_2)
    {
        Solution s;
        std::vector<std::vector<int>> input = { {1,1,1} ,{1,2,3},{1,2,3} };
        bool result = s.checkValid(input);
        bool expect = false;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2133_weekly_contest

#include "2134_weekly_contest.cpp"

namespace p_2134_weekly_contest
{
    using Solution = Solution;

    TEST(test_2134_weekly_contest, Case_1)
    {
        Solution s;
        std::vector<int> input = { 0,1,0,1,1,0,0 };
        int result = s.minSwaps(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2134_weekly_contest, Case_2)
    {
        Solution s;
        std::vector<int> input = { 0,1,1,1,0,0,1,1,0 };
        int result = s.minSwaps(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2134_weekly_contest, Case_3)
    {
        Solution s;
        std::vector<int> input = { 1,1,0,0,1 };
        int result = s.minSwaps(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2134_weekly_contest, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 1, 1, 1, 0, 0, 1, 0, 1, 1, 0 };
        int result = s.minSwaps(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2134_weekly_contest, Case_Failure_2)
    {
        Solution s;
        std::vector<int> input = { 1 };
        int result = s.minSwaps(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2134_weekly_contest, Case_Failure_3)
    {
        Solution s;
        std::vector<int> input = { 0 };
        int result = s.minSwaps(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2134_weekly_contest

#include "2169_weekly_contest.cpp"

namespace p_2169_weekly_contest
{
    using Solution = Solution;

    TEST(test_2169_weekly_contest, Case_1)
    {
        Solution s;
        int input_num1 = 2;
        int input_num2 = 3;
        int result = s.countOperations(input_num1, input_num2);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2169_weekly_contest, Case_2)
    {
        Solution s;
        int input_num1 = 10;
        int input_num2 = 10;
        int result = s.countOperations(input_num1, input_num2);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2169_weekly_contest, Case_Customize_1)
    {
        Solution s;
        int input_num1 = 3;
        int input_num2 = 0;
        int result = s.countOperations(input_num1, input_num2);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2169_weekly_contest

#include "2170_weekly_contest.cpp"

namespace p_2170_weekly_contest
{
    using Solution = Solution;

    TEST(test_2170_weekly_contest, Case_1)
    {
        Solution s;
        std::vector<int> input = { 3,1,3,2,4,3 };
        int result = s.minimumOperations(input);
        int expect = 3;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2170_weekly_contest, Case_2)
    {
        Solution s;
        std::vector<int> input = { 1,2,2,2,2 };
        int result = s.minimumOperations(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2170_weekly_contest, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 1 };
        int result = s.minimumOperations(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2170_weekly_contest, Case_Customize_2)
    {
        Solution s;
        std::vector<int> input = { 1, 2, 1 };
        int result = s.minimumOperations(input);
        int expect = 0;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2170_weekly_contest, Case_Customize_3)
    {
        Solution s;
        std::vector<int> input = { 2,1,2,2,2 };
        int result = s.minimumOperations(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
    TEST(test_2170_weekly_contest, Case_Customize_4)
    {
        Solution s;
        std::vector<int> input = { 1,2,2,2,2,2 };
        int result = s.minimumOperations(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }
    TEST(test_2170_weekly_contest, Case_Failure_1)
    {
        Solution s;
        std::vector<int> input = { 2,2 };
        int result = s.minimumOperations(input);
        int expect = 1;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2170_weekly_contest

#include "2171_weekly_contest.cpp"

namespace p_2171_weekly_contest
{
    using Solution = Solution;

    TEST(test_2171_weekly_contest, Case_1)
    {
        Solution s;
        std::vector<int> input = { 4,1,6,5 };
        long long result = s.minimumRemoval(input);
        long long expect = 4;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2171_weekly_contest, Case_2)
    {
        Solution s;
        std::vector<int> input = { 2,10,3,2 };
        long long result = s.minimumRemoval(input);
        long long expect = 7;
        ASSERT_EQ(result, expect);
    }

    TEST(test_2171_weekly_contest, Case_Customize_1)
    {
        Solution s;
        std::vector<int> input = { 4,4,3,4 };
        long long result = s.minimumRemoval(input);
        long long expect = 3;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2171_weekly_contest

#include "2180_weekly_contest_281.cpp"

namespace p_2180_weekly_contest_281
{
    using Solution = Solution;

    TEST(test__2180_weekly_contest_281, Case_1)
    {
        Solution s;
        int input = 4;
        int result = s.countEven(input);
        int expect = 2;
        ASSERT_EQ(result, expect);
    }

    TEST(test__2180_weekly_contest_281, Case_2)
    {
        Solution s;
        int input = 30;
        int result = s.countEven(input);
        int expect = 14;
        ASSERT_EQ(result, expect);
    }
} // namespace p_2180_weekly_contest_281

#include "2181_weekly_contest_281.cpp"

namespace p_2181_weekly_contest_281
{
    using Solution = Solution;

    TEST(test__2181_weekly_contest_281, Case_1)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 0,3,1,0,4,5,2,0 });
        ListNode* result = s.mergeNodes(input);
        std::vector<int> expect = { 4, 11 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }

    TEST(test__2181_weekly_contest_281, Case_2)
    {
        Solution s;
        ListNode* input = ListHelper::create({ 0,1,0,3,0,2,2,0 });
        ListNode* result = s.mergeNodes(input);
        std::vector<int> expect = { 1, 3, 4 };
        ASSERT_EQ(ListHelper::compare(result, expect), true);
    }
} // namespace p_2181_weekly_contest_281

#include "2182_weekly_contest_281.cpp"

namespace p_2182_weekly_contest_281
{
    using Solution = Solution;

    TEST(test__2182_weekly_contest_281, Case_1)
    {
        Solution s;
        std::string input_s = "cczazcc";
        int input_repeatLimit = 3;
        std::string result = s.repeatLimitedString(input_s, input_repeatLimit);
        std::string expect = "zzcccac";
        ASSERT_EQ(result, expect);
    }

    TEST(test__2182_weekly_contest_281, Case_2)
    {
        Solution s;
        std::string input_s = "aababab";
        int input_repeatLimit = 2;
        std::string result = s.repeatLimitedString(input_s, input_repeatLimit);
        std::string expect = "bbabaa";
        ASSERT_EQ(result, expect);
    }
} // namespace p_2182_weekly_contest_281

#include "2185_weekly_contest_282.cpp"

namespace p_2185_weekly_contest_282
{
    using Solution = Solution;

    TEST(test__2185_weekly_contest_282, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::string> input_words = { "pay", "attention", "practice", "attend" };
        std::string input_pref = "at";
        RetsultType result = s.prefixCount(input_words, input_pref);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2185_weekly_contest_282, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<std::string> input_words = { "leetcode","win","loops","success" };
        std::string input_pref = "code";
        RetsultType result = s.prefixCount(input_words, input_pref);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2185_weekly_contest_282

#include "2186_weekly_contest_282.cpp"

namespace p_2186_weekly_contest_282
{
    using Solution = Solution;

    TEST(test__2186_weekly_contest_282, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "leetcode";
        std::string input_t = "coats";
        RetsultType result = s.minSteps(input_s, input_t);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2186_weekly_contest_282, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_s = "night";
        std::string input_t = "thing";
        RetsultType result = s.minSteps(input_s, input_t);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2186_weekly_contest_282

#include "2187_weekly_contest_282.cpp"

namespace p_2187_weekly_contest_282
{
    using Solution = Solution;

    TEST(test__2187_weekly_contest_282, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 1, 2, 3 };
        int input_totalTrips = 5;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2187_weekly_contest_282, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 2 };
        int input_totalTrips = 1;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2187_weekly_contest_282, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 1, 2, 3, 4, 5, 6 };
        int input_totalTrips = 148;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 61;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2187_weekly_contest_282, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 3, 3, 8 };
        int input_totalTrips = 6;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 9;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2187_weekly_contest_282, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 39, 82, 69, 37, 78, 14, 93, 36, 66, 61, 13, 58, 57, 12, 70, 14, 67, 75, 91, 1, 34, 68, 73, 50, 13, 40, 81, 21, 79, 12, 35, 18, 71, 43, 5, 50, 37, 16, 15, 6, 61, 7, 87, 43, 27, 62, 95, 45, 82, 100, 15, 74, 33, 95, 38, 88, 91, 47, 22, 82, 51, 19, 10, 24, 87, 38, 5, 91, 10, 36, 56, 86, 48, 92, 10, 26, 63, 2, 50, 88, 9, 83, 20, 42, 59, 55, 8, 15, 48, 25 };
        int input_totalTrips = 4187;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 858;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2187_weekly_contest_282, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_time = { 5, 10, 10 };
        int input_totalTrips = 9;
        RetsultType result = s.minimumTime(input_time, input_totalTrips);
        RetsultType expect = 25;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2187_weekly_contest_282

#include "2190_biweekly.cpp"

namespace p_2190_biweekly
{
    using Solution = Solution;

    TEST(test__2190_biweekly, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 1,100,200,1,100 };
        int input_key = 1;
        RetsultType result = s.mostFrequent(input_nums, input_key);
        RetsultType expect = 100;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2190_biweekly, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 2,2,2,2,3 };
        int input_key = 2;
        RetsultType result = s.mostFrequent(input_nums, input_key);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2190_biweekly, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 1, 1000, 2 };
        int input_key = 1000;
        RetsultType result = s.mostFrequent(input_nums, input_key);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2190_biweekly, Case_Failure_2)
    {
        Solution s;
        using RetsultType = int;
        std::vector<int> input_nums = { 2, 1000, 2, 1000, 2, 3 };
        int input_key = 2;
        RetsultType result = s.mostFrequent(input_nums, input_key);
        RetsultType expect = 1000;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2190_biweekly

#include "2191_biweekly.cpp"

namespace p_2191_biweekly
{
    using Solution = Solution;

    TEST(test__2191_biweekly, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_mapping = { 8,9,4,0,2,1,3,5,7,6 };
        std::vector<int> input_nums = { 991,338,38 };
        RetsultType result = s.sortJumbled(input_mapping, input_nums);
        RetsultType expect = { 338, 38, 991 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2191_biweekly, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_mapping = { 0,1,2,3,4,5,6,7,8,9 };
        std::vector<int> input_nums = { 789,456,123 };
        RetsultType result = s.sortJumbled(input_mapping, input_nums);
        RetsultType expect = { 123,456,789 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2191_biweekly, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_mapping = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        std::vector<int> input_nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        RetsultType result = s.sortJumbled(input_mapping, input_nums);
        RetsultType expect = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2191_biweekly, Case_Failure_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_mapping = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        std::vector<int> input_nums = { 9, 99, 999, 9999, 999999999 };
        RetsultType result = s.sortJumbled(input_mapping, input_nums);
        RetsultType expect = { 9, 99, 999, 9999, 999999999 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2191_biweekly

#include "2192_biweekly.cpp"

namespace p_2192_biweekly
{
    using Solution = Solution;

    TEST(test__2192_biweekly, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        int input_n = 8;
        std::vector<std::vector<int>> input_edges = { {0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6} };
        RetsultType result = s.getAncestors(input_n, input_edges);
        RetsultType expect = { {}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2192_biweekly, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        int input_n = 5;
        std::vector<std::vector<int>> input_edges = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4} };
        RetsultType result = s.getAncestors(input_n, input_edges);
        RetsultType expect = { {}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2192_biweekly, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        int input_n = 8;
        std::vector<std::vector<int>> input_edges = { {0, 7}, {7, 6}, {0, 3}, {6, 3}, {5, 4}, {1, 5}, {2, 7}, {3, 5}, {3, 1}, {0, 5}, {7, 5}, {2, 1}, {1, 4}, {6, 1} };
        RetsultType result = s.getAncestors(input_n, input_edges);
        RetsultType expect = { {}, {0, 2, 3, 6, 7}, {}, {0, 2, 6, 7}, {0, 1, 2, 3, 5, 6, 7}, {0, 1, 2, 3, 6, 7}, {0, 2, 7}, {0, 2} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2192_biweekly

#include "2194_weekly.cpp"

namespace p_2194_weekly
{
    using Solution = Solution;

    TEST(test__2194_weekly, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input = "K1:L2";
        RetsultType result = s.cellsInRange(input);
        RetsultType expect = { "K1","K2","L1","L2" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2194_weekly, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input = "A1:F1";
        RetsultType result = s.cellsInRange(input);
        RetsultType expect = { "A1", "B1", "C1", "D1", "E1", "F1" };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2194_weekly, Case_Customize_1)
    {
        Solution s;
        using RetsultType = std::vector<std::string>;

        std::string input = "A2:C5";
        RetsultType result = s.cellsInRange(input);
        RetsultType expect = { "A2", "A3", "A4", "A5", "B2", "B3", "B4", "B5", "C2", "C3", "C4", "C5" };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2194_weekly

#include "2195_weekly.cpp"

namespace p_2195_weekly
{
    using Solution = Solution;

    TEST(test__2195_weekly, Case_1)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 1,4,25,10,25 };
        int input_k = 2;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_2)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 5,6 };
        int input_k = 6;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 25;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Customize_1)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 2,4,5 };
        int input_k = 4;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 17;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Failure_1)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86, 52, 19, 32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84 };
        int input_k = 35;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 794;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Failure_2)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83 };
        int input_k = 76;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 3444;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Failure_3)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 93, 44, 49, 45, 93, 52, 6, 7, 88, 70, 86, 15, 38, 86, 86, 95, 8, 62, 13, 84, 26, 16, 33, 85, 7, 62, 55, 50, 77, 10, 76, 10, 35, 67, 19, 12, 24, 39, 76, 37 };
        int input_k = 17;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 250;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 1 };
        int input_k = 1000000000;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 500000001500000000;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2195_weekly, Case_Runtime_2)
    {
        Solution s;
        using RetsultType = long long;

        std::vector<int> input_nums = { 1000000000 };
        int input_k = 1000000000;
        RetsultType result = s.minimalKSum(input_nums, input_k);
        RetsultType expect = 500000000500000001;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2195_weekly

#include "2196_weekly.cpp"

namespace p_2196_weekly
{
    using Solution = Solution;

    TEST(test__2196_weekly, Case_1)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<std::vector<int>> input = { {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1} };
        RetsultType result = s.createBinaryTree(input);
        RetsultType expect = TreeHelper::create("50,20,80,15,17,19");
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }

    TEST(test__2196_weekly, Case_2)
    {
        Solution s;
        using RetsultType = TreeNode*;

        std::vector<std::vector<int>> input = { {1, 2, 1}, {2, 3, 0}, {3, 4, 1} };
        RetsultType result = s.createBinaryTree(input);
        RetsultType expect = TreeHelper::create("1,2,null,null,3,4");
        ASSERT_THAT(TreeHelper::compare(result, expect), Eq(true));

        TreeHelper::remove(result);
        TreeHelper::remove(expect);
    }
} // namespace p_2196_weekly

#include "2200.cpp"

namespace p_2200_weekly
{
    using Solution = Solution;

    TEST(test__2200_weekly, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 3,4,9,1,3,9,5 };
        int input_key = 9;
        int input_k = 1;
        RetsultType result = s.findKDistantIndices(input_nums, input_key, input_k);
        RetsultType expect = { 1,2,3,4,5,6 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2200_weekly, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 2,2,2,2,2 };
        int input_key = 2;
        int input_k = 2;
        RetsultType result = s.findKDistantIndices(input_nums, input_key, input_k);
        RetsultType expect = { 0,1,2,3,4 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2200_weekly, Case_3)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        std::vector<int> input_nums = { 2 };
        int input_key = 3;
        int input_k = 1;
        RetsultType result = s.findKDistantIndices(input_nums, input_key, input_k);
        RetsultType expect = { };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2200_weekly

#include "2201.cpp"

namespace p_2201_weekly
{
    using Solution = Solution;

    TEST(test__2201_weekly, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 2;
        std::vector<std::vector<int>> input_artifacts = { {0, 0, 0, 0}, {0, 1, 1, 1} };
        std::vector<std::vector<int>> input_dig = { {0, 0}, {0, 1} };
        RetsultType result = s.digArtifacts(input_n, input_artifacts, input_dig);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2201_weekly, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input_n = 2;
        std::vector<std::vector<int>> input_artifacts = { {0, 0, 0, 0}, {0, 1, 1, 1} };
        std::vector<std::vector<int>> input_dig = { {0, 0}, {0, 1}, {1, 1} };
        RetsultType result = s.digArtifacts(input_n, input_artifacts, input_dig);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2201_weekly

#include "2202.cpp"

namespace p_2202_weekly
{
    using Solution = Solution;

    TEST(test__2202_weekly, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 5,2,2,4,0,6 };
        int input_k = 4;
        RetsultType result = s.maximumTop(input_nums, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2202_weekly, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 2 };
        int input_k = 1;
        RetsultType result = s.maximumTop(input_nums, input_k);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2202_weekly, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 99, 95, 68, 24, 18 };
        int input_k = 69;
        RetsultType result = s.maximumTop(input_nums, input_k);
        RetsultType expect = 99;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2202_weekly, Case_Failure_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_nums = { 18 };
        int input_k = 3;
        RetsultType result = s.maximumTop(input_nums, input_k);
        RetsultType expect = -1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2202_weekly

#include "2206_biweekly_74.cpp"

namespace p_2206_biweekly_74
{
    using Solution = Solution;

    TEST(test__2206_biweekly_74, Case_1)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 3,2,3,2,2,2 };
        RetsultType result = s.divideArray(input);
        RetsultType expect = true;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2206_biweekly_74, Case_2)
    {
        Solution s;
        using RetsultType = bool;

        std::vector<int> input = { 1,2,3,4 };
        RetsultType result = s.divideArray(input);
        RetsultType expect = false;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2206_biweekly_74

#include "2207_biweekly_74.cpp"

namespace p_2207_biweekly_74
{
    using Solution = Solution;

    TEST(test__2207_biweekly_74, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_text = "abdcdbc";
        std::string input_pattern = "ac";
        RetsultType result = s.maximumSubsequenceCount(input_text, input_pattern);
        RetsultType expect = 4;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2207_biweekly_74, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_text = "aabb";
        std::string input_pattern = "ab";
        RetsultType result = s.maximumSubsequenceCount(input_text, input_pattern);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2207_biweekly_74, Case_Customize_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_text = "bbaa";
        std::string input_pattern = "ab";
        RetsultType result = s.maximumSubsequenceCount(input_text, input_pattern);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2207_biweekly_74, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_text = "fwymvreuftzgrcrxczjacqovduqaiig";
        std::string input_pattern = "yy";
        RetsultType result = s.maximumSubsequenceCount(input_text, input_pattern);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2207_biweekly_74

#include "2208_biweekly_74.cpp"

namespace p_2208_biweekly_74
{
    using Solution = Solution;

    TEST(test__2208_biweekly_74, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 5,19,8,1 };
        RetsultType result = s.halveArray(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2208_biweekly_74, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 3,8,20 };
        RetsultType result = s.halveArray(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2208_biweekly_74

#include "2210_weekly_285.cpp"

namespace p_2210_weekly_285
{
    using Solution = Solution;

    TEST(test__2210_weekly_285, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 2,4,1,1,6,5 };
        RetsultType result = s.countHillValley(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2210_weekly_285, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 6,6,5,5,4,1 };
        RetsultType result = s.countHillValley(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2210_weekly_285, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 21,21,21,2,2,2,2,21,21,45 };
        RetsultType result = s.countHillValley(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2210_weekly_285

#include "2211_weekly_285.cpp"

namespace p_2211_weekly_285
{
    using Solution = Solution;

    TEST(test__2211_weekly_285, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "RLRSLL";
        RetsultType result = s.countCollisions(input);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2211_weekly_285, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "LLRR";
        RetsultType result = s.countCollisions(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2211_weekly_285

#include "2212_weekly_285.cpp"

namespace p_2212_weekly_285
{
    using Solution = Solution;

    TEST(test__2212_weekly_285, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numArrows = 9;
        std::vector<int> input_aliceArrows = { 1,1,0,1,0,0,2,1,0,1,2,0 };
        RetsultType result = s.maximumBobPoints(input_numArrows, input_aliceArrows);
        RetsultType expect = { 0,0,0,0,1,1,0,0,1,2,3,1 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2212_weekly_285, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numArrows = 3;
        std::vector<int> input_aliceArrows = { 0,0,1,0,0,0,0,0,0,0,0,2 };
        RetsultType result = s.maximumBobPoints(input_numArrows, input_aliceArrows);
        RetsultType expect = { 0,0,0,0,0,0,0,0,1,1,1,0 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2212_weekly_285, Case_Failure_1)
    {
        Solution s;
        using RetsultType = std::vector<int>;

        int input_numArrows = 89;
        std::vector<int> input_aliceArrows = { 3, 2, 28, 1, 7, 1, 16, 7, 3, 13, 3, 5 };
        RetsultType result = s.maximumBobPoints(input_numArrows, input_aliceArrows);
        RetsultType expect = { 21,3,0,2,8,2,17,8,4,14,4,6 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2212_weekly_285

#include "2215_weekly_286.cpp"

namespace p_2215_weekly_286
{
    using Solution = Solution;

    TEST(test__2215_weekly_286, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input_nums1 = { 1,2,3 };
        std::vector<int> input_nums2 = { 2,4,6 };
        RetsultType result = s.findDifference(input_nums1, input_nums2);
        RetsultType expect = { {1, 3}, {4, 6} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2215_weekly_286, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<int> input_nums1 = { 1,2,3,3 };
        std::vector<int> input_nums2 = { 1,1,2,2 };
        RetsultType result = s.findDifference(input_nums1, input_nums2);
        RetsultType expect = { {3}, {} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2215_weekly_286

#include "2216_weekly_286.cpp"

namespace p_2216_weekly_286
{
    using Solution = Solution;

    TEST(test__2216_weekly_286, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,1,2,3,5 };
        RetsultType result = s.minDeletion(input);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2216_weekly_286, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,1,2,2,3,3 };
        RetsultType result = s.minDeletion(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2216_weekly_286

#include "2217_weekly_286.cpp"

namespace p_2217_weekly_286
{
    using Solution = Solution;

    TEST(test__2217_weekly_286, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<long long>;

        std::vector<int> input_queries = { 1,2,3,4,5,90 };
        int input_intLength = 3;
        RetsultType result = s.kthPalindrome(input_queries, input_intLength);
        RetsultType expect = { 101,111,121,131,141,999 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2217_weekly_286, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<long long>;

        std::vector<int> input_queries = { 2,4,6 };
        int input_intLength = 4;
        RetsultType result = s.kthPalindrome(input_queries, input_intLength);
        RetsultType expect = { 1111,1331,1551 };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2217_weekly_286, Case_Cusotmize_1)
    {
        Solution s;
        using RetsultType = std::vector<long long>;

        std::vector<int> input_queries = { 89,90,91 };
        int input_intLength = 3;
        RetsultType result = s.kthPalindrome(input_queries, input_intLength);
        RetsultType expect = { 989,999,-1 };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2217_weekly_286

#include "2220_biweekly_75.cpp"

namespace p_2220_biweekly_75
{
    using Solution = Solution;

    TEST(test__2220_biweekly_75, Case_1)
    {
        Solution s;
        using RetsultType = int;

        int input_start = 10;
        int input_goal = 7;
        RetsultType result = s.minBitFlips(input_start, input_goal);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2220_biweekly_75, Case_2)
    {
        Solution s;
        using RetsultType = int;

        int input_start = 3;
        int input_goal = 4;
        RetsultType result = s.minBitFlips(input_start, input_goal);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2220_biweekly_75

#include "2221_biweekly_75.cpp"

namespace p_2221_biweekly_75
{
    using Solution = Solution;

    TEST(test__2221_biweekly_75, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 1,2,3,4,5 };
        RetsultType result = s.triangularSum(input);
        RetsultType expect = 8;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2221_biweekly_75, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input = { 5 };
        RetsultType result = s.triangularSum(input);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2221_biweekly_75

#include "2222_biweekly_75.cpp"

namespace p_2222_biweekly_75
{
    using Solution = Solution;

    TEST(test__2222_biweekly_75, Case_1)
    {
        Solution s;
        using RetsultType = long long;

        std::string input = "001101";
        RetsultType result = s.numberOfWays(input);
        RetsultType expect = 6;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2222_biweekly_75, Case_2)
    {
        Solution s;
        using RetsultType = long long;

        std::string input = "11100";
        RetsultType result = s.numberOfWays(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2222_biweekly_75, Case_Runtime_1)
    {
        Solution s;
        using RetsultType = long long;

        std::string input = "1110110010111000010010001101010000010001010001110101100001001111101000101001001101000101100010000110110010101011101000111010010000100111110100110111001101101101000001110010110010111000110100111011011111100011100110110110100010100110001101010011111011110000001100010111000010011010010101111001110010001001011101010111110001011100110000100010101010001111110100100111001000010110010111011001110001000100110011100000010001100110001011010101110000110010111100110001001111010010111001101100011010101010000011111101000010001111001011000110101110000111111100111110010000011101000110010010101011000000001100101001011000010100010011100010011010011000011111100000001010100100111000010011101101001100000010010111101110011101111110101100100100110001011111000101000001100110100100001101000101000100010000010001010010001001000111011011011101111110011100110101011001101010001111111001011111000010100010101011111110100111011001111010111010100100111000110111111000010011011110101100010010101001111010000000100011101011111010010001011101010111001100000000001111000010010110001100100111111110111000100101110101100010001001010000011010100110001010011111111011100101111110001110101011000000110101100000101001110110101011001001010001011100110000011010010001111101111101100001110010010101001100101000101000110101100111001001111111011000101110010010001000011011110111100001111000111110001101111010001110011111000101011011010001111010000010011100001110010010000001011001100000111110000100100100110010110001101000001111010010010110000110111000000111110010000000100110011101101011111011111110100100100100010111111010011001000000101011000101100010001011010011100001011001110011001110111000011011011100100110111110110001010100010111010110011000010010100010110111100011010111011101001000101110101001001010011011110100011011111111010110100001100010101011011001010001100000000100001001100110000110101101101010011011110101111000110000001011001110000101110100001110001110010101011001101110011110000011111011011011110000111101101111001010101011000110001100101011100100111100011101101000000101110000011100000010011110100101110111010011011111100101100010110001100101110110111010010010000101011101011011001001010010000000001010010101011000101110000001100110111001001101011111010011101010110101000110001011001111101001001110110100100110101110010110001110111100100001010011001100011100110110101111010101110011101011101011010000111001000110110110100100011100101111110011111101001110110111101011111001100000001001101111001001010000001100001001001000110101010001101101010001000110011110001000001101110011111101000110010010101010010011101001101101001100100011011011101101111010010100111011000100111110111010111111011110001101100011000000010001110101011010101001100101011101011011001011110101101100111101101011111100011110111110001100010001001001101100101001000101001111111111100111101011100010000111001010010101011001010010101110111101001011100000001001100011110010001011011001010010001111011010011110011111101000010101101111110100100101010010011111000101000101110111010100101111000001111110111100101010010010100011111011001100011110110010010110001010110100100101111111001010001010000000010110111100101010101111011100010011110011010001000010101111000011110010001101000011110011111100011101100101001001111101110111011111000110010101111100010101011100010000001010011011100010100101001001100010101110010111111110001101100000001001110010101101000000110011101100001010101000001100110001000101001111010010110010001111011000101111100000010011010010010010010000100001100101100111011010001011001010011010101111000111000110100110111100111100100100100010000100101000010100100010111010111011100110101011001001100010011011000111001010011111101110011001000110000110010011011101101111000001111110111000110111001111100101001010101001101011000000101100111000000010101101101111010110010011011000111100110100000000000100001000111110110001110111011010010001110101000001010001101100001000100011011010000100101100010100101101101110000101110010110101011110001000000100111101010100010110110000011010001000111100010011111100011100111101100100001111011111111100010100100100110000000100011100000111110011111100110011011101001101101001000110001010110000001111000101011010100101101000010001011111111100011000001001010111011111011000111111001100011110001101011011011010001110111100110101110010001110010101001011111101010011101101100001001010110001111110001000110101110011010110000011101101110001001110110100011110100110101110101001111011001010110110010001110011100100011010111110100110110110001101011110110010000011001110110100111010000000110111101111001110001000110011010111111000011111110101010101000111110101110101011011000000110001100000010111001010001011011000001111010000011111010000010010001111101011100111110001010100111111011101101000000100100101011011110100111100110100011001010100111010111110111111000101111000111110100101101111110001111110101010001011101100110100011001110001000001110001001011111000111100101100110000110100011111000010101111010000010011000110000001110100001100111010000100111010110001010111100001000100110011101111001110101010110010010100110000000100011101001010010110000011110101110111001110110010001101010011010110111111000100101000101010000010101100000110000100011000000100010100101000001010111010011011010011110101100110001001001000100101011110110001100001111101001010011011110001000111101110111010111000100110101111101011000010100001101001100010001110111110111110111000100101100111010101100110011000100101001000101110100010101010101010111000010111101000000010001011010001101111100010001010100000011100101111000010100100100111010011101110000011000100011011111110110101100000001000111001111010110001001100101001000100100100000100100111001000100101000001110000000111101111001101001001110110110111011101111101010010000011011011001110011001110101001000110001101110101110000101101100110001110111110000110101010111111101001100001101011001100011001011101011001011110010111111110000101011101011001011011101111000010110101011000111111011101110011110111000011101011011101011000110110011010100001100011000110111011111110011110001000011011110111111011100001110001100110101110001000100100000010011011011101010001011010001111111011110010001111000000010010001000000101011111010100101001101011100001011010000011110001110100010001111101111101000001111100100010010001101100001111010000001001101100100100100110001111000111000100100011110111101110001011000000101110100000100";
        RetsultType result = s.numberOfWays(input);
        RetsultType expect = 10981495136;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2222_biweekly_75

#include "2224_weekly_287.cpp"

namespace p_2224_weekly_287
{
    using Solution = Solution;

    TEST(test__2224_weekly_287, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_current = "02:30";
        std::string input_correct = "04:35";
        RetsultType result = s.convertTime(input_current, input_correct);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2224_weekly_287, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input_current = "11:00";
        std::string input_correct = "11:01";
        RetsultType result = s.convertTime(input_current, input_correct);
        RetsultType expect = 1;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2224_weekly_287, Case_Failure_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input_current = "09:41";
        std::string input_correct = "10:34";
        RetsultType result = s.convertTime(input_current, input_correct);
        RetsultType expect = 7;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2224_weekly_287

#include "2225_weekly_287.cpp"

namespace p_2225_weekly_287
{
    using Solution = Solution;

    TEST(test__2225_weekly_287, Case_1)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9} };
        RetsultType result = s.findWinners(input);
        RetsultType expect = { {1, 2, 10}, {4, 5, 7, 8} };
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2225_weekly_287, Case_2)
    {
        Solution s;
        using RetsultType = std::vector<std::vector<int>>;

        std::vector<std::vector<int>> input = { {2, 3}, {1, 3}, {5, 4}, {6, 4} };
        RetsultType result = s.findWinners(input);
        RetsultType expect = { {1, 2, 5, 6}, {} };
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2225_weekly_287

#include "2226_weekly_287.cpp"

namespace p_2226_weekly_287
{
    using Solution = Solution;

    TEST(test__2226_weekly_287, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_candies = { 5,8,6 };
        int input_k = 3;
        RetsultType result = s.maximumCandies(input_candies, input_k);
        RetsultType expect = 5;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test__2226_weekly_287, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input_candies = { 2,5 };
        int input_k = 11;
        RetsultType result = s.maximumCandies(input_candies, input_k);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2226_weekly_287

#include "2716_weekly_348_fred.cpp"

namespace p_2716_weekly_348_fred
{
    using Solution = Solution;

    TEST(test_2716_weekly_348_fred, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "aaabc";
        RetsultType result = s.minimizedStringLength(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test_2716_weekly_348_fred, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "cbbd";
        RetsultType result = s.minimizedStringLength(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test_2716_weekly_348_fred, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::string input = "dddaaa";
        RetsultType result = s.minimizedStringLength(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }
} // namespace p_2716_weekly_348_fred

#include "2717_weekly_348_fred.cpp"

namespace p_2717_weekly_348_fred
{
    using Solution = Solution;

    TEST(test_2717_weekly_348_fred, Case_1)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input  { 2,1,4,3 };
        RetsultType result = s.semiOrderedPermutation(input);
        RetsultType expect = 2;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test_2717_weekly_348_fred, Case_2)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input{ 2,4,1,3 };
        RetsultType result = s.semiOrderedPermutation(input);
        RetsultType expect = 3;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test_2717_weekly_348_fred, Case_3)
    {
        Solution s;
        using RetsultType = int;

        std::vector<int> input{ 1,3,4,2,5 };
        RetsultType result = s.semiOrderedPermutation(input);
        RetsultType expect = 0;
        ASSERT_THAT(result == expect, Eq(true));
    }
}

#include "2718_weekly_348_fred.cpp"

namespace p_2718_weekly_348_fred
{
    using Solution = Solution;

    TEST(test_2718_weekly_348_fred, Case_1)
    {
        Solution s;
        using RetsultType = long long;

        int input_n = 3;
        std::vector<std::vector<int>> input_queries{ { 0, 0, 1 }, { 1, 2, 2 }, { 0, 2, 3 }, { 1, 0, 4 } };
        RetsultType result = s.matrixSumQueries(input_n, input_queries);
        RetsultType expect = 23;
        ASSERT_THAT(result == expect, Eq(true));
    }

    TEST(test_2718_weekly_348_fred, Case_2)
    {
        Solution s;
        using RetsultType = long long;

        int input_n = 3;
        std::vector<std::vector<int>> input_queries {{ 0, 0, 4 }, { 0, 1, 2 }, { 1, 0, 1 }, { 0, 2, 3 }, { 1, 2, 1 }};
        RetsultType result = s.matrixSumQueries(input_n, input_queries);
        RetsultType expect = 17;
        ASSERT_THAT(result == expect, Eq(true));
    }
}

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
