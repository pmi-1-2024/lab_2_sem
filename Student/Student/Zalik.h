#ifndef ZALIK_H
#define ZALIK_H

#include "Subject.h"
#include <string>
using namespace std;

class Zalik {
    unsigned id;
    Subject* subjects;
    unsigned subjCount;

public:
    Zalik(unsigned id, unsigned subjCount);
    Zalik(const Zalik& other);
    Zalik& operator=(const Zalik& other);
    ~Zalik();
    void print();
    unsigned getId();
    Subject findSubjectByName(string name);
    Subject findSubjectBySemester(int semester);
    void setSubject(unsigned index, const Subject& subject);
};

#endif
