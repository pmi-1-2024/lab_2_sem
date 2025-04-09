#pragma once
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    bool operator<(const Person& other) const { return age < other.age;}
};

