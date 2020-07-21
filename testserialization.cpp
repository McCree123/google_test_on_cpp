#include "testserialization.hpp"

TestSerialization::TestSerialization()
{ /* init protected members here */
}

TestSerialization::~TestSerialization()
{ /* free protected members here */
}

void
TestSerialization::SetUp()
{ /* called before every test */
}

void
TestSerialization::TearDown()
{ /* called after every test */
}

TEST_F(TestSerialization, Calculate1)
{
    QString str("55 + 44 * (4 / 2 - 3 / 5) + 2 * 2");
    Calc* calc      = new Calc();
    QString workStr = str.replace(" ", "");

    double d1 = calc->solution(workStr);
    double d2 = 120.6;
    ASSERT_EQ(d1, d2);
}

TEST_F(TestSerialization, Calculate2)
{
    QString str("55 + 44 * 4 / 2 - 3 / 5 + 2 * 2");
    Calc* calc      = new Calc();
    QString workStr = str.replace(" ", "");
    double d1       = calc->solution(workStr);
    double d2       = 146.4;
    ASSERT_EQ(d1, d2);
}

int
main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
