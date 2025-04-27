#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person() : name("Unknown"), age(0) {}
    Person(string name, int age) : name(name), age(age) {}

    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);
};
