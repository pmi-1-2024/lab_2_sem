#pragma once
#include <iostream>
#include "Subject.h"
using namespace std;

class Zalikovka {
private:
    int number;
    int subjectCount;
    Subject* subjects;
public:
    Zalikovka();
    Zalikovka(int num, int count);
    Zalikovka(const Zalikovka& other);
    Zalikovka& operator=(const Zalikovka& other);
    ~Zalikovka();
    Subject& operator[](int index);
    friend ostream& operator<<(ostream& os, const Zalikovka& z);
    friend istream& operator>>(istream& is, Zalikovka& z);
};