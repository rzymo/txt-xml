#include <iostream>
#include "ToTxt.h"
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;


bool ToTxt::convert(vector<string> &data)
{
    if (data.empty())
        { cout << "no data!\n"; return false; }

    XMLDocument xml;
    XMLNode *pRoot;
    XMLElement *pElemCol, *pElemRow;
    string str;

    for (const auto &item : data)
    {
        if (!item.compare(0, 2, "<!")) continue;      // skip e.g. comments
        else if (!item.compare(0, 2, "<?")) continue;
        str += item;
    }
    xml.Parse(str.c_str(), str.length()); // string -> XML structure

    if (!(pRoot = xml.FirstChild()))
        return false; // root
    else
    {
        if (pElemRow = pRoot->FirstChildElement()) // row
        {
            do
            {
                if (pElemCol = pElemRow->FirstChildElement()) // col
                {
                    str = "";
                    while (pElemCol != nullptr)
                    {
                        const char* wsk = pElemCol->GetText();
                        if ( wsk )
                        {
                            str.append(wsk);
                            str.append(" ");
                        }
                        pElemCol = pElemCol->NextSiblingElement();
                    }
                    if (str.length())
                         converted.push_back(str.substr(0, str.length()-1));
                }
            } while (pElemRow = pElemRow->NextSiblingElement());
        }
    }
    data = converted;
    return true;
}
