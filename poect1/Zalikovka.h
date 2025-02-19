#ifndef ZALIKOVKA_H
#define ZALIKOVKA_H

#include "Subject.h"

class Zalikovka {
private:
    Subject* subjects;
    int subjectCount;

public:
    Zalikovka(int subjectCount = 0);
    ~Zalikovka();
    void addSubject(const Subject& subject);
    Subject* getSubjects() const;
    int getSubjectCount() const;
};

#endif




