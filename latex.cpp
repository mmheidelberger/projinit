#include "latex.h"
#include <string>
#include <iostream>

using namespace std;

latex::latex(string doctype){
    documenttype = doctype;
}

void latex::setoutputcontent(string *outputstring){
    *outputstring = "\\documentclass{" + documenttype + "}\n\n\\end {document}\n";
}

string latex::getfiletype(){
    return "tex";
}
