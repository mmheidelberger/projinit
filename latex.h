#pragma once
#include <string>
#include "project.h"
using namespace std;
class latex: public project {
    public:
        latex(string doctype);
        string getfiletype();
        //void setdocumenttype (string type);
        void setoutputcontent(string *outputstring);
    private:
        string documenttype;
};
