#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "Student.h"
void readStudentsFromFile(const string& filename, Student*& students, int& studentCount);
void saveToFile(const string& filename, Student* students, int studentCount);
#endif
