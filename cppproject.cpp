#include <string>
#include "cppproject.h"
#include <iostream>

using namespace std;

//Begin cpp file
void cppfile::setoutputcontent(string *outputstring){
    *outputstring = "#include <iostream> \n\nusing namespace std;\n\nint main ()\n{\n    return 0;\n}\n";
}

string cppfile::getfiletype(){
    return "cpp";
}

//Begin cpp class header

cppclassheader::cppclassheader(string classname){
    this->classname = classname;
}

void cppclassheader::setoutputcontent(string *outputstring){
   *outputstring = "#pragma once\n"
                   "using namespace std;\n"
                   "class " + classname + "{\n\n};\n";
}

string cppclassheader::getfiletype(){
    return "h";
}
