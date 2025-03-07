#include "Zalikovka.h"
using namespace std;
Zalikovka::Zalikovka(int number, int subjectCount) : number(number), subjectCount(subjectCount) {
    subjects = new Subject[subjectCount];
}

Zalikovka::~Zalikovka() {
    delete[] subjects;
}

ostream& operator<<(ostream& os, const Zalikovka& zal) {
    os << "Zalikovka No: " << zal.number << "\nSubjects:\n";
    for (int i = 0; i < zal.subjectCount; ++i) {
        os << "  " << zal.subjects[i] << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Zalikovka& zal) {
    is >> zal.number >> zal.subjectCount;
    delete[] zal.subjects;
    zal.subjects = new Subject[zal.subjectCount];
    for (int i = 0; i < zal.subjectCount; ++i) {
        is >> zal.subjects[i];
    }
    return is;
}




