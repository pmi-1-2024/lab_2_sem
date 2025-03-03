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
    cout << "\t\tЗаліковка: Номер заліковки = " << id << ", К-сть предметів = " << subjCount << ". | Предмети: " << endl;
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

istream& operator>>(istream& is, Zalik& zalik) {
    is >> zalik.id >> zalik.subjCount;
    zalik.subjects = new Subject[zalik.subjCount];
    for (unsigned i = 0; i < zalik.subjCount; ++i) {
        is >> ws;
        string name;
        getline(is, name);
        zalik.subjects[i].setName(name);
        unsigned sem;
        float grade;
        is >> sem >> grade;
        zalik.subjects[i].setSem(sem);
        zalik.subjects[i].setGrade(grade);
    }
    return is;
}

ostream& operator<<(ostream& os, const Zalik& zalik) {
    os << zalik.id << " " << zalik.subjCount << endl;
    for (unsigned i = 0; i < zalik.subjCount; ++i) {
        os << zalik.subjects[i].getName() << endl;
        os << zalik.subjects[i].getSem() << " " << zalik.subjects[i].getGrade() << endl;
    }
    return os;
}
