#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "string_tools.hpp"

class Test_StringTools : public testing::Test
{
    void SetUp() override
    {
        std::cout << "setup" << std::endl;
    }

    void TearDown() override
    {
        std::cout << "teardown" << std::endl;
    }
};

TEST_F(Test_StringTools, debug)
{
    std::vector<int> result;
    StringTools::KMP(result, "caatcat", "caatcacaatcatcaatcat");

    for(auto a : result)
    {
        std::cout << a << std::endl;
    }
}