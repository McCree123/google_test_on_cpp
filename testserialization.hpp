#ifndef TESTSERIALIZATION_HPP
#define TESTSERIALIZATION_HPP

#include "calc.cpp"
#include "calc.hpp"
#include <gtest/gtest.h>

class TestSerialization : public ::testing::Test
{
public:
    TestSerialization();
    ~TestSerialization();
    void SetUp();
    void TearDown();

protected:
    /* none yet */
};

#endif // TESTSERIALIZATION_HPP
