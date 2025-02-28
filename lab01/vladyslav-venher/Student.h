#pragma once

#include "Address.h"
#include "Zalikovka.h"

class Student {
public:
    string name;
    Address address;
    string group;
    Zalikovka zalikovka;

    Student();
    void print() const;
};