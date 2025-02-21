#include "Zalik.h"
#include <iostream>
using namespace std;

Zalik::Zalik(unsigned id, unsigned subjCount) :
    id(id), subjCount(subjCount) {
    subjects = new Subject[subjCount];
}

Zalik::Zalik(const Zalik& other) : id(other.id), subjCount(other.subjCount) {
    subjects = new Subject[subjCount];
    for (unsigned i = 0; i < subjCount; ++i) {
        subjects[i] = other.subjects[i];
    }
}

Zalik& Zalik::operator=(const Zalik& other) {
    if (this == &other) return *this;

    delete[] subjects;

    id = other.id;
    subjCount = other.subjCount;
    subjects = new Subject[subjCount];
    for (unsigned i = 0; i < subjCount; ++i) {
        subjects[i] = other.subjects[i];
    }

    return *this;
}

Zalik::~Zalik() {
    delete[] subjects;
}

void Zalik::print() {
    cout << "\tЗаліковка: Номер заліковки = " << id << ", К-сть предметів = " << subjCount << ". | Предмети: " << endl;
    for (unsigned i = 0; i < subjCount; i++) subjects[i].print();
}

unsigned Zalik::getId() { return id; }

Subject Zalik::findSubjectByName(string name) {
    for (unsigned i = 0; i < subjCount; i++) {
        if (subjects[i].getName() == name) {
            return subjects[i];
        }
    }
    return Subject("", 0, 0.0f);
}

Subject Zalik::findSubjectBySemester(int semester) {
    for (unsigned i = 0; i < subjCount; i++) {
        if (subjects[i].getSem() == semester) {
            return subjects[i];
        }
    }
    return Subject("", 0, 0.0f);
}

void Zalik::setSubject(unsigned index, const Subject& subject) {
    if (index < subjCount) {
        subjects[index] = subject;
    }
}
