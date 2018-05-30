#include <ncurses.h>
#include "project.h"
#include "latex.h"
#include "cppproject.h"
#include <iostream>
#include <string>

using namespace std;

char * choices[] = {
                "Exit",
                "LaTeX Document",
                "CPP Main",
                "CPP Class",
                "CPP Header",
                "Python Program",
                };

void present_list();
void select_handler(int selection);
void set_file(char (*file)[50]);
string get_additional_info(string literal);

int no_choices = sizeof(choices) /sizeof(char *);

int main () {
    initscr();
    noecho();
    present_list();
    endwin();

    return 0;
}

void present_list()
{
    clear();
    attron(A_BOLD);
    printw("Choose from the following options, any other key to exit program");
    move(2,0);
    for(int i = 0; i < no_choices; ++i){
        printw("%d. %s\n", i, choices[i]);
    }
    refresh();
    int c = getch();
    select_handler(c);
}

void select_handler(int selection){
    if (selection != 48 && selection > 48 && selection <54) {
       char filename[50];
       set_file(&filename);
       project *projbase;
    switch(selection){
        case 48:
            //0
            break;
        case 49:
            //1 LaTex
            {
            string documentclass = get_additional_info("Enter LaTeX document class");
            projbase = new latex(documentclass);
            }
            break;
        case 50:
            //2
            projbase = new cppfile;
            break;
        case 51:
            //3
            break;
        case 52:
            //4
            projbase = new cppclassheader(filename);
            break;
        case 53:
            //5
            break;
        default:
            present_list();
            break;
          }
            projbase->setprojectname(".");
            string filecontent;
            projbase->setoutputcontent(&filecontent);
            projbase->addinworkspace(filecontent,projbase->getfiletype(), filename);
            delete projbase;
            projbase = nullptr;
 
    }
}    
void set_file(char (*file)[50]){
    printw("Enter object name (omitting extension and suffixes):\n");
    echo();
    getstr(*file);
    noecho();
}

string get_additional_info(string literal){
    echo();
    printw("%s\n", literal.c_str());
    char inputstr[55];
    getstr(inputstr);
    string str = string(inputstr);
    noecho();
    return str;
}
