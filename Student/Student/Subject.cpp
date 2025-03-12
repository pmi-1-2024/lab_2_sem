#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject(string name, unsigned sem, float grade) :
    name(name), sem(sem), grade(grade) {
}

string Subject::getName() { return name; }
unsigned Subject::getSem() { return sem; }
float Subject::getGrade() { return grade; }
void Subject::setName(const string& name) { this->name = name; }
void Subject::setSem(unsigned sem) { this->sem = sem; }
void Subject::setGrade(float grade) { this->grade = grade; }

istream& operator>>(istream& is, Subject& subject) {
    is >> ws;
    getline(is, subject.name);
    is >> subject.sem >> subject.grade;
    return is;
}

ostream& operator<<(ostream& os, const Subject& subject) {
    os << "\t\t\t" << subject.name << ": Семестр = " << subject.sem << ", Оцінка = " << subject.grade << "." << endl;
    return os;
}
