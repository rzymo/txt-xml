#ifndef TOXML_H
#define TOXML_H

#include "Convert.h"


class ToXml : public Convert
{
    public:
        ToXml() {};
        ~ToXml() = default;
        virtual bool convert(vector<string> &) override;

    private:
        string validChar(string); // ' " & < >
};

#endif // TOXML_H
