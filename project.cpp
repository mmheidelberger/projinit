#include <iostream>
#include <string>
#include "project.h"
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

void project::setoutputcontent (string *outputstring){
}

string project::getfiletype (){
}

void project::addinworkspace (string output, string filetype, string filename){
    string projectpath = projectname + "/" + filename + "." + filetype;
    ofstream targetfile(projectpath);
    targetfile << output;
    targetfile.close();
}

void project::createworkspace (string output, string filetype){
    mkdir(projectname.c_str(), S_IRWXU);
    addinworkspace(output, filetype, projectname);
}

void project::setprojectname (string f){
    projectname = f;
}

