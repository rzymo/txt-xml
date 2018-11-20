#include <iostream>
#include "FileRW.h"
#include "ToXml.h"
#include "ToTxt.h"
using namespace std;


int main(int argc, char* argv[])
{
    bool error = false;
    if (argc == 2)
    {
        FileRW *file  = new FileRW();
        Convert *conv = nullptr;

        switch(file->loadFromFile(argv[1]))
        {
            case 'x':
                        conv = new ToTxt();
                        if ( !conv->convert(file->getData()) ) error = true;
                        else if ( !file->saveToFile() ) error = true;
                        break;
            case 't':
                        conv = new ToXml();
                        if ( !conv->convert(file->getData()) ) error = true;
                        else if ( !file->saveToFile() ) error = true;
                        break;
            case '0':
                        cout << "File doesn't exist!\n";
                        error = true;
                        break;
            default:
                        cout << "Unsupported extension (xml/txt only)!\n";
                        error = true;
        }
        delete conv;
        delete file;
    }
    else
    {
        cout << "Incorrect number of arguments!\n";
        error = true;
    }
    return (error?1:0);
}
