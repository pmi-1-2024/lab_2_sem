#pragma once
#include "Subject.h"

class Zalikovka {
private:
    string id;
    Subject* subjects; 
    int size;
public:
    Zalikovka();
    Zalikovka(string id, int size, Subject* subjects);

    string getId() const;

    void display() const;
    void read(istream& is);
    friend istream& operator>>(istream& is, Zalikovka& z);
};
