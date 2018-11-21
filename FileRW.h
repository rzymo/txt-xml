#ifndef FILERW_H
#define FILERW_H

#include <iostream>
#include <vector>

using namespace std;


class FileRW
{
    public:
        FileRW();
        ~FileRW() = default;

        char loadFromFile(const string &);
        bool saveToFile();
        vector<string>& getData();

    private:
        char ext;
        string outPath;
        vector<string> txtFile;
        size_t checkExt(const string &);
};

#endif // FILERW_H
