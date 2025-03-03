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

    Zalikovka(const Zalikovka& other);

    
    Zalikovka& operator=(const Zalikovka& other);

    
    Subject& operator[](int index);
    const Subject& operator[](int index) const;

    
    ~Zalikovka();

    string getId() const;

    void display(ostream& os) const;
    void read(istream& is);

    friend istream& operator>>(istream& is, Zalikovka& z);
    friend ostream& operator<<(ostream& os, const Zalikovka& z);
};
