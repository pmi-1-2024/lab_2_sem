#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <fstream>
#include "Group.h"
using namespace std;

void readFromFile(ifstream& file, int& studentCount, Student*& students);
void menu1();
void menu2();


#endif