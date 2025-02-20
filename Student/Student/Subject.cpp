#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject(string name, unsigned sem, float grade) :
    name(name), sem(sem), grade(grade) {
}

void Subject::print() {
    cout << "\t\t" << name << ": Семестр = " << sem << ", Оцінка = " << grade << "." << endl;
}

string Subject::getName() { return name; }
unsigned Subject::getSem() { return sem; }