#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void readFromFile(ifstream& file, int& studentCount, Student students[]);
void menu();

#endif