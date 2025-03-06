#include "Zalikovka.h"
#include <iostream>

using namespace std;

Zalikovka::Zalikovka() : number(0), subjectCount(0), subjects(nullptr) {}

Zalikovka::Zalikovka(int number, int subjectCount)
    : number(number), subjectCount(subjectCount), subjects(nullptr) {
    if (subjectCount > 0) {
        subjects = new Subject[subjectCount];
    }
}

Zalikovka::Zalikovka(const Zalikovka& other)
    : number(other.number), subjectCount(other.subjectCount), subjects(nullptr) {
    if (subjectCount > 0) {
        subjects = new Subject[subjectCount];
        for (int i = 0; i < subjectCount; ++i) {
            subjects[i] = other.subjects[i];
        }
    }
}

Zalikovka& Zalikovka::operator=(const Zalikovka& other) {
    if (this != &other) {
        if (subjects) {
            delete[] subjects;
        }
        number = other.number;
        subjectCount = other.subjectCount;
        subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;
        for (int i = 0; i < subjectCount; ++i) {
            subjects[i] = other.subjects[i];
        }
    }
    return *this;
}

Zalikovka::~Zalikovka() {
    delete[] subjects;
    subjects = nullptr;
}

ostream& operator<<(ostream& os, const Zalikovka& zalikovka) {
    os << "Номер залікової книжки: " << zalikovka.number << "\n";
    if (zalikovka.subjects && zalikovka.subjectCount > 0) {
        os << "Предмети:\n";
        for (int i = 0; i < zalikovka.subjectCount; ++i) {
            os << zalikovka.subjects[i] << "\n";
        }
    }
    else {
        os << "Немає предметів.\n";
    }
    return os;
}

istream& operator>>(istream& is, Zalikovka& zalikovka) {
    is >> zalikovka.number >> zalikovka.subjectCount;
    if (zalikovka.subjects) {
        delete[] zalikovka.subjects;
    }
    zalikovka.subjects = (zalikovka.subjectCount > 0) ? new Subject[zalikovka.subjectCount] : nullptr;
    for (int i = 0; i < zalikovka.subjectCount; ++i) {
        is >> zalikovka.subjects[i];
    }
    return is;
}
