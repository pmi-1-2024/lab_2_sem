#ifndef FEATURES_H
#define FEATURES_H
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void menu();
void readFile(ifstream& f, int& StudCount, Student studs[]);

#endif