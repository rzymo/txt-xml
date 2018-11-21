#include <gtest/gtest.h>
#include "tests.cpp"


// --- FileRW ---
TEST_F(TestFileRW, UnitTest1)
{
    EXPECT_EQ('*', wsk->loadFromFile("/home/f.i.l.e"));
}
TEST_F(TestFileRW, UnitTest2)
{
    EXPECT_EQ('0', wsk->loadFromFile("ex1.txt"));
}
TEST_F(TestFileRW, UnitTest3)
{
    EXPECT_EQ('x', wsk->loadFromFile("testfile.xml"));
}
TEST_F(TestFileRW, UnitTest4)
{
    EXPECT_EQ(false, wsk->saveToFile());
}

// --- ToTxt ---
TEST_F(TestToTxt, UnitTest1)
{
    vec.push_back("<root><row><col>1</col></row></root>");
    EXPECT_EQ(true, wsk->convert(vec));
}
TEST_F(TestToTxt, UnitTest2)
{
    vec.push_back("<root><row><col/></row></root>");
    EXPECT_EQ(true, wsk->convert(vec));
}
TEST_F(TestToTxt, UnitTest3)
{
    vec.push_back("<root><row><col>1</col><col>2<col><col></row></root>");
    EXPECT_EQ(false, wsk->convert(vec));
}

// --- ToXml ---
TEST_F(TestToXml, UnitTest1)
{
    vec.push_back("''\"&//");
    EXPECT_EQ(true, wsk->convert(vec));
}
TEST_F(TestToXml, UnitTest2)
{
    vec.push_back("\n/\n<\n>\n");
    EXPECT_EQ(true, wsk->convert(vec));
}

// --- main ---
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
