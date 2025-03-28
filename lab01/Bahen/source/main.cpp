#include <iostream>
#include <fstream>
#include <conio.h>
#include "student.h"
#include "functions.h"
#include "group.h"
#include "constants.h"

using namespace std;

int main()
{
    ifstream inp("dateee.txt");
    Group * groups = new Group[groups_n];
    while(!inp.eof()) {
        Student s;
        inp >> s;
        groups[stoi(s.get_group())-1].add(s);
        
    }
    
    search(groups);
    return 0;
}


