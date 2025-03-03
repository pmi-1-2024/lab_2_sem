#pragma once
#include "Student.h"
#include "Group.h"
#include <iostream>
#include <fstream>
using namespace std;

class Menu {
public:
    void run();

private:
    void loadFromFile(string filename, int& size, Student* students);
    void searchByName(Student* students, int size, string lastName);
    void searchByGroup(Group* groups, int size, string g);
    void searchByZalikovka(Student* students, int size, string recordID);
    void searchByAddress(Student* students, int size, string address);
    void StudentsIntoGroups(Student* students, int studentCount, Group*& groups, int& groupCount);
};
