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
void readFile(ifstream& f, int& StudCount, Student*& studs,Group groups[]);
void AddtoGroup(Group groups[], Student* studs);
void GroupStudCout(string choise,Group groups[]);
#endif