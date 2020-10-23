#include <iostream>
#include "gtest/gtest.h"
#include "string_tools.hpp"
#include "sort_tools.hpp"

TEST(Test_StringTools, debug)
{
    std::vector<int> result;
    StringTools::KMP(result, "caatcat", "caatcacaatcatcaatcat");
}

TEST(TEST_Sort, normal_set)
{
    std::vector<int> result = {5, 3, 2, 6, 9, 3, 1, 4, -10, -999};
    SortTools::quicksort(result, 0, result.size() - 1);
    std::vector<int> expect = {-999, -10, 1, 2, 3, 3, 4 ,5 ,6, 9};
    ASSERT_EQ(result, expect);
}

TEST(TEST_Sort, decreasing_set)
{
    std::vector<int> result = {6, 5, 4, 3, 2, 1};
    SortTools::quicksort(result, 0, result.size() - 1);
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(result, expect);
}

TEST(TEST_Sort, increasing_set)
{
    std::vector<int> result = {1, 2, 3, 4, 5, 6};
    SortTools::quicksort(result, 0, result.size() - 1);
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(result, expect);
}

TEST(TEST_Sort, empty_set)
{
    std::vector<int> result = {};
    SortTools::quicksort(result, 0, result.size() - 1);
    std::vector<int> expect = {};
    ASSERT_EQ(result, expect);
}

TEST(TEST_Sort, the_same_elements_set)
{
    std::vector<int> result = {3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2};
    SortTools::quicksort(result, 0, result.size() - 1);
    std::vector<int> expect = {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3};
    ASSERT_EQ(result, expect);
}