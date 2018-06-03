#pragma once
#include <string>
#include "project.h"
using namespace std;

class cppfile: public project {
    public:
        string getfiletype();
        void setoutputcontent(string *outputstring);
    private:
        string documenttype;
};

class cppclassheader: public project {
    public:
        cppclassheader(string classname);
        string getfiletype();
        void setoutputcontent(string *outputstring);
    private:
        string documenttype;
        string classname;

};

class cppclassbody: public project {
    public:
        cppclassbody(string classname, string headerfile);
        string getfiletype();
        void setoutputcontent(string *outputstring);
    private:
        string classname;
        string headerfile;
};
