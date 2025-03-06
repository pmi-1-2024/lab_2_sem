#pragma once
#include "Student.h"
#include <string>
using namespace std;

void readStudentsFromFile(const string& filename);
void searchStudentByName(const string& filename, const string& name);
void searchStudentByGroup(const string& filename, const string& group);