#ifndef SEARCH_H
#define SEARCH_H

#include "Student.h"
#include <string>
using namespace std;

void findByName(Student* students, int count, string name);
void findByGroup(Student* students, int count, string group);
void findByZalik(Student* students, int count, int zalikNumber);
void findByAdress(Student* students, int count, string addressPart);
void findBySubject(Student* students, int count, string subjectName);
void findBySem(Student* students, int count, int semester);

#endif