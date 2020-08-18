#include <iostream>
#include "gtest/gtest.h"
#include "string_tools.hpp"
#include "sort_tools.hpp"

TEST(Test_StringTools, debug)
{
    std::vector<int> result;
    StringTools::KMP(result, "caatcat", "caatcacaatcatcaatcat");
}

TEST(TEST_Sort, debug)
{
    std::vector<int> result = {6, 5, 4, 3, 2, 1};
    SortTools::quicksort(result, 0, result.size());
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(result, expect);
}