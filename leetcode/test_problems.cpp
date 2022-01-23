#include <iostream>

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

#include "19.cpp"

namespace p19
{
    using Solution = Solution;

    TEST(test_19, Case_1)
    {
        Solution s;
        auto input = ListHelper::create({ 1,2,3,4,5 });
        auto result = std::shared_ptr<ListNode>(s.removeNthFromEnd(input, 2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,5 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_19, Case_2)
    {
        Solution s;
        auto input = ListHelper::create({ 1 });
        auto result = std::shared_ptr<ListNode>(s.removeNthFromEnd(input, 1), ListHelper::remove);
        auto expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_19, Case_3)
    {
        Solution s;
        auto input = ListHelper::create({ 1,2 });
        auto result = std::shared_ptr<ListNode>(s.removeNthFromEnd(input, 1), ListHelper::remove);
        auto expect = ListHelper::create({ 1 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_19, Case_Customer_1)
    {
        Solution s;
        auto input = ListHelper::create({ 1,2 });
        auto result = std::shared_ptr<ListNode>(s.removeNthFromEnd(input, 2), ListHelper::remove);
        auto expect = ListHelper::create({ 2 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
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
        auto input_1 = ListHelper::create({ 1,2,4 });
        auto input_2 = ListHelper::create({ 1,3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,1,2,3,4,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_2)
    {
        Solution s;
        auto input_1 = ListHelper::create({});
        auto input_2 = ListHelper::create({});
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({});
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_3)
    {
        Solution s;
        auto input_1 = ListHelper::create({});
        auto input_2 = ListHelper::create({ 0 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 0 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_Customer_1)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2 });
        auto input_2 = ListHelper::create({});
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_Customer_2)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2 });
        auto input_2 = ListHelper::create({ 3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_Customer_3)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1,2,3 });
        auto input_2 = ListHelper::create({ 4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
    }

    TEST(test_21, Case_Customer_4)
    {
        Solution s;
        auto input_1 = ListHelper::create({ 1 });
        auto input_2 = ListHelper::create({ 2,3,4 });
        auto result = std::shared_ptr<ListNode>(s.mergeTwoLists(input_1, input_2), ListHelper::remove);
        auto expect = ListHelper::create({ 1,2,3,4 });
        ASSERT_THAT(ListHelper::compare(expect, result), testing::Eq(true));
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
