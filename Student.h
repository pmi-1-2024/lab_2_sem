#pragma once

#include "Address.h"
#include "Zalikovka.h"
#include <string>
using namespace std;

class Student {
public:
    string name;
    string group;
    Address address;
    Zalikovka zalikovka;

    Student();

    void input();
    void output() const;
};

