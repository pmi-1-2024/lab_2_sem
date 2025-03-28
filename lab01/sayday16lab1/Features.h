#ifndef FEATURES_H
#define FEATURES_H
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Group.h"
using namespace std;

void Startmenu();
void Searchmenu();
void Groupmenu();
void readFile(ifstream& f, int& StudCount, Student*& studs);
void AddtoGroup(Group& gr, Student* studs);
void GroupStudCout(int choise);


#endif
