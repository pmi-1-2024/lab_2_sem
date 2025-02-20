#ifndef FILE_H
#define FILE_H

#include "Student.h"
#include <string>
using namespace std;

void readStudentsFromFile(const string& filename, Student*& students, int& count);

#endif