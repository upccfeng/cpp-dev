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
    using double_data = std::vector<double>;
    using double_data_entry = std::pair<double_data, double_data>; // <input, expect>
    std::vector<int_data_entry> int_data_entries;
    std::vector<double_data_entry> double_data_entries;

private:
    void SetUp() override
    {
        // Normal set
        int_data_entries.emplace_back((int_data_entry){
                {5, 3, 2, 6, 9, 3, 1, 4, -10, -999},
                {-999, -10, 1, 2, 3, 3, 4 ,5 ,6, 9}
            });
        double_data_entries.emplace_back((double_data_entry){
                {5.1, 5.6, 5.4, 5.40001, 5.9, 4.3, 1.0, 0, -9.9, -9.8},
                {-9.9, -9.8, 0, 1, 4.3, 5.1, 5.4, 5.40001, 5.6, 5.9}
            });

        // decreasing set
        int_data_entries.emplace_back((int_data_entry){
                {6, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 6}
            });
        double_data_entries.emplace_back((double_data_entry){
                {5.9, 5.8, 5.7, 5.6, 5.5},
                {5.5, 5.6, 5.7, 5.8, 5.9}
            });

        // increasing set
        int_data_entries.emplace_back((int_data_entry){
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6}
            });
        double_data_entries.emplace_back((double_data_entry){
                {5.5, 5.6, 5.7, 5.8, 5.9},
                {5.5, 5.6, 5.7, 5.8, 5.9}
            });

        // empty set
        int_data_entries.emplace_back((int_data_entry){
                {},
                {}
            });
        double_data_entries.emplace_back((double_data_entry){
                {},
                {}
            });

        // same elements set
        int_data_entries.emplace_back((int_data_entry){
                {3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2},
                {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3}
            });
        double_data_entries.emplace_back((double_data_entry){
                {5.1, 5.1, 5.0, 5.1, 5.3, 5.2, 5.3, 5.1, 5.0},
                {5.0, 5.0, 5.1, 5.1, 5.1, 5.1, 5.2, 5.3, 5.3}
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

    for (auto& data_entry : double_data_entries)
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

    for (auto& data_entry : double_data_entries)
    {
        auto data = data_entry.first;
        SortTools::quicksort(data, 0, data.size() - 1);
        ASSERT_THAT(data, testing::Eq(data_entry.second));
    }
}
