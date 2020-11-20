#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"


#include "gtest/gtest.h"
#include "string_tools.hpp"
#include "sort_tools.hpp"

TEST(Test_StringTools, debug)
{
    std::vector<int> result;
    StringTools::KMP(result, "caatcat", "caatcacaatcatcaatcat");
}

class TestSortTestSuit : public ::testing::Test
{
public:
    using int_data = std::vector<int>;
    using int_data_entry = std::pair<int_data, int_data>; // <input, expect>
    std::vector<int_data_entry> int_data_entries;

private:
    void SetUp() override
    {
        // Normal set
        int_data_entries.emplace_back((int_data_entry){
                {5, 3, 2, 6, 9, 3, 1, 4, -10, -999},
                {-999, -10, 1, 2, 3, 3, 4 ,5 ,6, 9}
            });

        // decreasing set
        int_data_entries.emplace_back((int_data_entry){
                {6, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 6}
            });

        // increasing set
        int_data_entries.emplace_back((int_data_entry){
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6}
            });

        // empty set
        int_data_entries.emplace_back((int_data_entry){
                {},
                {}
            });

        // same elements set
        int_data_entries.emplace_back((int_data_entry){
                {3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2},
                {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3}
            });
    }
};

TEST_F(TestSortTestSuit, bubble_sort)
{
    for (auto& data_entry : int_data_entries)
    {
        auto data = data_entry.first;
        SortTools::bubblesort(data);
        ASSERT_THAT(data, testing::Eq(data_entry.second));
    }
}

TEST_F(TestSortTestSuit, quick_sort)
{
    for (auto& data_entry : int_data_entries)
    {
        auto data = data_entry.first;
        SortTools::quicksort(data, 0, data.size() - 1);
        ASSERT_THAT(data, testing::Eq(data_entry.second));
    }
}
