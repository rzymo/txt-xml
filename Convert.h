#ifndef CONVERT_H
#define CONVERT_H

#include <string>
#include <vector>
using namespace std;


class Convert
{
    public:
        Convert() {};
        virtual ~Convert() = default;
        virtual bool convert(vector<string> &) = 0;

    protected:
        vector<string> converted;
};

#endif // CONVERT_H
