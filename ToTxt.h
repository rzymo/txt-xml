#ifndef TOTXT_H
#define TOTXT_H

#include "Convert.h"


class ToTxt : public Convert
{
    public:
        ToTxt() {};
        ~ToTxt() = default;
        virtual bool convert(vector<string> &) override;
};

#endif // TOTXT_H
