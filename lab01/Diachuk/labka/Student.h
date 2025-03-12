#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

struct Student {
    string name;
    string group;
    string subject;
    string residence;
    double grade;
    string postal_code;
};

int readStudentsFromFile(const string& filename, Student students[], int maxStudents);
void printStudentInfo(const Student& s);

#endif
