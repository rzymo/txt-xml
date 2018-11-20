#include <iostream>
#include <sstream>
#include <iterator>
#include "ToXml.h"
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;


bool ToXml::convert(vector<string> &data)
{
    if (data.empty())
        { cout << "no data!\n"; return false; }

    converted.push_back("<root>");
    for (const auto &line : data)
    {
        if (line.length() > 0)
        {
            converted.push_back("<row>");

            stringstream ss(line);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> vec(begin, end); // split spring

            for (const auto &item : vec)
                converted.push_back("<col>"+validChar(item)+"</col>");

            converted.push_back("</row>");
        }
    }
    converted.push_back("</root>");

    data = converted;
    return true;
}

string ToXml::validChar(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '\'') str.replace(i, 1, "&apos;");
        else if (str[i] == '"') str.replace(i, 1, "&quot;");
        else if (str[i] == '&') str.replace(i, 1, "&amp;");
        else if (str[i] == '<') str.replace(i, 1, "&lt;");
        else if (str[i] == '>') str.replace(i, 1, "&gt;");
    }
    return str;
}
