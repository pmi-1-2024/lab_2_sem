#include "Zalikovka.h"
#include <iostream>

Zalikovka::Zalikovka(int subjectCount) : subjectCount(subjectCount) {
    subjects = new Subject[subjectCount];
}

Zalikovka::~Zalikovka() {
    delete[] subjects;
}

void Zalikovka::addSubject(const Subject& subject) {
    
}

Subject* Zalikovka::getSubjects() const {
    return subjects;
}

int Zalikovka::getSubjectCount() const {
    return subjectCount;
}



