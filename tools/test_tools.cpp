#include <iostream>

#include "assert.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "string_tools.hpp"
#include "sort_tools.hpp"
#include "binary_tools.hpp"

TEST(Test_StringTools, debug)
{
    //
    // TODO: need to finish the test cases
    //
    std::vector<int> result;
    StringTools::KMP(result, "caatcat", "caatcacaatcatcaatcat");
}

class TestBinaryTools : public ::testing::Test
{

};

TEST(TestBinaryTools, Case_Normal_add_1)
{
    int input_1 = 7;
    int input_2 = 3;
    std::vector<int> result = BinaryTools::binary_of_two_int_sum(input_1, input_2);
    int expect_one_size = 3;
    int result_one_size = 0;

    for (const auto e : result)
    {
        if (e == 1)
        {
            ++result_one_size;
        }
    }

    ASSERT_EQ(result_one_size, expect_one_size);
}

TEST(TestBinaryTools, Case_Normal_add_2)
{
    int input_1 = 4;
    int input_2 = 8;
    std::vector<int> result = BinaryTools::binary_of_two_int_sum(input_1, input_2);
    int expect_one_size = 1;
    int result_one_size = 0;

    for (const auto e : result)
    {
        if (e == 1)
        {
            ++result_one_size;
        }
    }

    ASSERT_EQ(result_one_size, expect_one_size);
}

TEST(TestBinaryTools, Case_Boundary_1)
{
    int input_1 = 100000000;
    int input_2 = 100000000;
    std::vector<int> result = BinaryTools::binary_of_two_int_sum(input_1, input_2);
    int expect_one_size = 20;
    int result_one_size = 0;

    for (const auto e : result)
    {
        if (e == 1)
        {
            ++result_one_size;
        }
    }

    ASSERT_EQ(result_one_size, expect_one_size);
}

TEST(TestBinaryTools, Case_Boundary_2)
{
    int input_1 = 0;
    int input_2 = 100000000;
    std::vector<int> result = BinaryTools::binary_of_two_int_sum(input_1, input_2);
    int expect_one_size = 0;
    int result_one_size = 0;

    for (const auto e : result)
    {
        if (e == 1)
        {
            ++result_one_size;
        }
    }

    ASSERT_EQ(result_one_size, expect_one_size);
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
        int_data_entries.emplace_back(std::make_pair<int_data, int_data>(
                {5, 3, 2, 6, 9, 3, 1, 4, -10, -999},
                {-999, -10, 1, 2, 3, 3, 4 ,5 ,6, 9}
            ));
        double_data_entries.emplace_back(std::make_pair<double_data, double_data>(
                {5.1, 5.6, 5.4, 5.40001, 5.9, 4.3, 1.0, 0, -9.9, -9.8},
                {-9.9, -9.8, 0, 1, 4.3, 5.1, 5.4, 5.40001, 5.6, 5.9}
            ));

        // decreasing set
        int_data_entries.emplace_back(std::make_pair<int_data, int_data>(
                {6, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 6}
            ));
        double_data_entries.emplace_back(std::make_pair<double_data, double_data>(
                {5.9, 5.8, 5.7, 5.6, 5.5},
                {5.5, 5.6, 5.7, 5.8, 5.9}
            ));

        // increasing set
        int_data_entries.emplace_back(std::make_pair<int_data, int_data>(
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6}
            ));
        double_data_entries.emplace_back(std::make_pair<double_data, double_data>(
                {5.5, 5.6, 5.7, 5.8, 5.9},
                {5.5, 5.6, 5.7, 5.8, 5.9}
            ));

        // empty set
        int_data_entries.emplace_back(std::make_pair<int_data, int_data>(
                {},
                {}
            ));
        double_data_entries.emplace_back(std::make_pair<double_data, double_data>(
                {},
                {}
            ));

        // same elements set
        int_data_entries.emplace_back(std::make_pair<int_data, int_data>(
                {3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2},
                {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3}
            ));
        double_data_entries.emplace_back(std::make_pair<double_data, double_data>(
                {5.1, 5.1, 5.0, 5.1, 5.3, 5.2, 5.3, 5.1, 5.0},
                {5.0, 5.0, 5.1, 5.1, 5.1, 5.1, 5.2, 5.3, 5.3}
            ));
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


#include "listnode.hpp"

class TestNodeList : public ::testing::Test
{

};

TEST_F(TestNodeList, ListHelper)
{
    {
        std::shared_ptr<ListNode> x = std::shared_ptr<ListNode>(ListHelper::create({1, 2, 3, 4}), ListHelper::remove);
        ASSERT_THAT(ListHelper::compare(x, { 1, 2, 3, 4 }), testing::Eq(true));
        ASSERT_THAT(ListHelper::compare(x, { 1, 2, 3, 5 }), testing::Eq(false));
        ASSERT_THAT(ListHelper::compare(x, { 1, 2, 3 }), testing::Eq(false));
        ASSERT_THAT(ListHelper::compare(x, { 1, 2, 3, 4, 5 }), testing::Eq(false));
    }

    {
        std::shared_ptr<ListNode> x = std::shared_ptr<ListNode>(ListHelper::create({}), ListHelper::remove);
        ASSERT_THAT(ListHelper::compare(x, {}), testing::Eq(true));
        ASSERT_THAT(ListHelper::compare(x, { 1 }), testing::Eq(false));
    }

    {
        std::shared_ptr<ListNode> x = std::shared_ptr<ListNode>(ListHelper::create({1, 2}), ListHelper::remove);
        std::shared_ptr<ListNode> y = std::shared_ptr<ListNode>(ListHelper::create({1, 2}), ListHelper::remove);
        ASSERT_THAT(ListHelper::compare(x.get(), y.get()), testing::Eq(true));
        ASSERT_THAT(ListHelper::compare(x.get(), {1, 2}), testing::Eq(true));
        ASSERT_THAT(ListHelper::compare(x, {1, 2}), testing::Eq(true));
        ASSERT_THAT(ListHelper::compare(x.get(), y), testing::Eq(true));
    }
}