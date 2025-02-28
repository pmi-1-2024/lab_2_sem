#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka(int number, int subjectCount)
    : number(number), subjectCount(subjectCount), subjects(nullptr) {
    if (subjectCount > 0) {
        subjects = new Subject[subjectCount];
    }
}

Zalikovka::~Zalikovka() {
    delete[] subjects;
    subjects = nullptr;
}

void Zalikovka::output() const {
    cout << "����� ������� ������: " << number << "\n";
    if (subjects && subjectCount > 0) {
        cout << "��������:\n";
        for (int i = 0; i < subjectCount; ++i) {
            subjects[i].output();
        }
    }
    else {
        cout << "���� ��������.\n";
    }
}