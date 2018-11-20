#include <iostream>
#include <fstream>
#include "FileRW.h"


FileRW::FileRW()
{
    ext = '*';
    outPath = "";
}

char FileRW::loadFromFile(const string &path)
{
    string extension = path.substr(checkExt(path));

    if (!extension.compare("xml"))
        ext = 'x';
    else if (!extension.compare("txt"))
        ext = 't';

    if (ext == 'x' || ext == 't')
    {
        outPath = path;
        ifstream file(path);
        string line;

        if (!file.is_open())
            return '0'; // file doesn't exist
        else
            while(getline(file, line))
                txtFile.push_back(line);

        file.close();
    }
    return ext;
}

bool FileRW::saveToFile()
{
    if (ext == '*') return false;   // when no data
    if (txtFile.empty()) return false;

    if (ext == 'x')                 // swap output extension
        outPath.replace(outPath.end()-3, outPath.end(), "txt");
    if (ext == 't')
        outPath.replace(outPath.end()-3, outPath.end(), "xml");

    ofstream file(outPath);
    if (file.is_open())
        for (const auto &item : txtFile)
            file << item << endl;
    else
        return false;

    file.close();
    return true;
}

vector<string>& FileRW::getData()
{
    return txtFile;
}

size_t FileRW::checkExt(const string &path)
{
    size_t dot = path.length()-1;

    for(size_t i = 0; path[i]; i++)
    {
        if (path[i] == '.')
            dot = i;
        else if (path[i] == '/' || path[i] == '\\')
            dot = path.length()-1;
    }
    return dot+1;
}
