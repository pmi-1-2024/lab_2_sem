#ifndef ZALIKOVKA_H
#define ZALIKOVKA_H
#include <iostream>
#include "Subject.h"
using namespace std;
class Zalikovka {
private:
    int number;
    int subjectCount;
    Subject* subjects;
public:
    Zalikovka(int number = 0, int subjectCount = 0);
    ~Zalikovka();
    friend ostream& operator<<(ostream& os, const Zalikovka& zal);
    friend istream& operator>>(istream& is, Zalikovka& zal);
};

#endif




