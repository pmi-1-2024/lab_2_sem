#include "Zalikovka.h"
#include <iostream>

Zalikovka::Zalikovka() : number(""), subjectCount(0) {}

void Zalikovka::input() {
    cout << "Enter zalikovka number: ";
    cin >> number;
    cout << "Enter number of subjects: ";
    cin >> subjectCount;
    for (int i = 0; i < subjectCount; ++i) {
        cout << "Enter details for subject " << i + 1 << ":" << endl;
        subjects[i].input();
    }
}

void Zalikovka::output() const {
    cout << "Zalikovka number: " << number << endl;
    for (int i = 0; i < subjectCount; ++i) {
        subjects[i].output();
    }
}