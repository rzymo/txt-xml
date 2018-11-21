#include <gtest/gtest.h>
#include "FileRW.h"
#include "ToXml.h"
#include "ToTxt.h"


struct TestFileRW : public testing::Test
{
    FileRW *wsk;

    TestFileRW()  { wsk = new FileRW; }
    ~TestFileRW() { delete wsk; }
};

struct TestToTxt : public testing::Test
{
    ToTxt *wsk;
    vector<string> vec;

    TestToTxt()  { wsk = new ToTxt; }
    ~TestToTxt() { delete wsk; }
};

struct TestToXml : public testing::Test
{
    ToXml *wsk;
    vector<string> vec;

    TestToXml()  { wsk = new ToXml; }
    ~TestToXml() { delete wsk; }
};
