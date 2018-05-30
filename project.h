#pragma once
#include <string>
using namespace std;
class project
{
    public:
        void createworkspace (string output, string filetype);
        void addinworkspace (string output, string filetype, string filename);
        void setprojectname (string f);
        virtual void setoutputcontent(string *outputstring);
        virtual string getfiletype() = 0;
    private:
        string projectname;
};

