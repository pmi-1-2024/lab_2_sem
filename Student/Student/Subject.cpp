#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject(string name, unsigned sem, float grade) :
    name(name), sem(sem), grade(grade) {
}

void Subject::print() {
    cout << "\t\t\t" << name << ": ������� = " << sem << ", ������ = " << grade << "." << endl;
}

string Subject::getName() { return name; }
unsigned Subject::getSem() { return sem; }
float Subject::getGrade() { return grade; }
void Subject::setName(const string& name) { this->name = name; }
void Subject::setSem(unsigned sem) { this->sem = sem; }
void Subject::setGrade(float grade) { this->grade = grade; }
