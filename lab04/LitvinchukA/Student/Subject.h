#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
    string name;
    unsigned sem;
    float grade;

public:
    Subject() : name(""), sem(0), grade(0.0f) {}
    Subject(string name, unsigned sem, float grade);
    string getName();
    unsigned getSem();
    float getGrade();
    void setName(const string& name);
    void setSem(unsigned sem);
    void setGrade(float grade);

    friend istream& operator>>(istream& is, Subject& subject);
    friend ostream& operator<<(ostream& os, const Subject& subject);
};

#endif
