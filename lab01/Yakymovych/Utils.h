#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "Student.h"

using namespace std;

bool matchesSearch(const Student& student, const string& query);
void searchStudents(Student* students, int count);
void loadStudents(const string& filename, Student*& students, int& count);

#endif
